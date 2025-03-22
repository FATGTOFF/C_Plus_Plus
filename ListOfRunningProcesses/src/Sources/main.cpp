#include "Logger.h"
#include <array>
#include <chrono>
#include <exception>
#include <iomanip>
#include <iostream>
#include <Pdh.h>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>
#include <WtsApi32.h>

#pragma comment(lib, "pdh.lib")
#pragma comment(lib, "Wtsapi32.lib")

/*
Per https://learn.microsoft.com/en-us/windows/win32/api/wtsapi32/nf-wtsapi32-wtsenumerateprocessesexw
[in, out] pLevel
A pointer to a DWORD variable that, on input, 
specifies the type of information to return. 
To return an array of WTS_PROCESS_INFO structures, 
specify zero. To return an array of WTS_PROCESS_INFO_EX 
structures, specify one.

If you do not specify a valid value for this parameter, 
on output, WTSEnumerateProcessesEx sets this parameter 
to one and returns an error. Otherwise, on output, 
WTSEnumerateProcessesEx does not change the value 
of this parameter.
*/
enum class returnArrayEnum
{
	WTS_PROCESS_INFO_ENUM,
	WTS_PROCESS_INFO_EXW_ENUM
};

enum class continuousLoopEnum
{
	MULTIPLE_LOOPS,
	SINGLE_LOOP
};

struct tempStruct
{
	LPWSTR pProcessNameTemp;
	DWORD ProcessIdTemp;
	DWORD WorkingSetSizeTemp;
};

constexpr auto keepLooping{ static_cast<int>(continuousLoopEnum::MULTIPLE_LOOPS) };
constexpr bool displayThermalTemp{ true };

void DisplayListOfProcesses(const Logger &log);
void DisplayThermalTemperature(const Logger &log);
int rounds(const double num);
double ConvertKelvinToFahrenheit(const double num);
LONGLONG ConvertBytesToKB(const LONGLONG num);
LONGLONG ConvertKBToMB(const LONGLONG num);
void SortAscendingByPIDNum(const std::vector<WTS_PROCESS_INFO_EXW*> &proc_info_vector);
void SortDescendingByPIDNum(const std::vector<WTS_PROCESS_INFO_EXW*>& proc_info_vector);
void SortAscendByWorkSetSz(const std::vector<WTS_PROCESS_INFO_EXW*>& proc_info_vector);
void SortDescendByWorkSetSz(const std::vector<WTS_PROCESS_INFO_EXW*>& proc_info_vector);
void ClearScreen(short xCoord, short yCoord);

void DisplayListOfProcesses(const Logger& log)
{
	WTS_PROCESS_INFO_EXW* proc_info{nullptr};
	auto pLevel = static_cast<DWORD>(returnArrayEnum::WTS_PROCESS_INFO_EXW_ENUM);
	DWORD pi_count{};

#pragma warning(suppress : 6387 )
	if (!WTSEnumerateProcessesExW(nullptr, &pLevel, WTS_CURRENT_SESSION, reinterpret_cast<LPWSTR*>(&proc_info), &pi_count))
	{
		DWORD err = GetLastError();
		throw std::exception("WTSEnumerateProcessesExW failed. Error code: ", err);
	}

	std::vector<WTS_PROCESS_INFO_EXW*> proc_info_vector{};
	proc_info_vector.reserve(pi_count);

	for (std::size_t i = 0; i < pi_count; ++i) 
	{
		proc_info_vector.push_back(&proc_info[i]);
	}

	SortDescendByWorkSetSz(proc_info_vector);

	for (std::size_t i = 0; i < pi_count; ++i)
	{
		log.consoleOutput_w(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC_MS) << std::left << "PID Name: " << std::setw(50)
			<< proc_info_vector[i]->pProcessName << "PID ID : "
			<< std::setw(9) << proc_info_vector[i]->ProcessId
			<< "Working set size : " << std::setw(8)
			<< ConvertBytesToKB(proc_info_vector[i]->WorkingSetSize) << std::setw(4)
			<< "KB" << std::setw(4) << ConvertKBToMB(proc_info_vector[i]->WorkingSetSize) << std::setw(8)
			<< " MB" << std::endl;

		log.fileOutPut_w(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC) << ','
			<< proc_info_vector[i]->pProcessName << ',' 
		 << proc_info_vector[i]->ProcessId << ','
			<< ConvertBytesToKB(proc_info_vector[i]->WorkingSetSize) << ','
			<< ConvertKBToMB(proc_info_vector[i]->WorkingSetSize) << std::endl;
	}


	proc_info_vector.clear();

	//Free memory
	if (proc_info)
	{
		static_cast<void>(WTSFreeMemoryExW(WTSTypeProcessInfoLevel1, proc_info, pi_count));
		proc_info = nullptr;
	}
}

void DisplayThermalTemperature(const Logger& log)
{
	enum class thermalZoneTempInstances
	{
		TZ00,
		TZ01,
		_TOTAL_
	};

	std::array<PDH_HQUERY, static_cast<int>(thermalZoneTempInstances::_TOTAL_)> tempQuery{};
	std::array<PDH_HCOUNTER, static_cast<int>(thermalZoneTempInstances::_TOTAL_)> tempTotal{};
	std::array<PDH_FMT_COUNTERVALUE, static_cast<int>(thermalZoneTempInstances::_TOTAL_)> tempVal{};

	const std::array<std::wstring, static_cast<int>(thermalZoneTempInstances::_TOTAL_)> commandToPdhAddCounter
	{
		L"\\Thermal Zone Information(\\_TZ.TZ00)\\Temperature",
		L"\\Thermal Zone Information(\\_TZ.TZ01)\\Temperature"
	};

	for (auto whichThermalZone = 0; whichThermalZone < static_cast<int>(thermalZoneTempInstances::_TOTAL_); ++whichThermalZone)
	{
		PdhOpenQuery(nullptr, 0, &tempQuery.at(whichThermalZone));

		PdhAddCounter(tempQuery.at(whichThermalZone), commandToPdhAddCounter.at(whichThermalZone).c_str(), NULL, &tempTotal.at(whichThermalZone));
		static_cast<void>(PdhCollectQueryData(tempQuery.at(whichThermalZone)));
		static_cast<void>(PdhGetFormattedCounterValue(tempTotal.at(whichThermalZone), PDH_FMT_DOUBLE, nullptr, &tempVal.at(whichThermalZone)));
		std::wcout << "PC Thermal Temperature Zone [" << (whichThermalZone + 1) << "]: " << tempVal.at(whichThermalZone).doubleValue << " (K degs) "
			<< std::setw(6) << ConvertKelvinToFahrenheit(tempVal.at(whichThermalZone).doubleValue) << " (F degs)" << std::endl;

		log.fileOutPut_w(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC) << ',' << "PC Thermal Temperature Zone [" << (whichThermalZone + 1) << "]: " << ',' 
			<< tempVal.at(whichThermalZone).doubleValue << " (K degs) " << ',' << ConvertKelvinToFahrenheit(tempVal.at(whichThermalZone).doubleValue) << " (F degs)" << std::endl;

		static_cast<void>(PdhCloseQuery(tempQuery.at(whichThermalZone)));
	}

}

int rounds(const double num)
{
	return static_cast<int>(num + (num < 0 ? -0.5 : +0.5)); // Round to the nearest number.
}

double ConvertKelvinToFahrenheit(const double tempInKelvin)
{
	return (tempInKelvin * (9.0/5.0)) - 459.67;
}

LONGLONG ConvertBytesToKB(const LONGLONG num)
{
	return num / 1024;
}

LONGLONG ConvertKBToMB(const LONGLONG num)
{
	return ConvertBytesToKB(num) / 1024;
}

void SortAscendingByPIDNum(const std::vector<WTS_PROCESS_INFO_EXW*> &proc_info_vector)
{
	tempStruct pTempStruct{};

	for (int i = 0; i < proc_info_vector.size(); ++i)
	{
		for (int j = i + 1; j < proc_info_vector.size(); ++j)
		{
			if (proc_info_vector[j]->ProcessId < proc_info_vector[i]->ProcessId)
			{
				pTempStruct.ProcessIdTemp = proc_info_vector[i]->ProcessId;
				pTempStruct.pProcessNameTemp = proc_info_vector[i]->pProcessName;
				pTempStruct.WorkingSetSizeTemp = proc_info_vector[i]->WorkingSetSize;

				proc_info_vector[i]->ProcessId = proc_info_vector[j]->ProcessId;
				proc_info_vector[i]->pProcessName = proc_info_vector[j]->pProcessName;
				proc_info_vector[i]->WorkingSetSize = proc_info_vector[j]->WorkingSetSize;

				proc_info_vector[j]->ProcessId = pTempStruct.ProcessIdTemp;
				proc_info_vector[j]->pProcessName = pTempStruct.pProcessNameTemp;
				proc_info_vector[j]->WorkingSetSize = pTempStruct.WorkingSetSizeTemp;

			}
		}

	}
}

void SortDescendingByPIDNum(const std::vector<WTS_PROCESS_INFO_EXW*>& proc_info_vector)
{
	tempStruct pTempStruct{};

	for (int i = 0; i < proc_info_vector.size(); ++i)
	{
		for (int j = i + 1; j < proc_info_vector.size(); ++j)
		{
			if (proc_info_vector[j]->ProcessId > proc_info_vector[i]->ProcessId)
			{
				pTempStruct.ProcessIdTemp = proc_info_vector[i]->ProcessId;
				pTempStruct.pProcessNameTemp = proc_info_vector[i]->pProcessName;
				pTempStruct.WorkingSetSizeTemp = proc_info_vector[i]->WorkingSetSize;

				proc_info_vector[i]->ProcessId = proc_info_vector[j]->ProcessId;
				proc_info_vector[i]->pProcessName = proc_info_vector[j]->pProcessName;
				proc_info_vector[i]->WorkingSetSize = proc_info_vector[j]->WorkingSetSize;

				proc_info_vector[j]->ProcessId = pTempStruct.ProcessIdTemp;
				proc_info_vector[j]->pProcessName = pTempStruct.pProcessNameTemp;
				proc_info_vector[j]->WorkingSetSize = pTempStruct.WorkingSetSizeTemp;

			}
		}

	}
}

void SortAscendByWorkSetSz(const std::vector<WTS_PROCESS_INFO_EXW*>& proc_info_vector)
{
	tempStruct pTempStruct{};

	for (int i = 0; i < proc_info_vector.size(); ++i)
	{
		for (int j = i + 1; j < proc_info_vector.size(); ++j)
		{
			if (proc_info_vector[j]->WorkingSetSize < proc_info_vector[i]->WorkingSetSize)
			{
				pTempStruct.ProcessIdTemp = proc_info_vector[i]->ProcessId;
				pTempStruct.pProcessNameTemp = proc_info_vector[i]->pProcessName;
				pTempStruct.WorkingSetSizeTemp = proc_info_vector[i]->WorkingSetSize;

				proc_info_vector[i]->ProcessId = proc_info_vector[j]->ProcessId;
				proc_info_vector[i]->pProcessName = proc_info_vector[j]->pProcessName;
				proc_info_vector[i]->WorkingSetSize = proc_info_vector[j]->WorkingSetSize;

				proc_info_vector[j]->ProcessId = pTempStruct.ProcessIdTemp;
				proc_info_vector[j]->pProcessName = pTempStruct.pProcessNameTemp;
				proc_info_vector[j]->WorkingSetSize = pTempStruct.WorkingSetSizeTemp;

			}
		}

	}
}

void SortDescendByWorkSetSz(const std::vector<WTS_PROCESS_INFO_EXW*>& proc_info_vector)
{
	tempStruct pTempStruct{};

	for (int i = 0; i < proc_info_vector.size(); ++i)
	{
		for (int j = i + 1; j < proc_info_vector.size(); ++j)
		{
			if (proc_info_vector[j]->WorkingSetSize > proc_info_vector[i]->WorkingSetSize)
			{
				pTempStruct.ProcessIdTemp = proc_info_vector[i]->ProcessId;
				pTempStruct.pProcessNameTemp = proc_info_vector[i]->pProcessName;
				pTempStruct.WorkingSetSizeTemp = proc_info_vector[i]->WorkingSetSize;

				proc_info_vector[i]->ProcessId = proc_info_vector[j]->ProcessId;
				proc_info_vector[i]->pProcessName = proc_info_vector[j]->pProcessName;
				proc_info_vector[i]->WorkingSetSize = proc_info_vector[j]->WorkingSetSize;

				proc_info_vector[j]->ProcessId = pTempStruct.ProcessIdTemp;
				proc_info_vector[j]->pProcessName = pTempStruct.pProcessNameTemp;
				proc_info_vector[j]->WorkingSetSize = pTempStruct.WorkingSetSizeTemp;

			}
		}

	}
}

void ClearScreen(short xCoord, short yCoord)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	const COORD  homeCoords{ xCoord, yCoord };

	const HANDLE hStdOut{ GetStdHandle(STD_OUTPUT_HANDLE) };
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	const DWORD cellCount{ static_cast<DWORD>(csbi.dwSize.X * csbi.dwSize.Y) };

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		static_cast<TCHAR>(' '),
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	static_cast<void>(SetConsoleCursorPosition(hStdOut, homeCoords));
}

int main() 
{
	Logger log("ListOfRunningProcesses_log.csv");
	Logger logTemperature("ComputerTemperature_log.csv");

	log.fileOutPut_w() << "Date/Time" << ','
		<< "PID Name" << ',' << "PID ID" << ',' << "Working set size (KB)"
	    << ',' << "Working set size (MB)" << std::endl;

	if (keepLooping == static_cast<int>(continuousLoopEnum::MULTIPLE_LOOPS))
	{
		while (true)
		{
			DisplayListOfProcesses(log);

			if (displayThermalTemp)
			{
				DisplayThermalTemperature(logTemperature);
			}

			std::this_thread::sleep_for(std::chrono::seconds(1));
			ClearScreen(0, 0);
		}
	}
	else
	{
		DisplayListOfProcesses(log);

		if (displayThermalTemp)
		{
			DisplayThermalTemperature(logTemperature);
		}
	}

}
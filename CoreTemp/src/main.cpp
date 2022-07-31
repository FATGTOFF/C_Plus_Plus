// A simple program that uses CoreTemp DLL to pull the computer data

#include <windows.h> 
#include <cstdio>
#include <tlhelp32.h>
#include <tchar.h>
#include <thread>
#include <chrono>

constexpr auto UNKNOWN_EXCEPTION = 0x20000000;

typedef struct core_temp_shared_data
{
    unsigned int	uiLoad[256];
    unsigned int	uiTjMax[128];
    unsigned int	uiCoreCnt;
    unsigned int	uiCPUCnt;
    float			fTemp[256];
    float			fVID;
    float			fCPUSpeed;
    float			fFSBSpeed;
    float			fMultipier;
    char			sCPUName[100];
    unsigned char	ucFahrenheit;
    unsigned char	ucDeltaToTjMax;
}CORE_TEMP_SHARED_DATA, *PCORE_TEMP_SHARED_DATA, **PPCORE_TEMP_SHARED_DATA;

typedef bool (WINAPI* myGetCoreTempInfo)(CORE_TEMP_SHARED_DATA* pData);

bool IsProcessRunning(const TCHAR* const executableName);

int main()
{
	/*It needs Core Temp running since it pulls the data from the shared memory*/
	if (IsProcessRunning(TEXT("Core Temp.exe")))
	{
		printf("Core Temp running.\n");
	}
	else
	{
		printf("Starting Core Temp.");

		STARTUPINFO info;
		PROCESS_INFORMATION processInfo;
		ZeroMemory(&info, sizeof(info));

		LPCWSTR path = (TEXT(".\\CoreTempSDK\\Core_Temp\\run.bat"));
		if (CreateProcess(path, NULL, NULL, NULL, NULL, 0, NULL, NULL, &info, &processInfo))
		{
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);
		}
		else
		{
			printf("CreateProcess failed (%d).\n", GetLastError());
			return GetLastError();
		}

		for (int count = 3; count > 0; --count)
		{
			printf(".");
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		printf("\n");
	}


	myGetCoreTempInfo GetCoreTempInfo;
	HMODULE hCT;
	ULONG index;
	DWORD lastError = 0;
	wchar_t errMsg[100];
	char tempType;
	memset(errMsg, 0, sizeof(errMsg));
	CORE_TEMP_SHARED_DATA* CoreTempData = new CORE_TEMP_SHARED_DATA;
	memset(CoreTempData, 0, sizeof(CORE_TEMP_SHARED_DATA));

	// Get a handle to the DLL module.
	hCT = LoadLibrary(TEXT(".\\CoreTempSDK\\Shared_Memory\\GetCoreTempInfo.dll"));
	// If the handle is valid, try to get the function address.
	if (hCT)
	{
		//Get the address of the function.
		GetCoreTempInfo = (myGetCoreTempInfo)GetProcAddress(hCT, "fnGetCoreTempInfoAlt");
		if (GetCoreTempInfo)
		{
			//Call the function, if it returns true continue to print the info.
			if (GetCoreTempInfo(CoreTempData))
			{
				tempType = CoreTempData->ucFahrenheit ? 'F' : 'C';
				//Now print the output.
				printf("CPU Name: %s\n", CoreTempData->sCPUName);
				printf("CPU Speed: %.2fMHz (%.2f x %.2f)\n",
					CoreTempData->fCPUSpeed, CoreTempData->fFSBSpeed, CoreTempData->fMultipier);
				printf("CPU VID: %.4fv\n", CoreTempData->fVID);
				printf("Physical CPUs: %d\n", CoreTempData->uiCPUCnt);
				printf("Cores per CPU: %d\n", CoreTempData->uiCoreCnt);
				for (UINT i = 0; i < CoreTempData->uiCPUCnt; i++)
				{
					printf("CPU #%d\n", i);
					printf("Tj.Max: %d%c\n", CoreTempData->uiTjMax[i], tempType);
					for (UINT g = 0; g < CoreTempData->uiCoreCnt; g++)
					{
						index = g + (i * CoreTempData->uiCoreCnt);
						if (CoreTempData->ucDeltaToTjMax)
						{
							printf("Core #%d: %.2f%c to TjMax, %d%% Load\n",
								index, CoreTempData->fTemp[index], tempType, CoreTempData->uiLoad[index]);
						}
						else
						{
							printf("Core #%d: %.2f%c, %d%% Load\n",
								index, CoreTempData->fTemp[index], tempType, CoreTempData->uiLoad[index]);
						}
					}
				}
			}
			else
			{
				//Display DLL related errors.
				lastError = GetLastError();
				printf("Error: Core Temp's shared memory could not be read.\n");
				printf("Error number: %d\n", GetLastError());
				if ((lastError & UNKNOWN_EXCEPTION) > 0)
				{
					printf("Error description: Unknown error occured while copying shared memory.\n");
				}
				else
				{
					FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
						NULL, lastError, 0, errMsg, 100, NULL);
					wprintf(TEXT("Error description: %s\n"), errMsg);
				}
			}
		}
		else
		{
			printf("Error: The function \"fnGetCoreTempInfo\" in \"GetCoreTempInfo.dll\" could not be found.");
		}
		FreeLibrary(hCT);
		hCT = NULL;
	}
	else
	{
		printf("Error: \"GetCoreTempInfo.dll\" could not be loaded.");
	}

	delete CoreTempData;


}

bool IsProcessRunning(const TCHAR* const executableName) 
{
	PROCESSENTRY32 entry{};
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (!Process32First(snapshot, &entry)) {
		CloseHandle(snapshot);
		return false;
	}

	do {
		if (!_tcsicmp(entry.szExeFile, executableName)) {
			CloseHandle(snapshot);
			return true;
		}
	} while (Process32Next(snapshot, &entry));

	CloseHandle(snapshot);
	return false;
}

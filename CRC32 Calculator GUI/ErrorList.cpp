#include "pch.h"
#include "ErrorList.h"

#if (DEBUG_ERROR)
ErrorList::ErrorList()
{
	for (auto iter{ errorMessageList.begin() };
		iter != errorMessageList.end();
		++iter)
	{
		std::cout << '\t' << iter->first << '\t' << iter->second << '\n';
	}
}
#endif // DEBUG

int ErrorList::getErrorNumber() const noexcept
{
	return errorNumber;
}

std::string ErrorList::getErrorMessage(const int errNum) const
{
	const auto findErrorNumber = errorMessageList.find(errNum);

	if (errorMessageList.end() != findErrorNumber)
	{
		errorMessage = errorMessageList.at(errNum);
	}
	else
	{
		errorMessage = "Unknown Error";
	}

	return errorMessage;
}

std::wstring ErrorList::getErrorMessage_w(const int errNum) const
{
	const auto findErrorNumber = errorMessageList.find(errNum);

	if (errorMessageList.end() != findErrorNumber)
	{
		errorMessage_w = errorMessageList_w.at(errNum);
	}
	else
	{
		errorMessage_w = L"Unknown Error";
	}

	return errorMessage_w;
}

void ErrorList::printErrorMessage(const std::string& errTypeMsg, const int errNum) const
{
	std::fstream outErrorFile{};
	outErrorFile.open("errorLog.out", std::ios::app);

	std::cerr << errTypeMsg <<  errNum << " - " << getErrorMessage(errNum) << std::endl;
	outErrorFile << errTypeMsg << errNum << " - " << getErrorMessage(errNum) << std::endl;
	outErrorFile.close();

}

void ErrorList::printErrorMessage_w(const std::wstring& errTypeMsg, const int errNum) const
{
	std::wofstream outErrorFile{};
	outErrorFile.open("errorLog.out", std::ios::app);

	std::wcerr << errTypeMsg << errNum << " - " << getErrorMessage_w(errNum) << std::endl;
	outErrorFile << errTypeMsg << errNum << " - " << getErrorMessage_w(errNum) << std::endl;
	outErrorFile.close();
}

void ErrorList::printErrorMessage(const int errNum) const
{
   std::fstream outErrorFile{};
   outErrorFile.open("errorLog.out", std::ios::app);

   std::cerr << errNum << " - " << getErrorMessage(errNum) << std::endl;
   outErrorFile << errNum << " - " << getErrorMessage(errNum) << std::endl;
   outErrorFile.close();
}

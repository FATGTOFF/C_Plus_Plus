#include "ErrorList.h"

#if (DEBUG)
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

void ErrorList::setErrorNumber(const int errNum) noexcept
{
	errorNumber = errNum;
}

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

void ErrorList::printErrorMessage(const int errNum) const
{

	std::fstream outErrorFile{};
	outErrorFile.open("errorLog.out", std::ios::out);

	std::cerr << errNum << "\t" << getErrorMessage(errNum) << std::endl;
	outErrorFile << errNum << "\t" << getErrorMessage(errNum) << std::endl;
	outErrorFile.close();

}

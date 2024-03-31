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

void ErrorList::setErrorNumber(const int errNum)
{
	errorNumber = errNum;
}

int ErrorList::getErrorNumber() const
{
	return errorNumber;
}

std::string ErrorList::getErrorMessage()
{
	return errorMessageList[errorNumber];
}

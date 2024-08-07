#include "GetLocalTimeException.h"


GetLocalTimeException::GetLocalTimeException(const int errNum) : GetTimeExceptionBase(errNum), errorNumber(errNum)
{
}

void GetLocalTimeException::setErrorNumber(const int errNum) noexcept
{
   errorNumber = errNum;
}

int GetLocalTimeException::getTimeException() const noexcept
{
	return errorNumber;
}

std::string GetLocalTimeException::what() const 
{
   return exceptionTypeMessage;
}

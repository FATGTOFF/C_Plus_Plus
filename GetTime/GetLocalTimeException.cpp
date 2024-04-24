#include "GetLocalTimeException.h"


GetLocalTimeException::GetLocalTimeException(const int errNum) noexcept : GetTimeExceptionBase(errNum), errorNumber(errNum)
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

std::string GetLocalTimeException::what() const noexcept
{
   return exceptionTypeMessage;
}

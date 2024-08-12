#include "pch.h"
#include "GetFTimeException.h"


GetFTimeException::GetFTimeException(const int errNum) : GetTimeExceptionBase(errNum), errorNumber(errNum)
{
}

void GetFTimeException::setErrorNumber(const int errNum) noexcept
{
   errorNumber = errNum;
}

int GetFTimeException::getTimeException() const noexcept
{
   return errorNumber;
}

std::string GetFTimeException::what() const
{
   return exceptionTypeMessage;
}

std::wstring GetFTimeException::what_w() const
{
   return exceptionTypeMessage_w;
}

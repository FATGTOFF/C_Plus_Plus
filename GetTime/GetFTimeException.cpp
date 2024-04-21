#include "GetFTimeException.h"


GetFTimeException::GetFTimeException(const int errNum) noexcept : GetTimeExceptionBase(errNum), errorNumber(errNum)
{
}

int GetFTimeException::getTimeException() noexcept
{
	return errorNumber;
}

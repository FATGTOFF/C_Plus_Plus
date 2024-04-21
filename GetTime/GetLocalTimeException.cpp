#include "GetLocalTimeException.h"


GetLocalTimeException::GetLocalTimeException(const int errNum) noexcept : GetTimeExceptionBase(errNum), errorNumber(errNum)
{
}

int GetLocalTimeException::getTimeException() noexcept
{
	return errorNumber;
}

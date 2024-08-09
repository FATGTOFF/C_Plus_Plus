#include "pch.h"
#include "GetTimeExceptionBase.h"

GetTimeExceptionBase::GetTimeExceptionBase(const int errNum) noexcept : errorNumber(errNum)
{
}

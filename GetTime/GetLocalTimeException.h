#ifndef _GETLOCALTIMEEXCEPTION_
#define _GETLOCALTIMEEXCEPTION_
#include "GetTimeExceptionBase.h"

class GetLocalTimeException : public GetTimeExceptionBase
{
private:
	int errorNumber{};

public:
	explicit GetLocalTimeException(const int errNum) noexcept;
	explicit GetLocalTimeException(const GetLocalTimeException& copyConstructorMember) = default;
	GetLocalTimeException(GetLocalTimeException&& moveConstructorMember) = default;
	GetLocalTimeException& operator=(const GetLocalTimeException& copyAssignmentMember) = default;
	GetLocalTimeException& operator=(GetLocalTimeException&& moveAssignmentMember) = default;
	~GetLocalTimeException() override = default;

	int getTimeException() noexcept override;
};

#endif // !_GETLOCALTIMEEXCEPTION_

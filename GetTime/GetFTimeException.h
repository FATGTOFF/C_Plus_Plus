#ifndef _GETFTIMEEXCEPTION_
#define _GETFTIMEEXCEPTION_
#include "GetTimeExceptionBase.h"

class GetFTimeException : public GetTimeExceptionBase
{
private:
	int errorNumber{};

public:
	explicit GetFTimeException(const int errNum) noexcept;
	explicit GetFTimeException(const GetFTimeException& copyConstructorMember) = default;
	GetFTimeException(GetFTimeException&& moveConstructorMember) = default;
	GetFTimeException& operator=(const GetFTimeException& copyAssignmentMember) = default;
	GetFTimeException& operator=(GetFTimeException&& moveAssignmentMember) = default;
	~GetFTimeException() override = default;

	int getTimeException() noexcept override;
};

#endif // !_GETTIMEEXCEPTION_

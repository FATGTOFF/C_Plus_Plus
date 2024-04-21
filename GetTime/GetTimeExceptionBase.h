#ifndef _GETTIMEEXCEPTIONBASE_
#define _GETTIMEEXCEPTIONBASE_

class GetTimeExceptionBase
{
private:
	int errorNumber;

public:
	GetTimeExceptionBase() = default;
	explicit GetTimeExceptionBase(const int errNum) noexcept;
	explicit GetTimeExceptionBase(const GetTimeExceptionBase& copyConstructorMember) = default;
	explicit GetTimeExceptionBase(GetTimeExceptionBase&& moveConstructorMember) = default;
	GetTimeExceptionBase& operator=(const GetTimeExceptionBase& copyAssignmentMember) = default;
	GetTimeExceptionBase& operator=(GetTimeExceptionBase&& moveAssignmentMember) = default;
	virtual ~GetTimeExceptionBase() = default;

	virtual int getTimeException() = 0;
};

#endif // !_GETTIMEEXCEPTIONBASE_


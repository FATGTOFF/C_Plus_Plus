#ifndef _GETFTIMEEXCEPTION_
#define _GETFTIMEEXCEPTION_
#include <string>
#include "GetTimeExceptionBase.h"

class GetFTimeException : public GetTimeExceptionBase
{
private:
	int errorNumber{};
   const std::string exceptionTypeMessage{ "F Time Exception: " };

public:
   explicit GetFTimeException() = default;
	explicit GetFTimeException(const int errNum) noexcept;
	explicit GetFTimeException(const GetFTimeException& copyConstructorMember) = default;
	GetFTimeException(GetFTimeException&& moveConstructorMember) = default;
	GetFTimeException& operator=(const GetFTimeException& copyAssignmentMember) = default;
	GetFTimeException& operator=(GetFTimeException&& moveAssignmentMember) = default;
	~GetFTimeException() override = default;

   void setErrorNumber(const int errNum) noexcept override;
	int getTimeException() const noexcept override;
   std::string what() const noexcept override;
};

#endif // !_GETTIMEEXCEPTION_

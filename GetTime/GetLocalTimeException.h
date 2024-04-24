#ifndef _GETLOCALTIMEEXCEPTION_
#define _GETLOCALTIMEEXCEPTION_
#include <string>
#include "GetTimeExceptionBase.h"

class GetLocalTimeException : public GetTimeExceptionBase
{
private:
	int errorNumber{};
   const std::string exceptionTypeMessage{ "Local Time Exception: " };

public:
   explicit GetLocalTimeException() = default;
	explicit GetLocalTimeException(const int errNum) noexcept;
	explicit GetLocalTimeException(const GetLocalTimeException& copyConstructorMember) = default;
	GetLocalTimeException(GetLocalTimeException&& moveConstructorMember) = default;
	GetLocalTimeException& operator=(const GetLocalTimeException& copyAssignmentMember) = default;
	GetLocalTimeException& operator=(GetLocalTimeException&& moveAssignmentMember) = default;
	~GetLocalTimeException() override = default;

   void setErrorNumber(const int errNum) noexcept override;
	int getTimeException() const noexcept override;
   std::string what() const noexcept override;
};

#endif // !_GETLOCALTIMEEXCEPTION_

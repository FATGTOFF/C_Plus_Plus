#ifndef _GETFTIMEEXCEPTION_
#define _GETFTIMEEXCEPTION_
#include <string>
#include "GetTimeExceptionBase.h"

class GetFTimeException : public GetTimeExceptionBase
{
private:
   int errorNumber{};
   const std::string exceptionTypeMessage{ "F Time Exception: " };
   const std::wstring exceptionTypeMessage_w{ L"F Time Exception: " };

public:
   explicit GetFTimeException() = default;
   explicit GetFTimeException(const int errNum);
   explicit GetFTimeException(const GetFTimeException& copyConstructorMember) = default;
   GetFTimeException(GetFTimeException&& moveConstructorMember) = default;
   ~GetFTimeException() override = default;

   void setErrorNumber(const int errNum) noexcept override;
   int getTimeException() const noexcept override;
   std::string what() const override;
   std::wstring what_w() const override;
};

#endif // !_GETTIMEEXCEPTION_

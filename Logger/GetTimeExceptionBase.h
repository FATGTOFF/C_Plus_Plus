#ifndef _GETTIMEEXCEPTIONBASE_
#define _GETTIMEEXCEPTIONBASE_
#include <string>

class GetTimeExceptionBase
{
private:
   int errorNumber{};

public:
   explicit GetTimeExceptionBase() = default;
   explicit GetTimeExceptionBase(const int errNum) noexcept;
   explicit GetTimeExceptionBase(const GetTimeExceptionBase& copyConstructorMember) = default;
   explicit GetTimeExceptionBase(GetTimeExceptionBase&& moveConstructorMember) = default;
   GetTimeExceptionBase& operator=(const GetTimeExceptionBase& copyAssignmentMember) = default;
   GetTimeExceptionBase& operator=(GetTimeExceptionBase&& moveAssignmentMember) = default;
   virtual ~GetTimeExceptionBase() = default;

   virtual void setErrorNumber(const int errNum) = 0;
   virtual int getTimeException() const = 0;
   virtual std::string what() const = 0;
   virtual std::wstring what_w() const = 0;
};

#endif // !_GETTIMEEXCEPTIONBASE_


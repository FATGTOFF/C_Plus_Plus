#ifndef _DATETIME_
#define _DATETIME_

#include <iostream>
#include <ctime>  
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <sys/timeb.h> // struct _timeb
#include <memory>
#include <array>
#include "ErrorList.h"
#include "GetTimeExceptionBase.h"
#include "GetFTimeException.h"
#include "GetLocalTimeException.h"

class DateTime : public ErrorList
{
private:

   enum class Month
   {
       JAN, FEB, MAR, APR, MAY, JUN,
       JUL, AUG, SEP, OCT, NOV, DEC
   };

   const std::map<const Month, const std::string> listOfMonths
   {
      {Month::JAN, "Jan"},
      {Month::FEB, "Feb"},
      {Month::MAR, "Mar"},
      {Month::APR, "Apr"},
      {Month::MAY, "May"},
      {Month::JUN, "Jun"},
      {Month::JUL, "Jul"},
      {Month::AUG, "Aug"},
      {Month::SEP, "Sep"},
      {Month::OCT, "Oct"},
      {Month::NOV, "Nov"},
      {Month::DEC, "Dec"},
   };
   
   const std::map<const Month, const std::wstring> listOfMonths_w
   {
      {Month::JAN, L"Jan"},
      {Month::FEB, L"Feb"},
      {Month::MAR, L"Mar"},
      {Month::APR, L"Apr"},
      {Month::MAY, L"May"},
      {Month::JUN, L"Jun"},
      {Month::JUL, L"Jul"},
      {Month::AUG, L"Aug"},
      {Month::SEP, L"Sep"},
      {Month::OCT, L"Oct"},
      {Month::NOV, L"Nov"},
      {Month::DEC, L"Dec"},
   };

    enum class TypesOfTimeException : int
    {
       FTimeException,
       LocalTimeException
    };

    std::array<std::unique_ptr<GetTimeExceptionBase>, 2> exceptionsTypes
    {
       std::make_unique<GetFTimeException>(),
       std::make_unique<GetLocalTimeException>()
    };

    long long aclock{};
    struct _timeb tstruct{};
    struct tm newtime{};
    mutable std::ostringstream pBuffer{};
    mutable std::wostringstream pBuffer_w{};
    std::string getMonth(const Month) const;
    std::wstring getMonth_w(const Month) const;
    void clearPBuffer() const;
    void clearPBuffer_w() const;

public:

// Supress the warning on Time default constructor.
// warning C26455: Default constructor may not throw. 
// Declare it 'noexcept' (f.6).
#pragma warning( disable : 26455)
// Supress the warning on Time default constructor.
// warning C26823: Dereferencing a possibly null pointer 
// (lifetime.1).
#pragma warning( disable : 26823)
   DateTime();

   std::string getDayMonthYrHrMinSecMs() const;
   std::wstring getDayMonthYrHrMinSecMs_w() const;
   std::string getHrMinSecMs() const;
   std::wstring getHrMinSecMs_w() const;
   std::string getHrMinSecs() const;
   std::wstring getHrMinSecs_w() const;
   std::string getHrMins() const;
   std::wstring getHrMins_w() const;
   std::string getDay() const;
   std::wstring getDay_w() const;
   std::string getMonth() const;
   std::wstring getMonth_w() const;
   std::string getYear() const;
   std::wstring getYear_w() const;
   std::string getHrs() const;
   std::wstring getHrs_w() const;
   std::string getMins() const;
   std::wstring getMins_w() const;
   std::string getSecs() const;
   std::wstring getSecs_w() const;
   std::string getMills() const;
   std::wstring getMills_w() const;

};

#endif

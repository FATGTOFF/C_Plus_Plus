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
    std::string getMonth(const Month) const;
    void clearPBuffer() const;

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
    std::string getHrMinSecMs() const;
    std::string getHrMinSecs() const;
    std::string getHrMins() const;
    std::string getDay() const;
    std::string getMonth() const;
    std::string getYear() const;
    std::string getHrs() const;
    std::string getMins() const;
    std::string getSecs() const;
    std::string getMills() const;

};

#endif

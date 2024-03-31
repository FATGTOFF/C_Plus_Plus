#ifndef _TIME_
#define _TIME_

#include <iostream>
#include <ctime>  
#include <iomanip>
#include <sstream>
#include <string>
#include <cerrno>
#include <map>
#include <sys/timeb.h>
#include "ErrorList.h"

class Time
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

    long long aclock{};
    struct _timeb tstruct{};
    struct tm newtime{};
    std::ostringstream pBuffer{};
    std::string getMonth(const Month) const;
    void clearPBuffer();

public:
    Time();
    ~Time() = default;
    std::string getDayMonthYrHrMinSecMs();
    std::string getHrMinSecMs();
    std::string getHrMinSecs();
    std::string getHrMins();
    std::string getDay();
    std::string getMonth();
    std::string getYear();
    std::string getHrs();
    std::string getMins();
    std::string getSecs();
    std::string getMills();
};

#endif

#ifndef _TIME_
#define _TIME_

#include <iostream>
#include <ctime>  
#include <iomanip>
#include <sstream>
#include <string>
#include <map>
#include <fstream>
#include <sys/timeb.h> // struct _timeb
#include "ErrorList.h"

class Time : public ErrorList
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
    mutable std::ostringstream pBuffer{};
    std::string getMonth(const Month) const;
    void clearPBuffer() const;
    void printErrorMessage(const int errNum) const;

public:
    Time();
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

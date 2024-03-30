#ifndef _TIME_
#define _TIME_

#include <ctime>  
#include <iomanip>
#include <sstream>
#include <string>
#include <sys/timeb.h>

class Time
{
private:

    enum class Month
    {
        JAN, FEB, MAR, APR, MAY, JUN,
        JUL, AUG, SEP, OCT, NOV, DEC
    };

    long long aclock{};
    struct _timeb tstruct{};
    struct tm newtime{};
    std::ostringstream pBuffer{};
    std::string getMonth(const Month) const;
    void clearPBuffer();

public:
    Time();
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

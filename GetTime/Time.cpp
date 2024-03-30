#include "Time.h"

std::string Time::getMonth(const Month month) const
{
    switch (month)
    {
        case Month::JAN:
            return "Jan";
        break;

        case Month::FEB:
            return "Feb";
        break;

        case Month::MAR:
            return "Mar";
        break;

        case Month::APR:
            return "Apr";
        break;

        case Month::MAY:
            return "May";
        break;

        case Month::JUN:
            return "Jun";
        break;

        case Month::JUL:
            return "Jul";
        break;

        case Month::AUG:
            return "Aug";
        break;

        case Month::SEP:
            return "Sep";
        break;

        case Month::OCT:
            return "Oct";
        break;

        case Month::NOV:
            return "Nov";
        break;

        case Month::DEC:
            return "Dec";
        break;

    }

    return "Error";
}

void Time::clearPBuffer()
{
    pBuffer.str("");
    pBuffer.clear();
}

Time::Time()
{
    // Set time zone from TZ environment variable. If TZ is not set,
    // the operating system is queried to obtain the default value
    // for the variable.
    _tzset();

    _time64(&aclock);
    _ftime64_s(&tstruct);
    _localtime64_s(&newtime, &aclock);

}

std::string Time::getDayMonthYrHrMinSecMs()
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_mday << ' '
        << std::setw(2) << std::setfill('0') << getMonth(static_cast<Month>(newtime.tm_mon)) << ' '
        << std::setw(2) << std::setfill('0') << (newtime.tm_year - 100) << ' '
        << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec << ':'
        << std::setw(4) << std::setfill('0') << tstruct.millitm;

    return pBuffer.str();
}

std::string Time::getHrMinSecMs()
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec << ':'
        << std::setw(4) << std::setfill('0') << tstruct.millitm;

    return pBuffer.str();
}

std::string Time::getHrMinSecs()
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec;

    return pBuffer.str();
}

std::string Time::getHrMins()
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min;

    return pBuffer.str();
}

std::string Time::getDay()
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_mday;

    return pBuffer.str();
}

std::string Time::getMonth()
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        getMonth(static_cast<Month>(newtime.tm_mon));

    return pBuffer.str();
}

std::string Time::getYear()
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        (newtime.tm_year - 100);

    return pBuffer.str();
}

std::string Time::getHrs()
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_hour;

    return pBuffer.str();
}

std::string Time::getMins()
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_min;

    return pBuffer.str();
}

std::string Time::getSecs()
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_sec;

    return pBuffer.str();
}

std::string Time::getMills()
{
    clearPBuffer();

    pBuffer << std::setw(4) <<
        std::setfill('0') <<
        tstruct.millitm;

    return pBuffer.str();
}

#include "Time.h"

std::string Time::getMonth(const Month month) const
{
    return listOfMonths.at(month);
}

void Time::clearPBuffer() const
{
    pBuffer.str("");
    pBuffer.clear();
}

[[noreturn]] void Time::printErrorMessage(const int errNum) const
{
    std::fstream outErrorFile{};
    outErrorFile.open("errorLog.out", std::ios::out);

    std::cerr << errNum << "\t" << getErrorMessage(errNum) << std::endl;
    outErrorFile << errNum << "\t" << getErrorMessage(errNum) << std::endl;
    outErrorFile.close();
    exit(errNum);
}

Time::Time() : ErrorList()
{
    // Set time zone from TZ environment variable. If TZ is not set,
    // the operating system is queried to obtain the default value
    // for the variable.
    _tzset();

    static_cast<void>(_time64(&aclock));

    setErrorNumber(_ftime64_s(&tstruct));
    if (0 != getErrorNumber())
    {
        printErrorMessage(getErrorNumber());
    }
   
    setErrorNumber(_localtime64_s(&newtime, &aclock));
    if (0 != getErrorNumber())
    {
        printErrorMessage(getErrorNumber());
    }


}

std::string Time::getDayMonthYrHrMinSecMs() const
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

std::string Time::getHrMinSecMs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec << ':'
        << std::setw(4) << std::setfill('0') << tstruct.millitm;

    return pBuffer.str();
}

std::string Time::getHrMinSecs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec;

    return pBuffer.str();
}

std::string Time::getHrMins() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min;

    return pBuffer.str();
}

std::string Time::getDay() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_mday;

    return pBuffer.str();
}

std::string Time::getMonth() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        getMonth(static_cast<Month>(newtime.tm_mon));

    return pBuffer.str();
}

std::string Time::getYear() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        (newtime.tm_year - 100);

    return pBuffer.str();
}

std::string Time::getHrs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_hour;

    return pBuffer.str();
}

std::string Time::getMins() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_min;

    return pBuffer.str();
}

std::string Time::getSecs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_sec;

    return pBuffer.str();
}

std::string Time::getMills() const
{
    clearPBuffer();

    pBuffer << std::setw(4) <<
        std::setfill('0') <<
        tstruct.millitm;

    return pBuffer.str();
}

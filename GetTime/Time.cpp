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

Time::Time() : ErrorList()
{

    // Set time zone from TZ environment variable. If TZ is not set,
    // the operating system is queried to obtain the default value
    // for the variable.
    _tzset();

    static_cast<void>(_time64(&aclock));
    try
    {
        exceptionsTypes[static_cast<int>(TypesOfTimeException::FTimeException)]->setErrorNumber(_ftime64_s(&tstruct));
        if (0 != exceptionsTypes[static_cast<int>(TypesOfTimeException::FTimeException)]->getTimeException())
        {
            throw GetFTimeException(exceptionsTypes[static_cast<int>(TypesOfTimeException::FTimeException)]->getTimeException());
        }

        exceptionsTypes[static_cast<int>(TypesOfTimeException::LocalTimeException)]->setErrorNumber(_localtime64_s(&newtime, &aclock));
        if (0 != exceptionsTypes[static_cast<int>(TypesOfTimeException::LocalTimeException)]->getTimeException())
        {

           throw GetLocalTimeException(exceptionsTypes[static_cast<int>(TypesOfTimeException::LocalTimeException)]->getTimeException());
        }
    }
    catch (const GetFTimeException&)
    {
        printErrorMessage(exceptionsTypes[static_cast<int>(TypesOfTimeException::FTimeException)]->what(), 
           exceptionsTypes[static_cast<int>(TypesOfTimeException::FTimeException)]->getTimeException());

        exit(exceptionsTypes[static_cast<int>(TypesOfTimeException::FTimeException)]->getTimeException());
    }
    catch (const GetLocalTimeException&)
    {

       printErrorMessage(exceptionsTypes[static_cast<int>(TypesOfTimeException::LocalTimeException)]->what(), 
          exceptionsTypes[static_cast<int>(TypesOfTimeException::LocalTimeException)]->getTimeException());

       exit(exceptionsTypes[static_cast<int>(TypesOfTimeException::LocalTimeException)]->getTimeException());
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

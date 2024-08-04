#include "DateTime.h"

std::string DateTime::getMonth(const Month month) const
{
    return listOfMonths.at(month);
}

void DateTime::clearPBuffer() const
{
    pBuffer.str("");
    pBuffer.clear();
}

DateTime::DateTime() : ErrorList()
{

    // Set time zone from TZ environment variable. If TZ is not set,
    // the operating system is queried to obtain the default value
    // for the variable.
    _tzset();

   static_cast<void>(_time64(&aclock));

    exceptionsTypes.at(static_cast<int>(TypesOfTimeException::FTimeException))->setErrorNumber(_ftime64_s(&tstruct));
    if (0 != exceptionsTypes.at(static_cast<int>(TypesOfTimeException::FTimeException))->getTimeException())
    {
        ErrorList errorList{};
        errorList.printErrorMessage(exceptionsTypes.at(static_cast<int>(TypesOfTimeException::FTimeException))->what(),
            exceptionsTypes.at(static_cast<int>(TypesOfTimeException::FTimeException))->getTimeException());
        throw GetFTimeException(exceptionsTypes.at(static_cast<int>(TypesOfTimeException::FTimeException))->getTimeException());
    }

    exceptionsTypes.at(static_cast<int>(TypesOfTimeException::LocalTimeException))->setErrorNumber(_localtime64_s(&newtime, &aclock));
    if (0 != exceptionsTypes.at(static_cast<int>(TypesOfTimeException::LocalTimeException))->getTimeException())
    {
        ErrorList errorList{};
        errorList.printErrorMessage(exceptionsTypes.at(static_cast<int>(TypesOfTimeException::LocalTimeException))->what(),
            exceptionsTypes.at(static_cast<int>(TypesOfTimeException::LocalTimeException))->getTimeException());
        throw GetLocalTimeException(exceptionsTypes.at(static_cast<int>(TypesOfTimeException::LocalTimeException))->getTimeException());

    }

}

std::string DateTime::getDayMonthYrHrMinSecMs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_mday << ' '
        << std::setw(2) << std::setfill('0') << getMonth(static_cast<Month>(newtime.tm_mon)) << ' '
        << std::setw(2) << std::setfill('0') << (newtime.tm_year - 100) << ' '
        << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec << ':'
        << std::setw(4) << std::setfill('0') << tstruct.millitm << " ";


    return pBuffer.str();
}

std::string DateTime::getHrMinSecMs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec << ':'
        << std::setw(4) << std::setfill('0') << tstruct.millitm << " ";

    return pBuffer.str();
}

std::string DateTime::getHrMinSecs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_sec << " ";

    return pBuffer.str();
}

std::string DateTime::getHrMins() const
{
    clearPBuffer();

    pBuffer << std::setw(2) << std::setfill('0') << newtime.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << newtime.tm_min << " ";

    return pBuffer.str();
}

std::string DateTime::getDay() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_mday << " ";

    return pBuffer.str();
}

std::string DateTime::getMonth() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        getMonth(static_cast<Month>(newtime.tm_mon)) << " ";

    return pBuffer.str();
}

std::string DateTime::getYear() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        (newtime.tm_year - 100) << " ";

    return pBuffer.str();
}

std::string DateTime::getHrs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_hour << " ";

    return pBuffer.str();
}

std::string DateTime::getMins() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_min << " ";

    return pBuffer.str();
}

std::string DateTime::getSecs() const
{
    clearPBuffer();

    pBuffer << std::setw(2) <<
        std::setfill('0') <<
        newtime.tm_sec << " ";

    return pBuffer.str();
}

std::string DateTime::getMills() const
{
    clearPBuffer();

    pBuffer << std::setw(4) <<
        std::setfill('0') <<
        tstruct.millitm << " ";

    return pBuffer.str();
}

#include "Logger.h"

Logger::Logger()
{
    openLoggerFile();
    openLoggerFile_w();
}

Logger::Logger(std::string_view const& lFN)
{
   logFileName = lFN;
   openLoggerFile();
   openLoggerFile_w();
}

Logger::~Logger()
{
    closeProgram();
}

std::string Logger::getLogFileName() const
{
   return logFileName;
}

void Logger::log(const std::string& logMessage)
{
   DateTime logTime{};
   logEntry << logTime.getDayMonthYrHrMinSecMs() << logMessage << std::endl;

   // Output to console
   std::clog << logEntry.str();
   
   // Output to the file.
   logfile << logEntry.str();
   logfile.flush();
   logfile.close();

   // Clear the buffer.
   logEntry.str("");
   logEntry.clear();
}

void Logger::log(const std::wstring& logMessage)
{
   DateTime logTime{};
   logEntry_w << logTime.getDayMonthYrHrMinSecMs_w() << logMessage << std::endl;

   // Output to console
   std::wclog << logEntry_w.str();
   
   // Output to the file.
   logfile_w << logEntry_w.str();
   logfile_w.flush();
   logfile_w.close();

   // Clear the buffer.
   logEntry_w.str(L"");
   logEntry_w.clear();
}

std::ostream& Logger::consoleOutPut(const DateTimeStamp logTimeEnum) const
{
    DateTime logTime{};

    switch (logTimeEnum)
    {

        using enum DateTime::TimeStamp;
        case LOG_DAY_MON_YR_HR_MIN_SEC_MS:
            return std::cout << logTime.getDayMonthYrHrMinSecMs() << std::flush;
        case LOG_DAY_MON_YR_HR_MIN_SEC:
            return std::cout << logTime.getDayMonthYrHrMinSecs() << std::flush;
        case LOG_DAY_MON_YR_HR_MIN:
            return std::cout << logTime.getDayMonthYrHrMins() << std::flush;
        case LOG_DAY_MON_YR:
            return std::cout << logTime.getDayMonthYr() << std::flush;
        case LOG_HR_MIN_SEC_MS:
            return std::cout << logTime.getHrMinSecMs() << std::flush;
        case LOG_HR_MIN_SEC:
            return std::cout << logTime.getHrMinSecs() << std::flush;
        case LOG_HR_MIN:
            return std::cout << logTime.getHrMins() << std::flush;
        case LOG_DAY:
            return std::cout << logTime.getDay() << std::flush;
        case LOG_MONTH:
            return std::cout << logTime.getMonth() << std::flush;
        case LOG_YEAR:
            return std::cout << logTime.getYear() << std::flush;
        case LOG_HRS:
            return std::cout << logTime.getHrs() << std::flush;
        case LOG_MINS:
            return std::cout << logTime.getMins() << std::flush;
        case LOG_SECS:
            return std::cout << logTime.getSecs() << std::flush;
        case LOG_MS:
            return std::cout << logTime.getMills() << std::flush;
        default:
            return std::cout << logTime.getNoTimeStamp() << std::flush;

    }
}

std::ostream& Logger::consoleOutPut() const
{
   DateTime logTime{};
   return std::cout << logTime.getNoTimeStamp();
}

std::wostream& Logger::consoleOutput_w(const DateTimeStamp logTimeEnum) const
{
    DateTime logTime{};

    switch (logTimeEnum)
    {

        using enum DateTime::TimeStamp;
        case LOG_DAY_MON_YR_HR_MIN_SEC_MS:
            return std::wcout << logTime.getDayMonthYrHrMinSecMs_w() << std::flush;
        case LOG_DAY_MON_YR_HR_MIN_SEC:
            return std::wcout << logTime.getDayMonthYrHrMinSecs_w() << std::flush;
        case LOG_DAY_MON_YR_HR_MIN:
            return std::wcout << logTime.getDayMonthYrHrMins_w() << std::flush;
        case LOG_DAY_MON_YR:
            return std::wcout << logTime.getDayMonthYr_w() << std::flush;
        case LOG_HR_MIN_SEC_MS:
            return std::wcout << logTime.getHrMinSecMs_w() << std::flush;
        case LOG_HR_MIN_SEC:
            return std::wcout << logTime.getHrMinSecs_w() << std::flush;
        case LOG_HR_MIN:
            return std::wcout << logTime.getHrMins_w() << std::flush;
        case LOG_DAY:
            return std::wcout << logTime.getDay_w() << std::flush;
        case LOG_MONTH:
            return std::wcout << logTime.getMonth_w() << std::flush;
        case LOG_YEAR:
            return std::wcout << logTime.getYear_w() << std::flush;
        case LOG_HRS:
            return std::wcout << logTime.getHrs_w() << std::flush;
        case LOG_MINS:
            return std::wcout << logTime.getMins_w() << std::flush;
        case LOG_SECS:
            return std::wcout << logTime.getSecs_w() << std::flush;
        case LOG_MS:
            return std::wcout << logTime.getMills_w() << std::flush;
        default:
            return std::wcout << logTime.getNoTimeStamp_w() << std::flush;

    }
}

std::wostream& Logger::consoleOutput_w() const
{
   DateTime logTime{};
   return std::wcout << logTime.getNoTimeStamp_w();
}

std::ofstream& Logger::fileOutPut(const DateTimeStamp logTimeEnum) const
{
    DateTime logTime{};

    switch (logTimeEnum)
    {

        using enum DateTime::TimeStamp;
        case LOG_DAY_MON_YR_HR_MIN_SEC_MS:
            logfile << logTime.getDayMonthYrHrMinSecMs() << std::flush;
            break;
        case LOG_DAY_MON_YR_HR_MIN_SEC:
            logfile << logTime.getDayMonthYrHrMinSecs() << std::flush;
            break;
        case LOG_DAY_MON_YR_HR_MIN:
            logfile << logTime.getDayMonthYrHrMins() << std::flush;
            break;
        case LOG_DAY_MON_YR:
            logfile << logTime.getDayMonthYr() << std::flush;
            break;
        case LOG_HR_MIN_SEC_MS:
            logfile << logTime.getHrMinSecMs() << std::flush;
            break;
        case LOG_HR_MIN_SEC:
            logfile << logTime.getHrMinSecs() << std::flush;
            break;
        case LOG_HR_MIN:
            logfile << logTime.getHrMins() << std::flush;
            break;
        case LOG_DAY:
            logfile << logTime.getDay() << std::flush;
            break;
        case LOG_MONTH:
            logfile << logTime.getMonth() << std::flush;
            break;
        case LOG_YEAR:
            logfile << logTime.getYear() << std::flush;
            break;
        case LOG_HRS:
            logfile << logTime.getHrs() << std::flush;
            break;
        case LOG_MINS:
            logfile << logTime.getMins() << std::flush;
            break;
        case LOG_SECS:
            logfile << logTime.getSecs() << std::flush;
            break;
        case LOG_MS:
            logfile << logTime.getMills() << std::flush;
            break;
        default:
            logfile << logTime.getNoTimeStamp() << std::flush;
            break;
    }
    logfile.flush();

    return logfile;
}

std::ofstream& Logger::fileOutPut() const
{
   DateTime logTime{};
   logfile << logTime.getNoTimeStamp() << std::flush;

   return logfile;
}

std::wofstream& Logger::fileOutPut_w(const DateTimeStamp logTimeEnum) const
{
   DateTime logTime{};

   switch (logTimeEnum)
   {
       using enum DateTime::TimeStamp;
       case LOG_DAY_MON_YR_HR_MIN_SEC_MS:
           logfile_w << logTime.getDayMonthYrHrMinSecMs_w() << std::flush;
           break;
       case LOG_DAY_MON_YR_HR_MIN_SEC:
           logfile_w << logTime.getDayMonthYrHrMinSecs_w() << std::flush;
           break;
       case LOG_DAY_MON_YR_HR_MIN:
           logfile_w << logTime.getDayMonthYrHrMins_w() << std::flush;
           break;
       case LOG_DAY_MON_YR:
           logfile_w << logTime.getDayMonthYr_w() << std::flush;
           break;
       case LOG_HR_MIN_SEC_MS:
           logfile_w << logTime.getHrMinSecMs_w() << std::flush;
           break;
       case LOG_HR_MIN_SEC:
           logfile_w << logTime.getHrMinSecs_w() << std::flush;
           break;
       case LOG_HR_MIN:
           logfile_w << logTime.getHrMins_w() << std::flush;
           break;
       case LOG_DAY:
           logfile_w << logTime.getDay_w() << std::flush;
           break;
       case LOG_MONTH:
           logfile_w << logTime.getMonth_w() << std::flush;
           break;
       case LOG_YEAR:
           logfile_w << logTime.getYear_w() << std::flush;
           break;
       case LOG_HRS:
           logfile_w << logTime.getHrs_w() << std::flush;
           break;
       case LOG_MINS:
           logfile_w << logTime.getMins_w() << std::flush;
           break;
       case LOG_SECS:
           logfile_w << logTime.getSecs_w() << std::flush;
           break;
       case LOG_MS:
           logfile_w << logTime.getMills_w() << std::flush;
           break;
       default:
           logfile_w << logTime.getNoTimeStamp_w() << std::flush;
           break;

   }

   return logfile_w;
}

std::wofstream& Logger::fileOutPut_w() const
{
    DateTime logTime{};
    logfile_w << logTime.getNoTimeStamp_w();

    return logfile_w;
}

void Logger::openLoggerFile() const
{
    logfile.open(getLogFileName(), std::ios::app);
    if (!logfile.is_open())
    {
        ErrorList::printErrorMessage(ENOENT);
    }
    else
    {
        if (DEBUG_LOGGER)
        {
            std::cout << "File " << getLogFileName() << " open\n";
        }

    }

}

void Logger::openLoggerFile_w() const
{
    logfile_w.open(getLogFileName(), std::ios::app);
    if (!logfile_w.is_open())
    {
        ErrorList::printErrorMessage(ENOENT);
    }
    else
    {
        if (DEBUG_LOGGER)
        {
            std::cout << "File " << getLogFileName() << " open\n";
        }
    }
}

void Logger::closeLoggerFile() const
{
    if (DEBUG_LOGGER)
    {
        std::cout << "File " << logFileName << " closed\n";
    }

    logfile.flush();
    logfile.close();

    logfile_w.flush();
    logfile_w.close();

}

void Logger::closeProgram() const
{
   DateTime logTime{};
   // Output to the file.
   logfile << logTime.getDayMonthYrHrMinSecMs() << "Error Code: " << GetLastError() << " - " << "Program Closed\n";

   closeLoggerFile();
}
#ifndef LOGGER_H
#define LOGGER_H
#include "DateTime.h"
#include "ErrorList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr bool DEBUG_LOGGER{ false };

constexpr DateTime::TimeStamp GET_DAY_MON_YR_HR_MIN_SEC_MS()
{
    return DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC_MS;
}

constexpr DateTime::TimeStamp GET_DAY_MON_YR_HR_MIN_SEC()
{
	return DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC;
}

constexpr DateTime::TimeStamp GET_DAY_MON_YR_HR_MIN()
{
	return DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN;
}

constexpr DateTime::TimeStamp GET_DAY_MON_YR()
{
	return DateTime::TimeStamp::LOG_DAY_MON_YR;
}

constexpr DateTime::TimeStamp GET_HR_MIN_SEC_MS()
{
	return DateTime::TimeStamp::LOG_HR_MIN_SEC_MS;
}

constexpr DateTime::TimeStamp GET_HR_MIN_SEC()
{
	return DateTime::TimeStamp::LOG_HR_MIN_SEC;
}

constexpr DateTime::TimeStamp GET_HR_MIN()
{
	return DateTime::TimeStamp::LOG_HR_MIN;
}

constexpr DateTime::TimeStamp GET_DAY()
{
	return DateTime::TimeStamp::LOG_DAY;
}

constexpr DateTime::TimeStamp GET_MONTH()
{
	return DateTime::TimeStamp::LOG_MONTH;
}

constexpr DateTime::TimeStamp GET_YEAR()
{
	return DateTime::TimeStamp::LOG_YEAR;
}

constexpr DateTime::TimeStamp GET_HRS()
{
	return DateTime::TimeStamp::LOG_HRS;
}

constexpr DateTime::TimeStamp GET_MINS()
{
	return DateTime::TimeStamp::LOG_MINS;
}

constexpr DateTime::TimeStamp GET_SECS()
{
	return DateTime::TimeStamp::LOG_SECS;
}

constexpr DateTime::TimeStamp GET_MS()
{
	return DateTime::TimeStamp::LOG_MS;
}


class Logger : public ErrorList
{
private:

   /*const*/ std::string logFileName{ "LogFile.txt" };
   mutable std::ofstream logfile{};
   mutable std::wofstream logfile_w{};
   mutable std::ostringstream logEntry{};
   mutable std::wostringstream logEntry_w{};

public:

   explicit Logger();
   explicit Logger(std::string_view const&);
   explicit Logger(const Logger& copyConstructorMember) = default;
   Logger(Logger&& moveConstructorMember) = default;
   ~Logger();

   std::string getLogFileName() const;
   void log(const std::string&);
   void log(const std::wstring&);
   std::ostream& consoleOutPut(const DateTime::TimeStamp) const;
   std::ostream& consoleOutPut() const;
   std::wostream& consoleOutput_w(const DateTime::TimeStamp) const;
   std::wostream& consoleOutput_w() const;
   std::ofstream& fileOutPut(const DateTime::TimeStamp) const;
   std::ofstream& fileOutPut() const;
   std::wofstream& fileOutPut_w(const DateTime::TimeStamp) const;
   std::wofstream& fileOutPut_w() const;
   bool openLoggerFile() const;
   bool openLoggerFile_W() const;
   void closeLoggerFile() const noexcept;
   void closeProgram() const;

};
#endif

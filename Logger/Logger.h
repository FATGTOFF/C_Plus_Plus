#ifndef LOGGER_H
#define LOGGER_H
#include "DateTime.h"
#include "ErrorList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr bool DEBUG_LOGGER{ false };
using DateTimeStamp = DateTime::TimeStamp;

constexpr DateTimeStamp GET_DAY_MON_YR_HR_MIN_SEC_MS()
{
	return DateTimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC_MS;
}

constexpr DateTimeStamp GET_DAY_MON_YR_HR_MIN_SEC()
{
	return DateTimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC;
}

constexpr DateTimeStamp GET_DAY_MON_YR_HR_MIN()
{
	return DateTimeStamp::LOG_DAY_MON_YR_HR_MIN;
}

constexpr DateTimeStamp GET_DAY_MON_YR()
{
	return DateTimeStamp::LOG_DAY_MON_YR;
}

constexpr DateTimeStamp GET_HR_MIN_SEC_MS()
{
	return DateTimeStamp::LOG_HR_MIN_SEC_MS;
}

constexpr DateTimeStamp GET_HR_MIN_SEC()
{
	return DateTimeStamp::LOG_HR_MIN_SEC;
}

constexpr DateTimeStamp GET_HR_MIN()
{
	return DateTimeStamp::LOG_HR_MIN;
}

constexpr DateTimeStamp GET_DAY()
{
	return DateTimeStamp::LOG_DAY;
}

constexpr DateTimeStamp GET_MONTH()
{
	return DateTimeStamp::LOG_MONTH;
}

constexpr DateTimeStamp GET_YEAR()
{
	return DateTimeStamp::LOG_YEAR;
}

constexpr DateTimeStamp GET_HRS()
{
	return DateTimeStamp::LOG_HRS;
}

constexpr DateTimeStamp GET_MINS()
{
	return DateTimeStamp::LOG_MINS;
}

constexpr DateTimeStamp GET_SECS()
{
	return DateTimeStamp::LOG_SECS;
}

constexpr DateTimeStamp GET_MS()
{
	return DateTimeStamp::LOG_MS;
}


class Logger : public ErrorList
{
private:

   std::string logFileName{ "LogFile.txt" };
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
   std::ostream& consoleOutPut(const DateTimeStamp) const;
   std::ostream& consoleOutPut() const;
   std::wostream& consoleOutput_w(const DateTimeStamp) const;
   std::wostream& consoleOutput_w() const;
   std::ofstream& fileOutPut(const DateTimeStamp) const;
   std::ofstream& fileOutPut() const;
   std::wofstream& fileOutPut_w(const DateTimeStamp) const;
   std::wofstream& fileOutPut_w() const;
   void openLoggerFile() const;
   void openLoggerFile_w() const;
   void closeLoggerFile() const;
   void closeProgram() const;

};
#endif

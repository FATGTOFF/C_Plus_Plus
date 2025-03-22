#ifndef LOGGER_H
#define LOGGER_H
#include "DateTime.h"
#include "ErrorList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr bool DEBUG_LOGGER{ false };


class Logger : public ErrorList
{
private:

   const std::string logFileName{ "LogFile.txt" };
   mutable std::ofstream logfile{};
   mutable std::wofstream logfile_w{};
   mutable std::ostringstream logEntry{};
   mutable std::wostringstream logEntry_w{};

public:

   explicit Logger() = default;
   explicit Logger(std::string const&);
   explicit Logger(const Logger& copyConstructorMember) = default;
   Logger(Logger&& moveConstructorMember) = default;
   ~Logger() = default;

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
   void openLoggerFile() const noexcept;
   void closeLoggerFile() const noexcept;
   void closeProgram() const noexcept;


};
#endif

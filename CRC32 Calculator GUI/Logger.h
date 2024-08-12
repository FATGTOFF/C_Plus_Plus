#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "DateTime.h"
#include "ErrorList.h"

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
   explicit Logger();
   explicit Logger(std::string const& logFileName);
   explicit Logger(const Logger& copyConstructorMember) = default;
   Logger(Logger&& moveConstructorMember) = default;
   ~Logger();

   std::string getLogFileName() const;
   void log(const std::string& logMessage);
   void log(const std::wstring& logMessage);
   std::ostream& consoleOutPut() const;
   std::wostream& consoleOutput_w() const;
   std::ofstream& fileOutPut() const;
   std::wofstream& fileOutPut_w() const;
   void closeProgram() noexcept;

};
#endif

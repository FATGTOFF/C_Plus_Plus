#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "DateTime.h"
#include "ErrorList.h"


class Logger : private ErrorList
{
private:
	const std::string logFileName = "LogFile.txt";
	mutable std::ofstream logfile{};
	mutable std::ostringstream logEntry{};
   DateTime time{};

public:
	explicit Logger();
	explicit Logger(std::string const& logFileName);
	explicit Logger(const Logger& copyConstructorMember) = default;
	Logger(Logger&& moveConstructorMember) = default;
   ~Logger();

	std::string getLogFileName() const;
	void log(const std::string& logMessage);
   std::ostream& consoleOutPut() const;
   std::ofstream& fileOutPut() const;


};
#endif

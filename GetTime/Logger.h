#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "DateTime.h"


class Logger
{
private:
	const std::string logFileName = "LogFile.txt";
	std::ofstream logfile{};
	mutable std::ostringstream logEntry{};

public:
	explicit Logger();
	explicit Logger(std::string const& logFileName);
	explicit Logger(const Logger& copyConstructorMember) = default;
	Logger(Logger&& moveConstructorMember) = default;
	~Logger() = default;

	std::string getLogFileName() const;
	void log(const std::string& logMessage);

};
#endif

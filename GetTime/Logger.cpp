#include "Logger.h"


Logger::Logger()
{
	logfile.open(logFileName, std::ios::app);
}

Logger::Logger(std::string const& lFN)
{
	logfile.open(lFN, std::ios::app);
}

std::string Logger::getLogFileName() const
{
	return logFileName;
}

void Logger::log(const std::string& logMessage)
{
	DateTime time{};

	logEntry << time.getDayMonthYrHrMinSecMs() << logMessage << std::endl;

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

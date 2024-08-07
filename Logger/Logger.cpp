#include "Logger.h"


Logger::Logger()
{
   logfile.open(logFileName, std::ios::app);
   if (!logfile.is_open())
   {
      ErrorList::printErrorMessage(ENOENT);
   }
}

Logger::Logger(std::string const& lFN)
{

   logfile.open(lFN, std::ios::app);
   if (!logfile.is_open())
   {
      ErrorList::printErrorMessage(ENOENT);
   }
}

Logger::~Logger()
{
   logfile.close();
}

std::string Logger::getLogFileName() const
{
	return logFileName;
}

void Logger::log(const std::string& logMessage)
{

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

std::ostream& Logger::consoleOutPut() const
{
   return std::cout << time.getDayMonthYrHrMinSecMs();
}

std::ofstream& Logger::fileOutPut() const
{
   logfile << time.getDayMonthYrHrMinSecMs();

   return logfile;
}

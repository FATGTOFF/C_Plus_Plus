#include "pch.h"
#include "Logger.h"


Logger::Logger()
{
   logfile.open(logFileName, std::ios::app);
   if (!logfile.is_open())
   {
      ErrorList::printErrorMessage(ENOENT);
   }

   logfile_w.open(logFileName, std::ios::app);
   if (!logfile_w.is_open())
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

   logfile_w.open(lFN, std::ios::app);
   if (!logfile_w.is_open())
   {
      ErrorList::printErrorMessage(ENOENT);
   }
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

std::ostream& Logger::consoleOutPut() const
{
   DateTime logTime{};
   return std::cout << logTime.getDayMonthYrHrMinSecMs();
}

std::wostream& Logger::consoleOutput_w() const
{
   DateTime logTime{};
   return std::wcout << logTime.getDayMonthYrHrMinSecMs_w();
}

std::ofstream& Logger::fileOutPut() const
{
   DateTime logTime{};
   logfile << logTime.getDayMonthYrHrMinSecMs();

   return logfile;
}

std::wofstream& Logger::fileOutPut_w() const
{
   DateTime logTime{};
   logfile_w << logTime.getDayMonthYrHrMinSecMs_w() << std::flush;

   return logfile_w;
}

void Logger::closeProgram() noexcept
{
   DateTime logTime{};
   // Output to the file.
   logfile << logTime.getDayMonthYrHrMinSecMs() << "Program Closed\n";
   logfile.flush();
   
   logfile.close();
   logfile_w.close();
}
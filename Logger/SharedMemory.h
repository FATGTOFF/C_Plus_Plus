#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include "Logger.h"

constexpr auto DEBUG_SHARED_MEMORY{ false };


#define LOG_TO_FILE_DAY_MON_YR_HR_MIN_SEC_MS                \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC_MS) \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_DAY_MON_YR_HR_MIN_SEC                   \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC)    \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_DAY_MON_YR_HR_MIN                       \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN)        \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_DAY_MON_YR                              \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_DAY_MON_YR)               \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_HR_MIN_SEC_MS                           \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_HR_MIN_SEC_MS)            \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_HR_MIN_SEC                              \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_HR_MIN_SEC)               \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_HR_MIN                                  \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_HR_MIN)                   \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_DAY                                     \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_DAY)                      \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_MONTH                                   \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_MONTH)                    \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_YEAR                                    \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_YEAR)                     \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_HRS                                     \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_HRS)                      \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_MINS                                    \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_MINS)                     \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_SECS                                    \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_SECS)                     \
		<< "Error Code: " << GetLastError() << " - "

#define LOG_TO_FILE_MS                                      \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_MS)                       \
		<< "Error Code: " << GetLastError() << " - "

const static Logger logger_shared{};

struct SharedMemory
{

	Logger const *getLoggerMemAddress() const
	{
		if(DEBUG_SHARED_MEMORY)
		{
			std::cout << "Shared Memory: Memory address of Logger: " << &logger_shared << std::endl;
		}

		return &logger_shared;
	}
};


#endif

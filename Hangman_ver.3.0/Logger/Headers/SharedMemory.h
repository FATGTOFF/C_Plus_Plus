#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include "Debug.h"
#include "Logger.h"

#define LOG_TO_FILE_DAY_MON_YR_HR_MIN_SEC_MS                \
		logger->fileOutPut                                  \
		(DateTime::TimeStamp::LOG_DAY_MON_YR_HR_MIN_SEC_MS) \
		<< "Error Code: " << GetLastError() << " - "

static Logger logger_shared{};

struct SharedMemory
{

	Logger const *getLoggerMemAddress() const
	{
#ifdef DEBUG_HANGMAN
		std::cout << "Shared Memory: Memory address of Logger: " << &logger_shared << std::endl;
#endif
		return &logger_shared;
	}
};


#endif

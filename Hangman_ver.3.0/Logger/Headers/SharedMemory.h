#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include "Logger.h"

static Logger logger_shared{};

struct SharedMemory
{

	Logger *getLoggerMemAddress() const
	{
		return &logger_shared;
	}
};


#endif

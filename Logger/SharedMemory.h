#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include "Logger.h"

constexpr auto DEBUG_SHARED_MEMORY{ false };
const static Logger logger_shared{};

struct SharedMemory
{

	Logger const* getLoggerMemAddress() const
	{
		if (DEBUG_SHARED_MEMORY)
		{
			std::cout << "Shared Memory: Memory address of Logger: " << &logger_shared << std::endl;
		}

		return &logger_shared;
	}

	SharedMemory() = default;
	bool operator==(const SharedMemory& other) const = default;
};


#endif

#include <iostream>
#include "Logger.h"


int main()
{
	Logger logger;
	Logger log("test.txt");

	logger.log("Hello world!");
	log.log("Hi");
}
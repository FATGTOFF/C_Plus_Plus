#include <iostream>
#include "Logger.h"


int main()
{
	Logger logger;
	Logger log("Log_Test.txt");

   log.consoleOutPut(DateTime::TimeStamp::LOG_MS) << "This is a test console Output\n";
   log.fileOutPut() << "This is a test file Output\n";
	logger.log("Hello world!");

}
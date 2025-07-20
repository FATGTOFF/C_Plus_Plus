#include <iostream>
#include "Logger.h"


int main()
{
	Logger logger{};
	Logger log("Log_Test.txt");

   log.consoleOutPut(GET_DAY_MON_YR_HR_MIN_SEC_MS()) << "This is a test console Output GET_DAY_MON_YR_HR_MIN_SEC_MS()\n";
   log.fileOutPut(GET_DAY_MON_YR_HR_MIN_SEC_MS())    << "This is a test file Output GET_DAY_MON_YR_HR_MIN_SEC_MS() \n";
   log.consoleOutPut(GET_DAY_MON_YR_HR_MIN_SEC())    << "This is a test console Output GET_DAY_MON_YR_HR_MIN_SEC()\n";
   log.fileOutPut(GET_DAY_MON_YR_HR_MIN_SEC())       << "This is a test file Output GET_DAY_MON_YR_HR_MIN_SEC()\n";
   log.consoleOutPut(GET_DAY_MON_YR_HR_MIN())        << "This is a test console Output GET_DAY_MON_YR_HR_MIN()\n";
   log.fileOutPut(GET_DAY_MON_YR_HR_MIN())           << "This is a test file Output GET_DAY_MON_YR_HR_MIN()\n";
   log.consoleOutPut(GET_DAY_MON_YR())               << "This is a test console Output GET_DAY_MON_YR()\n";
   log.fileOutPut(GET_DAY_MON_YR())                  << "This is a test file Output GET_DAY_MON_YR()\n";
   log.consoleOutPut(GET_HR_MIN_SEC_MS())            << "This is a test console Output GET_HR_MIN_SEC_MS()\n";
   log.fileOutPut(GET_HR_MIN_SEC_MS())               << "This is a test file Output GET_HR_MIN_SEC_MS()\n";
   log.consoleOutPut(GET_HR_MIN_SEC())               << "This is a test console Output GET_HR_MIN_SEC()\n";
   log.fileOutPut(GET_HR_MIN_SEC())                  << "This is a test file Output GET_HR_MIN_SEC()\n";
   log.consoleOutPut(GET_HR_MIN())                   << "This is a test console Output GET_HR_MIN()\n";
   log.fileOutPut(GET_HR_MIN())                      << "This is a test file Output GET_HR_MIN()\n";
   log.consoleOutPut(GET_DAY())                      << "This is a test console Output GET_DAY()\n";
   log.fileOutPut(GET_DAY())                         << "This is a test file Output GET_DAY()\n";
   log.consoleOutPut(GET_MONTH())                    << "This is a test console Output GET_MONTH()\n";
   log.fileOutPut(GET_MONTH())                       << "This is a test file Output GET_MONTH()\n";
   log.consoleOutPut(GET_YEAR())                     << "This is a test console Output GET_YEAR()\n";
   log.fileOutPut(GET_YEAR())                        << "This is a test file Output GET_YEAR()\n";
   log.consoleOutPut(GET_HRS())                      << "This is a test console Output GET_HRS()\n";
   log.fileOutPut(GET_HRS())                         << "This is a test file Output GET_HRS()\n";
   log.consoleOutPut(GET_MINS())                     << "This is a test console Output GET_MINS()\n";
   log.fileOutPut(GET_MINS())                        << "This is a test file Output GET_MINS()\n";
   log.consoleOutPut(GET_SECS())                     << "This is a test console Output GET_SECS()\n";
   log.fileOutPut(GET_SECS())                        << "This is a test file Output GET_SECS()\n";
   log.consoleOutPut(GET_MS())                       << "This is a test console Output GET_MS()\n";
   log.fileOutPut(GET_MS())                          << "This is a test file Output GET_MS()\n";

   logger.log("Hello world!");

}
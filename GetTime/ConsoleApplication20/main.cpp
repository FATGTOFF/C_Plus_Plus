#define _CRT_SECURE_NO_WARNINGS 1

/* strftime example */
#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */

int main()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[100];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 100, "%b %d, %Y %I:%M %p.", timeinfo);
	puts(buffer);

	return 0;
}

//#include <ctime>
//#include <iostream>
//
//int main()
//{
//	time_t rawtime = time(nullptr);
//	tm* timeinfo = localtime(&rawtime);
//
//	std::cout << asctime(timeinfo) << "\n";
//	return 0;
//}/*%b %e, %G */
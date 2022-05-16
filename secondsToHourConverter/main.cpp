#include <iostream>
#include <iomanip> // To use setfill and setw methods to lead 0s

int main()
{
	double elapsedTimeSecs = 0.0;

	std::cout << "Elapsed Time (secs): ";
	std::cin >> elapsedTimeSecs;

	double secondsToHours = elapsedTimeSecs / 3600;

	int hours = static_cast<int>(secondsToHours) % 10;
	double minutes = static_cast<int>(secondsToHours) % 100;
	minutes = secondsToHours - minutes;
	minutes *= 60;
	double seconds = static_cast<int>(minutes) % 1000;
	seconds = minutes - seconds;
	seconds *= 60;

	std::cout << "Output: ";
	std::cout << std::setfill('0') << std::setw(2) << hours
		<< ":" << std::setfill('0') << std::setw(2) 
		<< static_cast<int>(minutes) << ":" << std::setfill('0') 
		<< std::setw(2) << seconds << std::endl;
}
#include <iostream>
#include <thread>
#include <chrono>

void functionToInfiniteLoop();

int main()
{
	std::cout << "Program started\r\n";

	while (true)
	{
		functionToInfiniteLoop();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

void functionToInfiniteLoop()
{
	static auto loopCounter{ 0 };
	static auto numOfTimesIsPrinted{ 0 };

	++loopCounter;

	if (50 == loopCounter)
	{
		++numOfTimesIsPrinted;
		std::cout << " 50 * 200ms = 10 seconds elapsed [" <<
			numOfTimesIsPrinted << "]\r\n";
		loopCounter = 0;
	}
}

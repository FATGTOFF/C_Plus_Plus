#include <iostream>
#include <cstdlib> // For exit Function.
#include "Pyramid.h"

void validateInput(double&);

int main()
{
	Pyramid calcArea;
	double num{};

	std::cout << "Enter the Pyramid's base: ";
	std::cin >> num;
	validateInput(num);
	calcArea.setBase(num);

	std::cout << "Enter the Pyramid's slant: ";
	std::cin >> num;
	validateInput(num);
	calcArea.setSlant(num);

	std::cout << "The Pyramid's Surface Area: ";
	std::cout << calcArea.getTotalArea() << std::endl;

	return 0;
}

void validateInput(double &num)
{
	int attempts{ 3 };
	while (num < 1 && attempts != 0)
	{
		attempts--;
		if (attempts == 0)
		{
			std::cout << "Sorry, but you had 3 tries.\n";
			std::cout << "Closing the program...\n";
			std::exit(0);
		}

		else
		{
			std::cout << "Your input is incorrect.\n";
			std::cout << "Your input should be above 0\n";
			std::cout << "You have " << attempts << " attempts left\n";
			std::cout << "Try Again\n";
			std::cout << "Input the number again: >>>";
			std::cin >> num;
		}
	}
}

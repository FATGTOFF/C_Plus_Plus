//Write a program that will do the following steps :
//-generate 2 random integer numbers between 1 and 20 inclusive(1 - 20, no 0 values)
//- calculate the square root of each number
//- calculate the average of the 2 numbers
//- print the 2 random numbers
//- print the square root of each random number with 3 digits after the decimal point
//- print the average of the 2 numbers with 1 digit after the decimal point

#include <iostream>
#include <random>
#include <iomanip>
#include <cmath>

int randomNumber(int, int);
void average(const int, const int);
void printRandomNum(const int, const int);
void printSquareRoot(const int);

int main()
{
	const int num1 = randomNumber(1,20);
	const int num2 = randomNumber(1,20);
	
	printRandomNum(num1, num2);
	average(num1, num2);
	printSquareRoot(num1);
	printSquareRoot(num2);

	return 0;
}

int randomNumber(int min, int max)
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distrib(min, max);

	const int random = distrib(rng);

	return random;
}

void average(const int num1, const int num2)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "The average is " << (num1 + num2) / 2.0 << std::endl;
	std::cout << std::fixed << std::setprecision(0);
}

void printRandomNum(const int num1, const int num2)
{
	std::cout << "The two random numbers are " << num1
		<< " and " << num2 << std::endl;
}

void printSquareRoot(const int num)
{
	std::cout << std::fixed << std::setprecision(3);

	std::cout << "The square root of " << num
		<< " is " << std::sqrt(num) << std::endl;

	std::cout << std::fixed << std::setprecision(0);
}

#include "USABirds.h"
#include <iostream>
#include <fstream>
#include <algorithm> // For the use of the replace function.
#include <random>

USABirds::USABirds()
{
	FileName = "United States.txt"; //THE STATE.
	totalElements = getTotalElements();

	std::fstream Birds(FileName, std::ios::in);
	birds = new std::string[totalElements];
	numElements = totalElements;
	for (int count = 0; count < numElements; count++)
		std::getline(Birds, birds[count]);

	Birds.close();
}

USABirds::~USABirds()
{
	delete[] birds;
	birds = nullptr;
}

std::string USABirds::getWord() const
{
	int random = randomNumber(totalElements);
	//std::cout << birds[random] << std::endl; // DELETE THIS LINE PRIMA TO PLAYING IT.

	return birds[random];
}

int USABirds::getTotalElements() const
{
	std::ifstream countElements;
	std::string elements;
	std::string US = "UNITED STATES.txt"; //THE STATE
	countElements.open(US);
	int count{ 0 };

	if (countElements.fail())
	{
		std::cout << "Error!: The file [" << US << "] does not exist\n";
		std::cout << "Ensure the file [" << US << "] is in the same folder as the\n";
		std::cout << "hangman.exe file\n";
		std::cout << "The program will close\n";
		std::exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "The file [" << US << "] was open successfully...\n";
		std::cout << "Now reading [" << US << "] ...\n";
		std::replace(US.begin(), US.end(), '.', ' ');
		std::replace(US.begin(), US.end(), 't', ' ');
		std::replace(US.begin(), US.end(), 'x', ' ');

		while (getline(countElements, elements))
			count++;

		std::cout << "The Country of " << US << "]\b\b\b\bhas " << count << " species of birds\n";
		std::cout << "Good luck!!!\n";
	}
	countElements.close();

	return count;

}

int USABirds::randomNumber(int max) const
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distrib(0, max);

	const int random = distrib(rng);

	return random;
}

#include "Birds.h"
#include <iostream>
#include <fstream>
#include <random>

Birds::Birds(std::string State)
{
	totalElements = getTotalElements(State);

	std::ifstream BirdsFile(State);
	birds = new std::string[totalElements];
	numElements = totalElements;
	for (int count = 0; count < numElements; count++)
		std::getline(BirdsFile, birds[count]);


	BirdsFile.close();
}

Birds::~Birds()
{
	delete[] birds;
	birds = nullptr;
}

std::string Birds::getWord() const
{
	int random = randomNumber(totalElements);
	//std::std::cout << birds[random] << std::std::endl; // DELETE THIS LINE PRIMA TO PLAYING IT.

	return birds[random];
}

int Birds::getTotalElements(std::string State) const
{
	std::ifstream countElements;
	std::string elements;
	countElements.open(State);
	int count{ 0 };

	if (countElements.fail())
	{
		std::cout << "ERROR!: The file [" << State << "] does not exist\n";
		std::cout << "Ensure the file [" << State << "] is in the same folder as the\n";
		std::cout << "hangman.exe file\n";
		std::cout << "The program will close\n";
		std::exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "The file [" << State << "] was open successfully...\n";
		std::cout << "Now reading [" << State << "] ...\n";

		while (std::getline(countElements, elements))
			count++;

		if (count == 0)
		{
			std::cout << "ERROR!: The contents of the file cannot be read.\n";
			std::cout << "The program will close.\n";
			std::exit(EXIT_FAILURE);
		}

		std::cout << "The State of " << State << "\b\b\b\b has " << count << " species of birds\n";
		std::cout << "Good luck!!!\n";
	}
	countElements.close();

	return count;

}

int Birds::randomNumber(int max) const
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distrib(0, max);

	const int random = distrib(rng);

	return random;
}

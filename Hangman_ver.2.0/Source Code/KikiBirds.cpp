#include "KIKIBirds.h"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm> // For the use of the replace function.


KIKIBirds::KIKIBirds()
{
	FileName = "Types of Birds.txt"; //THE STATE.
	totalElements = getTotalElements();

	std::fstream Birds(FileName, std::ios::in);
	birds = new std::string[totalElements];
	numElements = totalElements;
	for (int count = 0; count < numElements; count++)
		std::getline(Birds, birds[count]);

	Birds.close();
}

KIKIBirds::~KIKIBirds()
{
	delete[] birds;
	birds = nullptr;
}

std::string KIKIBirds::getWord() const
{
	int random = randomNumber(totalElements);
	//std::cout << words[random] << std::endl; // DELETE THIS LINE PRIMA TO PLAYING IT.

	return birds[random];
}

int KIKIBirds::getTotalElements() const
{
	std::ifstream countElements;
	std::string elements;
	std::string State = "Types of Birds.txt"; //THE STATE
	countElements.open(State);
	int count{ 0 };

	if (countElements.fail())
	{
		std::cout << "ERROR!: The file [" << State << "] does not exist " << std::endl;
		std::cout << "Ensure the file [" << State << "] is in the same folder as the" << std::endl;
		std::cout << "hangman.exe file" << std::endl;
		std::cout << "The program will close" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "The file [" << State << "] was open successfully..." << std::endl;
		std::cout << "Now reading [" << State << "] ..." << std::endl;
		std::replace(State.begin(), State.end(), '.', ' ');
		std::replace(State.begin(), State.end(), 't', ' ');
		std::replace(State.begin(), State.end(), 'x', ' ');

		while (std::getline(countElements, elements))
			count++;

		if (count == 0)
		{
			std::cout << "ERROR!: The contents of the file cannot be read." << std::endl;
			std::cout << "The program will close." << std::endl;
			std::exit(EXIT_FAILURE);
		}


		//std::cout << "The State of " << State << "]\b\b\b\bhas " << count << " species of birds" << std::endl;
		std::cout << "Good luck!!!" << std::endl;
	}
	countElements.close();

	return count;

}

int KIKIBirds::randomNumber(int max) const
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distrib(0, max);

	const int random = distrib(rng);

	return random;
}

#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <algorithm> // For the use of the replace function.
#include <random>


Dictionary::Dictionary()
{
	FileName = "Dictionary.txt"; //THE STATE.
	totalElements = getTotalElements();

	std::fstream Birds(FileName, std::ios::in);
	words = new std::string[totalElements];
	numElements = totalElements;
	for (int count = 0; count < numElements; count++)
		std::getline(Birds, words[count]);

	Birds.close();
}

Dictionary::~Dictionary()
{
	delete[] words;
	words = nullptr;
}

std::string Dictionary::getWord() const
{
	int random = randomNumber(totalElements);
	//std::cout << words[random] << std::endl; // DELETE THIS LINE PRIOR TO PLAYING IT.

	return words[random];
}

int Dictionary::getTotalElements() const
{
	std::ifstream countElements;
	std::string elements;
	std::string State = "DICTIONARY.txt"; //THE STATE
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
		std::replace(State.begin(), State.end(), '.', ' ');
		std::replace(State.begin(), State.end(), 't', ' ');
		std::replace(State.begin(), State.end(), 'x', ' ');

		while (getline(countElements, elements))
			count++;

		if (count == 0)
		{
			std::cout << "ERROR!: The contents of the file cannot be read.\n";
			std::cout << "The program will close.\n";
			std::exit(EXIT_FAILURE);
		}


		std::cout << "The file " << State << "]\b\b\b\bhas " << count << " words in the file\n";
		std::cout << "Good luck!!!\n";
	}
	countElements.close();

	return count;

}

int Dictionary::randomNumber(int max) const
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distrib(0, max);

	const int random = distrib(rng);

	return random;
}

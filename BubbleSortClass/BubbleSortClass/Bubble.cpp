#include <iostream>
#include <fstream>
#include <string>
#include "Bubble.h"

void Bubble::countNumOfElements()
{
	int dummyVariable;

	numElements = 0;
	inputData.open("source.txt");

	if (inputData)
	{
		std::cout << "Counting the number of elements in the file...\n";
		while (inputData >> dummyVariable)
			numElements++;

		std::cout << "Found " << numElements << " in the file.\n";
		inputData.close();
	}
	else
		std::cout << "Error opening the file.\n";
}

Bubble::Bubble()
{
	countNumOfElements();
	data = new int[numElements];
	for (int count = 0; count < numElements; count++)
		data[count] = 0;
}

Bubble::~Bubble()
{
	delete[] data;
}

void Bubble::getData(std::string inputFile)
{
	inputData.open(inputFile);

	if (inputData)
	{
		std::cout << "Obtaining the data from the file " << inputFile << " ...\n";
		for (int count = 0; count < numElements; count++)
			inputData >> data[count];

		inputData.close();
	}
	else
		std::cout << "Error opening the file.\n";
}

void Bubble::bubbleSort()
{
	bool swap;
	int temp{0};

	std::cout << "Sorting the data in ascending order...\n";
	do
	{
		swap = false;
		for (int count = 0; count < (numElements - 1); count++)
		{
			if (data[count] > data[count + 1])
			{
				temp = data[count];
				data[count] = data[count + 1];
				data[count + 1] = temp;
				swap = true;
			}

		}
	} while (swap);

}

void Bubble::writeData(std::string outputFile)
{
	outputData.open(outputFile);

	std::cout << "Writing the data into the file " << outputFile << " ...\n";
	for (int count = 0; count < numElements; count++)
		outputData << data[count] << std::endl;
	
	std::cout << "The data was saved to the file " << outputFile << " \n";
	outputData.close();
}

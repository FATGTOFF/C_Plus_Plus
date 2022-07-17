#include <iostream>
#include <fstream>

bool isEven(int numbers);
int sumAllNumbers(int runningTotal, int numbers);
int average(int runningTotal, int countLines);
void processFile(std::ifstream &inFile, std::ofstream &outFile);

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;

	processFile(inFile, outFile);

	std::cout << "Done.\n";

}

bool isEven(int numbers)
{
	if (numbers % 2 == 0 || numbers == 0)
	{
		return true;
	}

	return false;
}

int sumAllNumbers(int runningTotal, int numbers)
{
	return runningTotal += numbers;
}

int average(int runningTotal, int countLines)
{
	return runningTotal/countLines;
}

void processFile(std::ifstream& inFile, std::ofstream& outFile)
{
	int numbers{};
	int countLines{ 0 };
	int runningTotal{ 0 };
	int countEven{ 0 };
	int countOdds{ 0 };
	int countZero{ 0 };

	inFile.open("Data.txt");
	outFile.open("output.txt");

	if (!inFile)
	{
		std::cout << "Error opening Data.txt\n";
		return;
	}

	else
	{

		while (inFile >> numbers)
		{
			// Count the numbers...
			countLines++;

			// Write the numbers to the output file
			outFile << numbers << " ";

			// When the count reaches 10, create a new line.
			if (countLines % 10 == 0)
			{
				outFile << std::endl;
			}

			runningTotal += numbers;

			// Check if the number is even or 0, then count it as even number.
			if (isEven(numbers))
			{
				countEven++;

				if (numbers == 0)
				{
					countZero++;
				}
			}
			// Odd number. 
			else
			{
				countOdds++;
			}

		}

		// Since all the numbers are processed, not we can close the file.
		inFile.close();
	}

	// Write to the ouput file the information.
	outFile << "\nThere are " << countEven << " evens, which includes " << countZero << " zeros\n";
	outFile << "Total number of odds are: " << countOdds << std::endl;
	outFile << "The sum of numbers = " << runningTotal << std::endl;
	outFile << "The average is " << average(runningTotal, countLines) << std::endl;

	outFile.close();
}

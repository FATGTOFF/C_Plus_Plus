#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main()
{
	std::ifstream inFile/*{"Numbers.txt"}*/;
	std::string fileName {"Numbers.txt"};
	double numbers{};
	int countLines{0};
	double runningTotal{0.0};

	inFile.open(fileName); // Step 4a.

	if (!inFile)
	{
		std::cout << "Error opening " << fileName << std::endl;
		return 0;
	}

	else
	{
		while (!inFile.eof()) // Step 4b.
		{
			// As long as it reads number, count it. do not count blank lines.
			if (inFile >> numbers) // Step 4c.
				countLines++; // Step 5.

			runningTotal += numbers; // Step 6.
		}
		inFile.clear();
		inFile.close(); // Step 7.
	}

	double average {runningTotal / countLines}; // Step 8.

	// Step 9.
	std::cout << "There are " << countLines << " lines in the file.\n";
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Total value: " << runningTotal << std::endl;
	std::cout << "Average value: " << average << std::endl;
}
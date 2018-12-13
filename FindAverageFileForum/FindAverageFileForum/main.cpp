#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For use of the atof operator.
#include <iomanip> // For use of the setprecision

bool readFile(std::ifstream &, std::string);
void displayFileContents(std::ifstream&, std::string , std::string,
	std::string, std::string);

int main()
{
	std::string firstName{};
	std::string lastName{};
	std::string email{};
	std::string num{};
	std::ifstream inputFile;

	if (readFile(inputFile, "credit.txt"))
	{
		std::cout << "File opened successfully.\n";
		std::cout << "Now reading data from the file...\n";
		displayFileContents(inputFile, firstName, lastName, email, num);
		inputFile.close();
		std::cout << "\nDone\n";
	}
	else
		std::cout << "File open error!\n";

	return 0;
}

bool readFile(std::ifstream &inputFile, std::string fileName)
{
	inputFile.open(fileName);
	if (inputFile.fail())
		return false;
	else
		return true;
}

void displayFileContents(std::ifstream& inputFile, std::string firstName, std::string lastName,
std::string email, std::string num)
{
	char tab{'\t'};
	char endLine{'\n'};
	int countList{0};
	float runningTotal{0.0};

	while (std::getline(inputFile, firstName, tab))
	{
		std::cout << "First Name: " << firstName << std::endl;
		std::getline(inputFile, lastName, tab);
		std::cout << "Last Name: " << lastName << std::endl;
		std::getline(inputFile, num, tab);
		std::cout << "Number: " << num << std::endl;
		std::getline(inputFile, email, endLine);
		std::cout << "Email: " << email << std::endl;
		countList++;
		float number = std::stof(num);
		runningTotal += number;
	}

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "The last number of the range is " << num << std::endl;
	std::cout << "The sum of this range is " << runningTotal << std::endl;
	std::cout << "The number of items in this range is " << countList << std::endl;
	std::cout << "The average of this range is " << runningTotal / countList << std::endl;

}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void readFileSauceNames(std::ifstream&, std::string[], std::string, const std::size_t);
void readFileSaucePrices(std::ifstream&, double[], std::string, const std::size_t);
void inputAmountSold(std::string[], double[], std::size_t [], const std::size_t);
double calculateTotalSales(double[], std::size_t[], const std::size_t);
std::size_t lowestSoldProduct(std::size_t[], const std::size_t);
std::size_t highestSoldProduct(std::size_t[], const std::size_t);
void displayTable(std::string[], double[], std::size_t[], const std::size_t);

int main()
{
	std::ifstream inFile;
	std::string fileSauceNames{"sauces_names.txt"};
	std::string fileSaucePrices{"sauces_prices.txt"};
	const std::size_t size{6};
	std::string arrSauceNames[size];
	double arrSaucePrices[size];
	std::size_t amountSold[size];

	readFileSauceNames(inFile, arrSauceNames, fileSauceNames, size);
	readFileSaucePrices(inFile, arrSaucePrices, fileSaucePrices, size);
	inputAmountSold(arrSauceNames, arrSaucePrices, amountSold, size);
	displayTable(arrSauceNames, arrSaucePrices, amountSold, size);

	std::cout << "Total: $" << std::fixed << std::setprecision(2) <<
		calculateTotalSales(arrSaucePrices, amountSold, size);
	
	std::cout << "\nLowest Product Sold: " << arrSauceNames[lowestSoldProduct(amountSold, size)];
	std::cout << "\nHighest Product Sold: " << arrSauceNames[highestSoldProduct(amountSold, size)];
}

void readFileSauceNames(std::ifstream &inFile, std::string arrSauceNames[], 
	std::string fileSauceNames, const std::size_t size)
{
	inFile.open(fileSauceNames);

	if (!inFile)
	{
		std::cerr << "File " << fileSauceNames << " could not be opened.\n";
		return;
	}
	else
	{
		std::cout << "Reading from the file " << fileSauceNames << std::endl;
		for (std::size_t count = 0; count < size; count++)
		{
			std::getline(inFile, arrSauceNames[count]);
		}
		std::cout << "Finished reading from " << fileSauceNames << std::endl;	
	}
	inFile.close();
}

void readFileSaucePrices(std::ifstream &inFile, double arrSaucePrices[], 
	std::string fileSaucePrices, const std::size_t size)
{
	inFile.open(fileSaucePrices);

	if (!inFile)
	{
		std::cerr << "File " << fileSaucePrices << " could not be opened.\n";
		return;
	}
	else
	{
		std::cout << "Reading from the file " << fileSaucePrices << std::endl;
		for (std::size_t count = 0; count < size; count++)
		{
			inFile >> arrSaucePrices[count];
		}
		std::cout << "Finished reading from " << fileSaucePrices << std::endl;
	}
	inFile.close();
}

void inputAmountSold(std::string arrSauceNames[], double arrSaucePrices[], 
	std::size_t amountSold[], const std::size_t size)
{
	for (std::size_t count = 0; count < size; count++)
	{
		std::cout << "How many " << arrSauceNames[count]
			<< " has been sold: ";
		std::cin >> amountSold[count];
	}
}

double calculateTotalSales(double arrSaucePrices[], std::size_t amountSold[], const std::size_t size)
{
	double total{0.0};
	for (std::size_t count = 0; count < size; count++)
	{
		total += arrSaucePrices[count] * amountSold[count];
	}
	return total;
}

std::size_t lowestSoldProduct(std::size_t amountSold[], const std::size_t size/*, std::size_t &lowest*/)
{
	std::size_t element{0};
	std::size_t lowest = amountSold[0];
	for (std::size_t count = 1; count < size; count++)
	{
		if (lowest > amountSold[count])
		{
			lowest = amountSold[count];
			element = count;
		}
	}
	return element;
}

std::size_t highestSoldProduct(std::size_t amountSold[], const std::size_t size/*, std::size_t &highest*/)
{
	std::size_t element{ 0 };
	std::size_t highest = amountSold[0];
	for (std::size_t count = 1; count < size; count++)
	{
		if (highest < amountSold[count])
		{
			highest = amountSold[count];
			element = count;
		}
	}
	return element;
}

void displayTable(std::string arrSauceNames[], double arrSaucePrices[],
	std::size_t amountSold[], const std::size_t size)
{
	std::cout << "-----------------------------------"
		<< "----------------------------------------\n";
	std::cout << std::left << std::setw(25) << "Types of Sauces "
		<< std::setw(15) << " Price " << std::setw(25)
		<< "Amount Purchased " << "Total\n";

	for (std::size_t count = 0; count < size; count++)
	{
		std::cout << "-----------------------------------"
			<< "----------------------------------------\n";
		std::cout << std::left << std::setw(26) << arrSauceNames[count]
			<< "$"<< std::setw(20) << arrSaucePrices[count] << std::setw(18)
			<< amountSold[count] << std::fixed << std::setprecision(2) 
			<< "$" << arrSaucePrices[count] * amountSold[count] << std::endl;
	}
	std::cout << "-----------------------------------"
		<< "----------------------------------------\n";
}

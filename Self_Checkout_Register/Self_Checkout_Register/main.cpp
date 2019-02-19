#include <iostream>
#include <string>
#include <iomanip>

// a Cash Register struct to hold the following members.
struct CashRegister
{
	std::string item;
	double price;
	unsigned int numItems;
};

//Function prototypes.
void inputData(CashRegister[], const unsigned int);
void print(CashRegister[], const unsigned int, const double);

int main()
{
	const unsigned int numOfItems{2}; // Holds the size of the array.
	const double salesTax{.0925}; // 9.25% sales tax.
	CashRegister selfRegister[numOfItems]{};

	inputData(selfRegister, numOfItems); // Call the function to enter the data.
	print(selfRegister, numOfItems, salesTax); // Call the function to print.

	return 0;
}

/*
	This function is used for a for loop to allow the user
	to input the required information for the cash register.
*/
void inputData(CashRegister selfRegister[], const unsigned int numOfItems)
{
	for (std::size_t count = 0; count < numOfItems; count++)
	{
		std::cout << "Enter the name of item " << count + 1 << ": ";
		std::getline(std::cin, selfRegister[count].item);

		std::cout << "Enter the number of " << selfRegister[count].item
			<< "(s) and the price of each: ";
		std::cin >> selfRegister[count].numItems >> selfRegister[count].price;

		std::cin.ignore();
	}
}

void print(CashRegister selfRegister[], const unsigned int numOfItems, const double salesTax)
{
	double runningTotal{0.0};
	double extPrice{};
	double tax{};
	std::cout << "Item\t\t\tCount\tPrice\tExt.Price\n";
	std::cout << "====\t\t\t=====\t=====\t=========\n";

	for (std::size_t count = 0; count < numOfItems; count++)
	{
		std::cout << std::left << std::setw(20) << selfRegister[count].item << "\t";
		std::cout << selfRegister[count].numItems << "\t";
		std::cout << std::fixed << std::setprecision(2) 
			<< selfRegister[count].price << "\t";
		extPrice = selfRegister[count].numItems * selfRegister[count].price;
		runningTotal += extPrice;
		std::cout << extPrice << std::endl;
		std::cout << std::fixed << std::setprecision(0);
	}
	tax = runningTotal * salesTax;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Tax\t\t\t\t\t" << tax << std::endl;
	std::cout << "Total\t\t\t\t\t" << runningTotal + tax << std::endl;
}

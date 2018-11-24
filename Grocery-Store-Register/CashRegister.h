/****************************************************************************
Header for the CashRegister class.

Carlos Vazquez

This class simulates the operation of a grocery store checkout system. This 
program builds a data structure to contain information on all the products 
available in the store. Then the program prints the cash register receipt 
for each customer.

The class has the following constructors:
- A default constructor that dynamically allocates memory into the array
- A destructor construtor that ensures the memory is returned once it is 
not needed it.
****************************************************************************/

#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <iostream>
#include <string>
using namespace std;

class CashRegister
{
protected:

	int TOTALINVENTORY; // This variable is used to provide a fixed amount of elements in the inventory.
	int *productNumber; // is a five-digit positive integer.
	string *description; // is a string of at most 12 characters with no embedded blanks.
	double *price; // Price of the product.
	char *tax; // 'T' if the product is taxable, 'N' if it is not taxable.
	char *anotherCustomer; // To ask the user if another customer needs to be process.

	string inFileName; //The name of the file for the program to obtain the inventory.
	string outFileName; //The name of the file, which will provide the output to the file.
	int productID;
	double totalTax;
	double taxes; // The taxes are at 7.5%
	double subTotal;
	double total;
	int times;
	int results;
	int duplicatedTimes; // Counter to count how many duplicated Items are in the inventory.
	int numberofCustomer; // Counter of number of customers.
	int totalElements; // Counter that counts the number of Elements on the file Invent.dat.
	bool inputFail; // This variable is used on the function verifyInputIsCorrect.

	// Functions.
	void resetCountDuplicatedItems(); // Resets the counter duplicatedTimes to zero.
	void displayMenuWithTest(int&); // If the file open successfully, then this function displays.
	void displayMenuWithOutTest(int&); // If the file fail opening, then this function displays.
	int getNumberofTimes();
	void verifyInputIsCorrect(int&);
	int searchDuplicatedProduct(int[], int, int, int&);




public:

	CashRegister(int&);
	~CashRegister();

	//Friends.
	friend istream & operator >> (istream&, CashRegister &inventory);


};
#endif
// Implementation for the CashRegister class.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype> // To use toupper function.
#include <cstdlib> // To use the exit function.
#include "CashRegister.h"
#include "DuplicateProduct.h"
#include "ProductNotFound.h"
#include "NotWithinRange.h"
#include "FileNotFound.h"
using namespace std;


/****************************************************************************
Constructor- it sets the data members to their values.
It sets the names of the file. It uses the try/catch method to test the 
Invent.dat by opening and closing the file (if successful) or will throw an exception
to let the user know to verify the file is available and will exit the program.

Input Parameters:  char (passing by reference).
****************************************************************************/
CashRegister::CashRegister(int &choice)
{
	// The variables are set to nullptr, because they are dynamically array allocated memory.
	TOTALINVENTORY = 50; // The value set to use for an array.
	productNumber = nullptr;
	description = nullptr;
	price = nullptr;
	tax = nullptr;
	anotherCustomer =nullptr;

	productNumber = new int[TOTALINVENTORY];
	description = new string[TOTALINVENTORY];
	price = new double[TOTALINVENTORY];
	tax = new char[TOTALINVENTORY];
	anotherCustomer = new char[100];

	inFileName = "Invent.in";  // Make sure the file is available in the folder.
	outFileName = "Receipts.out"; // It will be created at run-time.

	productID = 0;
	totalTax = 0.0;
	taxes = 0.075; // The taxes is setup to 7.50%. You can change it here to another value.
	subTotal = 0.0;
	total = 0.0;
	times = 0;
	results = 0;
	duplicatedTimes = 0;
	numberofCustomer = 1; // It is a counter that MUST begin with one. It is used to print the customer number in the receipt.
	totalElements = 0;
	inputFail = true; 

	try
	{

		fstream inventory(inFileName, ios::in);

		if (inventory.fail())
			throw FileNotFound(inFileName);

		else
			inventory.close();

	}
	catch (FileNotFound& exceptionFileNotFound)
	{
		cerr << "Error opening the file " << exceptionFileNotFound.getFileName() << endl;
		cerr << "Please, verify the Invent.data file is " << endl;
		cerr << "in the same folder as the .exe file." << endl;
		cout << "Closing the program..." << endl;
		cout << "Press Enter key to close the program.";
		cin.get(); // This function is used to allow the user to see the error message, prior closing the program.
		exit(1); // The number 1 in this function notify the OS the program closed with an error.		
	}

}

/****************************************************************************
Destructor- it de-allocates the memory from the array and return it back to
the computer memory.

****************************************************************************/
CashRegister :: ~CashRegister()
{
	delete[] productNumber;
	productNumber = nullptr;

	delete[] description;
	description = nullptr;

	delete[] price;
	price = nullptr;

	delete[] tax;
	tax = nullptr;

	delete[] anotherCustomer;
	anotherCustomer = nullptr;

}

/****************************************************************************
Function name:  resetCountDuplicatedItems

Description:	This function resets the counter duplicatedTimes.

Input Parameters:  None.

Return Type:  double
****************************************************************************/
void CashRegister::resetCountDuplicatedItems() 
{
	duplicatedTimes = 0;

}

/****************************************************************************
Function name:  displayMenuWithTest

Description:	This function displays the main menu with the condition
that it can read the file to test the program.

Input Parameters:  int choice.

Return Type:  choice by passing reference
****************************************************************************/
void CashRegister::displayMenuWithTest(int& choice)
{
	cout << "\t\t     -------------------------------------\n";
	cout << "\t\t     Welcome to the Cash Register Program\n";
	cout << "\t\t     -------------------------------------\n";
	cout << endl;

	cout << "\n\t\t\t=====Select from the Menu======\n";
	cout << "\t\t     -------------------------------------\n";
	cout << "\t\t     " << "1. Run a Program Test " << endl;
	cout << "\t\t     " << "2. Start the Program " << endl;
	cout << "\t\t     " << "3. Quit the program " << endl;
	cout << "\t\t     -------------------------------------\n";
	cout << "Enter your choice: ";
	verifyInputIsCorrect(choice);

}

/****************************************************************************
Function name:  displayMenuWithOutTest

Description:	This function displays the main menu with the condition
that it cannot read the file used to run the test driver of the program.

Input Parameters:  int choice.

Return Type:  choice by passing reference
****************************************************************************/
void CashRegister::displayMenuWithOutTest(int& choice)
{
	cout << "\t\t     -------------------------------------\n";
	cout << "\t\t     Welcome to the Cash Register Program\n";
	cout << "\t\t     -------------------------------------\n";
	cout << endl;

	cout << "\n\t\t\t=====Select from the Menu======\n";
	cout << "\t\t     -------------------------------------\n";
	cout << "\t\t     " << "2. Start the Program " << endl;
	cout << "\t\t     " << "3. Quit the program " << endl;
	cout << "\t\t     -------------------------------------\n";
	cout << "Enter your choice: ";
	verifyInputIsCorrect(choice);

	while (choice != 2 && choice != 3)
	{
		cout << "Your choice " << choice << " is incorrect. Try again." << endl;
		cout << "Enter your choice: ";
		verifyInputIsCorrect(choice);
	}
}

/****************************************************************************
Function name:  getNumberofTimes

Description:	This function determines if the user inputted the value
according to the parameters of the function. If the parameters are incorrect,
then it will throw an exception.

Input Parameters:  None.

Return Type:  int
****************************************************************************/
int CashRegister::getNumberofTimes()
{
	if (times < 0 || times > 100)
		throw NotWithinRange(times);

	else
		return times;
}

/****************************************************************************
Function name:  searchDuplicatedProduct

Description:	This function calls the function to reset the counter of
duplicatedItems to 0. It will open the file Invent.dat to read the file. The
search type will be linear . It will use the try/catch method to determine
if a product is ducplicated or not in the inventory and will throw an
exception in the event the product is duplicated or not in the inventory.

Input Parameters:  int array, int first, int last, int &product number.

Return Type:  int
****************************************************************************/
int CashRegister::searchDuplicatedProduct(int array[], int first, int last, int &pn)
{
	resetCountDuplicatedItems();
	fstream inventory(inFileName, ios::in);

	for (int count = 0; count < TOTALINVENTORY; count++)
	{
		inventory >> productNumber[count] >> description[count] >>
			price[count] >> tax[count];


		if (productNumber[count] == pn)
		{

			for (int add = count + 1; add < TOTALINVENTORY; add++)
			{
				inventory >> productNumber[add] >> description[add] >>
					price[add] >> tax[add];

			}

			duplicatedTimes++; // Count only if the product number is repeated.
		}

	}


		if (duplicatedTimes > 1)
			throw DuplicateProduct(pn);


		last = TOTALINVENTORY - 1;
		int middle;
		int position = -1;
		bool found = false;

		while (!found && first <= last)
		{
			middle = (first + last) / 2;

			if (array[middle] == pn)
			{
				found = true;
				position = middle;
			}

			else if (array[middle] > pn)
				last = middle - 1;

			else
				first = middle + 1;

		}

		if (found == false)
			throw ProductNotFound(pn);

		inventory.close();

		return position;

}

/****************************************************************************
Function name:  verifyInputIsCorrect

Description:	This function determines if the user inputted an integer value
If the input is incorrect, then it will notify the user to try again. 

Input Parameters:  input.

****************************************************************************/
void CashRegister::verifyInputIsCorrect(int &input)
{

	do
	{
		cin >> input;

		if (cin.fail())
		{
			cout << "Your input is incorrect" << endl;
			cout << "Please, try again." << endl;
			cout << ">>> ";

			inputFail = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			inputFail = false;

	} while (inputFail == true);
}

/****************************************************************************
Function name:  overload operator >>

Description:	This function will process the cash register program by 
calling the object Time and open the output file to process the receipt.
It will search from the file Invent.dat to process the inventory and allow
the user to type the product number and the times of the product the customer
wants. The user will type in the cash register like: 11111 2. While the 11111
means the product number and 2 is the number of the products. The user will 
type an space between the product number and the times. It will process the
ouput file named "Receipt.out" in the following format:

Customer 1
pie-shells 2 @ 0.99 1.98
*** item 40012 not in inventory ***
laundry-soap 1 @ 3.60 3.60 TX
	Subtotal 5.58
	Tax 0.27
  Total 5.85

The following is possible input from the user and the expected output:
>>> 11111 4
>>> 33333 t (The program will ignore the "t" input ONLY). Therefore, the user
ONLY have to input the number of products again. Let's say 4 products.
Your input is incorrect
Please, try again.
>>> 4
>>> 44444 3 (The user can input the new product number with the number of times.)
>>> qwerty 4 (The program will ignore the product number AND the number of products.)
Your input is incorrect
Please, try again.
>>> 12345 7
>>> 0
Is another customer needs to be processed>(Y/N) >>
End of demonstration.
****************************************************************************/
istream & operator >> (istream& cin, CashRegister &inventory)
{

		ofstream receiptFile;
		receiptFile.open(inventory.outFileName, ios::out);

		// Open the file to read the contents and echo print it to the receipt.out file
		fstream inventoryFile(inventory.inFileName, ios::in);

		cout << "Reading and displaying the current inventory..." << endl;

		cout << "Product Number" << "\t" << left << setw(13) << setfill(' ') << "Product Description" << "\t" <<
			"Price" << "\t" << "Taxable?" << endl;
		cout << "--------------------------------------------------------\n";

		for (int count = 0; count < inventory.TOTALINVENTORY; count++)
		{
			inventoryFile >> inventory.productNumber[count] >> inventory.description[count] >>
				inventory.price[count] >> inventory.tax[count];

			cout << inventory.productNumber[count] << "\t\t" << left << setw(13) << setfill(' ') << inventory.description[count] << "\t\t" <<
				inventory.price[count] << "\t" << inventory.tax[count] << endl;
			cout << "--------------------------------------------------------\n";

			receiptFile << inventory.productNumber[count] << "\t" << left << setw(13) << setfill(' ') << inventory.description[count] << "\t" <<
				inventory.price[count] << "\t" << inventory.tax[count] << endl;

		}
		cout << "Completed reading and displaying the current inventory." << endl;
		cout << "There are " << inventory.TOTALINVENTORY << " items in the inventory." << endl;
		receiptFile << "------------------------------------------------------\n";
		inventoryFile.close();


		receiptFile << "Customer " << inventory.numberofCustomer << endl;

		receiptFile << setprecision(2) << fixed;

		// Notify the user of the type of input are required to execute the program.
		cout << "Enter the product ID and the number of products to be" << endl;
		cout << "sold separated by a space. (i.e. 12345 3). Press Enter" << endl;
		cout << "to add another product or press zero to end the " << endl;
		cout << "transaction for the customer" << endl;

	do
	{

		try
		{

			for (int count = 0; count < inventory.TOTALINVENTORY; count++)
			{
				cout << ">>> ";
				//Enter the product ID. or press 0 to end the transaction.
				inventory.verifyInputIsCorrect(inventory.productID);

				// Use the if/else statement to break the loop to ask the user for another customer without asking for the number of products.
				if (inventory.productID == 0)
					break;
				else
				{
					inventory.verifyInputIsCorrect(inventory.times);
					inventory.getNumberofTimes();
				}

				// search for the product number and record the location in results. Once the number is recorded, it will be used to search for
				// the product description and the product price.
				inventory.results = inventory.searchDuplicatedProduct(inventory.productNumber, 0, inventory.TOTALINVENTORY - 1, inventory.productID);



				receiptFile << inventory.description[inventory.results] << " " << inventory.times
					<< " @ " << inventory.price[inventory.results] << " ";

				if (inventory.tax[inventory.results] == 'T')
				{
					receiptFile << inventory.price[inventory.results] * inventory.times << " TX" << endl;
					inventory.totalTax += (inventory.price[inventory.results] * inventory.times) * inventory.taxes;
				}
				else
				{
					receiptFile << inventory.price[inventory.results] * inventory.times << endl;
				}

					
				// Keep a running subTotal, while the same customer is making purchases.
				inventory.subTotal += inventory.price[inventory.results] * inventory.times;
			}


		}
		catch (DuplicateProduct& exceptionDuplicate)
		{
			receiptFile << "*** item  " << exceptionDuplicate.getProductNumber() << " is a duplicated product ***\n";
		}
		catch (ProductNotFound& exceptionNotFound)
		{

			if (inventory.productID != 0)
			{
				receiptFile << "*** item " << exceptionNotFound.getProductNumber() << " not in inventory ***\n";
			}

		}
		catch (NotWithinRange& exceptionWrongRange)
		{
			receiptFile << "*** The number of products [" << exceptionWrongRange.getNumberofTimes() << "] is out of range ***\n";
		}

		inventory.total = inventory.subTotal + inventory.totalTax;

		// If the user press 0 during the product ID, then it will ask to process another customer.
		if (inventory.productID == 0)
		{
			cout << "Is another customer needs to be processed?(Y/N)>> ";
			cin >> inventory.anotherCustomer;
			while (toupper(*inventory.anotherCustomer) != 'N' && toupper(*inventory.anotherCustomer) != 'Y')
			{
				cout << "Your input " << inventory.anotherCustomer << " is incorrect" << endl;
				cout << "Is another customer needs to be processed?(Y/N)>> ";
				cin >> inventory.anotherCustomer;
			}

			if (toupper(*inventory.anotherCustomer) == 'Y')
			{
				receiptFile << "\tSubtotal " << inventory.subTotal << endl;
				receiptFile << "\tTax " << inventory.totalTax << endl;
				receiptFile << endl;
				receiptFile << "\tTotal " << inventory.total << endl;
				inventory.numberofCustomer++;
				receiptFile << "------------------------------------------------------\n";
				receiptFile << "Customer " << inventory.numberofCustomer << endl;

				// The subTotal, totalTax, and total resets to zero to reset the running totals.
				inventory.subTotal = 0;
				inventory.totalTax = 0;
				inventory.total = 0;
			}
			else
			{
				cout << "Have a nice day!" << endl;
				receiptFile << "\tSubtotal " << inventory.subTotal << endl;
				receiptFile << "\tTax " << inventory.totalTax << endl;
				receiptFile << endl;
				receiptFile << "\tTotal " << inventory.total << endl;
				receiptFile << "------------------------------------------------------\n";
			}


		}



	} while (toupper(*inventory.anotherCustomer) != 'N' || toupper(*inventory.anotherCustomer) == 'Y');

		receiptFile.close();


return cin;
}
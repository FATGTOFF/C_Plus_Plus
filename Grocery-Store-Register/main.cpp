/* This program uses the object oriented approach
to test and run the operation of a grocery store
checkout system. This program first reads in all
of the inventory information and will echo print
the information to the ouput file. The program
will prompt the user to begin inputting the order
for the first customer. Once the customer's order
is processed, the receipt will be printed to the 
ouput file. After the order is processed, the 
programwill ask the user if another customer is 
to be processed. This program uses the following 
files to run the program:

 - Header Files
	- CashRegister
	- DuplicatedProduct
	- FileNotFound
	- NotWithinRange
	- ProductNotFound
	- TestDriver
  - Implementation Files
	- CashRegister
	- DuplicatedProduct
	- FileNotFound
	- NotWithinRange
	- ProductNotFound
	- TestDriver
  - Necessary Input Data Files 
	- Invent.in (This file MUST contain 50 
	inventory items only or the program will
	not function correctly) It uses an array
	to read the inventory file. If the user
	wants to add or substract items from the
	inventory list, then the number of inventory
	in the CashRegister implementation file must
	be changed to the correct number of inventory.
  - Informative Data Files
	- TestPlan.txt (This file displays to the 
	tester the predetermined values to run the
	test to indicated if the output and the 
	exception is correct)
	- InputTest.txt (This file contains the pre-
	determined values to run the test of the program.
	If the file is not in the file, then the program
	will create a file with the predetermined values.
	However, in order to run the test, the user must
	quit the program and restart it. Then the file 
	will be available for use.)
  - Output Files
	- OutputTest.txt (This file will be created
	by the program, once the user select to run
	the test.)
	- Receipts.out (This file will be created 
	by the program, once the user select to run
	the program)
THis program will use exception classes to handle
the three possible input errors:
  - Duplicate product number in the inventory file.
  - Product number not in the inventory file.
  - Number of products (times) not in the specified
  range.
The main function consist of a switch statement 
for the user to choose among running the test
with predetermined values found in the TestDriver
implementation file, run the program and quit
the program.*/
#include <iostream>
#include "CashRegister.h"
#include "TestDriver.h"

using namespace std;


int main()
{

	int choice{ 0 };

	do
	{

		TestDriver test(choice);
		CashRegister inventory(choice);

		switch (choice)
		{
		case 1:
			cin >> test;
			break;

		case 2:
			cin >> inventory;
			break;

		case 3:
			cout << "Program ending." << endl;
			break;

		default:
			cout << "Your choice " << choice << " is incorrect." << endl;
		}

	} while (choice != 3);


	return 0;
}

//Implementation of the TestDriver class.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "TestDriver.h"
#include "CashRegister.h"
#include "DuplicateProduct.h"
#include "ProductNotFound.h"
#include "NotWithinRange.h"
#include "FileNotFound.h"
using namespace std;


/****************************************************************************
Default Constructor- it sets the data members to their values.
It calls the function readInitialTestFile to read the file to run the test.

Input Parameters:  int (passing by reference).
****************************************************************************/
TestDriver::TestDriver(int &choice) : CashRegister(choice)
{
	TOTALOFCONTENTS = 13; /*The number of lines the file "InputTest.txt" contains. If the value
						  is change, ensure it matches the number of lines in the "InputTest.txt".*/
	input1 = nullptr;
	input2 = nullptr;
	input3 = nullptr;

	input1 = new int[TOTALOFCONTENTS];
	input2 = new int[TOTALOFCONTENTS];
	input3 = new string[TOTALOFCONTENTS];

	element = 0;
	outPutfileName = "OutputTest.txt";
	inPutfileName = "InputTest.txt";

	readInitialTestFile(choice);

}

/****************************************************************************
Destructor- it de-allocates the memory from the array and return it back to
the computer memory.

****************************************************************************/
TestDriver::~TestDriver()
{
	delete[] input1;
	input1 = nullptr;

	delete[] input2;
	input2 = nullptr;

	delete[] input3;
	input3 = nullptr;
}

/****************************************************************************
Function name:  readInitialTestFile

Description:	It uses the try/catch method to test the
InputTest.txt by opening and closing the file (if successful) or will throw an exception
to let the user know the file will be created. It will let the user know that
even the test cannot be run, the program can still run.

Input Parameters:  int choice.

Return Type:  choice by passing reference
****************************************************************************/
void TestDriver::readInitialTestFile(int& choice)
{
	try
	{
		fstream inputFile(inPutfileName, ios::in);

		if (inputFile.fail())
		{
			throw FileNotFound(inPutfileName);
		}

		else
		{
			displayMenuWithTest(choice);
			for (int count = 0; count < TOTALOFCONTENTS; count++)
			{
				inputFile >> input1[count];
				inputFile >> input2[count];
				inputFile >> input3[count];
			}
			inputFile.close();
		}
	}
	catch (FileNotFound& exceptionFileNotFound)
	{
		cerr << "Error opening the file " << exceptionFileNotFound.getFileName() << endl;
		cerr << "The test cannot be executed. " << endl;
		cerr << "Creating the file " << exceptionFileNotFound.getFileName() << " ..." << endl;
		fstream createFile(exceptionFileNotFound.getFileName(), ios::out);
		{
			createFile << 11111 << '\t' << 2 << '\t' << "n/a" << endl;
			createFile << 99999 << '\t' << 3 << '\t' << "n/a" << endl;
			createFile << 33340 << '\t' << 3 << '\t' << "n/a" << endl;
			createFile << 22230 << '\t' << 4 << '\t' << "n/a" << endl;
			createFile << 0 << '\t' << 0 << '\t' << "y" << endl;
			createFile << 33430 << '\t' << 2 << '\t' << "n/a" << endl;
			createFile << 44450 << '\t' << -1 << '\t' << "n/a" << endl;
			createFile << 44450 << '\t' << 101 << '\t' << "n/a" << endl;
			createFile << 44450 << '\t' << 99 << '\t' << "n/a" << endl;
			createFile << 0 << '\t' << 0 << '\t' << "y" << endl;
			createFile << 11111 << '\t' << 2 << '\t' << "n/a" << endl;
			createFile << 12345 << '\t' << 2 << '\t' << "n/a" << endl;
			createFile << 0 << '\t' << 0 << '\t' << "n" << endl;
		}

		if (createFile.fail())
			cout << "Failed creating the file " << exceptionFileNotFound.getFileName() << endl;

		else
			cout << "The file " << exceptionFileNotFound.getFileName() << " was created." << endl;

		createFile.close();

		cerr << "You may continue to use the program without running the test. " << endl;
		cerr << "If you would like to run the test, restart the program." << endl;
		cerr << "Displaying the Menu without the Test option..." << endl;
		displayMenuWithOutTest(choice);
	}

}

/****************************************************************************
Function name:  overload operator >>

Description:	This function will test the cash register program by openning
the output file to process the test. It will use the file InputTest.txt to 
input the data and search from the file  Invent.dat to process the inventory 
and test the product number and the times of the product the customer wants. 
It will test the exception ProductNotFound, NotWithinRange, and 
DuplicatedProduct. It will use the try/catch throw method to process the 
exceptions. It will create the ouput file named "OutPutTest.txt".
****************************************************************************/
istream & operator >> (istream& cin, TestDriver &testDriver)
{

	fstream outputFile(testDriver.outPutfileName, ios::out);

	cout << "Running Test for Cash Register Program..." << endl;
	cout << "Using the file " << testDriver.inPutfileName << " for inputs" << endl;

	outputFile << "Running Test for Cash Register Program..." << endl;
	outputFile << "<<<OUTPUT>>> Customer " << testDriver.numberofCustomer << endl;
	outputFile << setprecision(2) << fixed;

	do
	{

		try
		{

			for (int count = 0; count < testDriver.TOTALINVENTORY; count++)
			{

				outputFile << "<<<INPUT>>> Enter the product ID.or press 0 to end the transaction >> ";
				testDriver.productID = testDriver.input1[testDriver.element];
				testDriver.element++;

				if (testDriver.input2[testDriver.element - 1] == 0)
				{
					cout << "Command Number " << testDriver.element << " started." << endl;
					cout << "Inputting >> [" << testDriver.productID << "]" << endl;
					cout << "Command Number " << testDriver.element << " completed." << endl;
				}
				else
				{
					cout << "Command Number " << testDriver.element << " started." << endl;
					cout << "Inputting >> [" << testDriver.productID << " " << 
						testDriver.input2[testDriver.element - 1] << "]" << endl;
					cout << "Command Number " << testDriver.element << " completed." << endl;
				}
				outputFile << testDriver.productID << endl;

				testDriver.results = testDriver.searchDuplicatedProduct(testDriver.productNumber, 0, testDriver.TOTALINVENTORY - 1, testDriver.productID);
				
				outputFile << "<<<INPUT>>> Input the amount number of the product " << testDriver.productID << " >> ";
				testDriver.times = testDriver.input2[testDriver.element - 1];
				outputFile << testDriver.times << endl;

				testDriver.getNumberofTimes();

				outputFile << "<<<OUTPUT>>> " << testDriver.description[testDriver.results] << " " << testDriver.times
					<< " @ " << testDriver.price[testDriver.results] << " ";

				if (testDriver.tax[testDriver.results] == 'T')
				{
					outputFile << testDriver.price[testDriver.results] * testDriver.times << " TX" << endl;
					testDriver.totalTax += (testDriver.price[testDriver.results] * testDriver.times) * testDriver.taxes;
				}
				else
				{
					outputFile << testDriver.price[testDriver.results] * testDriver.times << endl;
				}


				testDriver.subTotal += testDriver.price[testDriver.results] * testDriver.times;
			}


		}
		catch (DuplicateProduct& exceptionDuplicate)
		{
			outputFile << "<<<CATCH ERROR>>> *** item  " << exceptionDuplicate.getProductNumber() << " is a duplicated product ***\n";
			testDriver.productID = testDriver.input1[testDriver.element];			
		}
		catch (ProductNotFound& exceptionNotFound)
		{

			if (testDriver.productID != 0)
			{	
				outputFile << "<<<CATCH ERROR>>> *** item " << exceptionNotFound.getProductNumber() << " not in inventory ***\n";
			}
		
		}
		catch (NotWithinRange& exceptionWrongRange)
		{
			outputFile << "<<<CATCH ERROR>>> *** The number of products [" << exceptionWrongRange.getNumberofTimes() << "] is out of range ***\n";
		}

		testDriver.total = testDriver.subTotal + testDriver.totalTax;
		if (testDriver.productID == 0)
		{
			outputFile << "<<<INPUT>>> Is another customer needs to be processed?>> ";
			*testDriver.anotherCustomer = testDriver.input3[testDriver.element - 1][0]; // It uses only the first element of input3 variable.
			outputFile << testDriver.anotherCustomer << endl;

			if (toupper(*testDriver.anotherCustomer) == 'Y')
			{
				outputFile << "<<<OUTPUT>>> Subtotal " << testDriver.subTotal << endl;
				outputFile << "<<<OUTPUT>>> Tax " << testDriver.totalTax << endl;
				outputFile << "<<<OUTPUT>>> Total: " << testDriver.total << endl;
				testDriver.numberofCustomer++;
				outputFile << "------------------------------\n";
				outputFile << "<<<OUTPUT>>> Customer " << testDriver.numberofCustomer << endl;
				testDriver.subTotal = 0;
				testDriver.totalTax = 0;
				testDriver.total = 0;
			}
			else
			{
				outputFile << "<<<OUTPUT>>> Subtotal " << testDriver.subTotal << endl;
				outputFile << "<<<OUTPUT>>> Tax " << testDriver.totalTax << endl;
				outputFile << "<<<OUTPUT>>> Total: " << testDriver.total << endl;
				outputFile << "------------------------------\n";
			}


		}


	} while (toupper(*testDriver.anotherCustomer) != 'N');

	cout << "Creating a file named " << testDriver.outPutfileName << endl;
	cout << "Inputting the results of the test in " << testDriver.outPutfileName << endl;
	cout << "Testing is completed. You may see the results at " << testDriver.outPutfileName << " file" << endl;
	cout << "Returning to the main menu." << endl;
	outputFile << "Testing is completed. " << endl;
	outputFile.close();



	return cin;
}
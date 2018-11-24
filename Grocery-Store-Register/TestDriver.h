/****************************************************************************
Header for the TestDriver class.

Carlos Vazquez

This class tests the operation of a grocery store checkout system. This
program builds a data structure to contain information on all the products
available in the store. Then the program prints out the test results in the
OutPutTest.txt. Below is the test plan, which is located at TestPlan.txt:

Input File		Output File
				Running Test for Cash Register Program...
				Customer 1
11111			Throw Exception (Duplicated Error)
99999			Throw Exception (Not in inventory)
33340			Ask to input a number of sales
3				Spinach 3 @ 6.78 20.34 TX
22230			Ask to input number of sales
4				Cucumbers 4 @ 6.76 27.04
0				Ask to process another customer
y				Subtotal 47.38
				Tax 1.53
				Total 48.91
-------------------------------
				Customer 2
33430			Ask to input number of sales
2				Squash 2 @ 4.55 9.10 TX
44450			Ask to input number of sales
-1				Throw Exception (Out of Range 0-100)
44450			Ask to input number of sales
101				Throw Exception (Out of Range 0-100)
44450			Ask to input number of sales
99				Jam 99 @ 6.43 636.57
0				Ask to process another customer
y				Subtotal 645.67
				Tax 0.68
				Total 646.35
-------------------------------
				Customer 3
11111			Throw Exception (Duplicated Error)
12345			Throw Exception (Not in inventory)
0				Ask to process another customer
n				Subtotal 0.00
				Tax 0.00
				Total 0.00
-------------------------------
Testing is completed.

The class has the following constructors:
- A default constructor that dynamically allocates memory into the array
- A destructor construtor that ensures the memory is returned once it is
not needed it.
****************************************************************************/
#ifndef TESTDRIVER_H
#define TESTDRIVER_H

#include <iostream>
#include <string>
#include "CashRegister.h"
using namespace std;

class TestDriver : public CashRegister
{

private:

	int TOTALOFCONTENTS;	
	int *input1;
	int *input2;
	string *input3;
	int element; // Counter to count the commands executed during the test.
	string outPutfileName;
	string inPutfileName;

	void readInitialTestFile(int&);

public:

	TestDriver(int&);
	~TestDriver();

	//Friends.
	friend istream & operator >> (istream&, TestDriver &testDriver);
};
#endif
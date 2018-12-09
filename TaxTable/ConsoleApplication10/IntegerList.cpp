// Implementation file for the IntegerList class.
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include "IntegerList.h"
using namespace std;



IntegerList::IntegerList()
{

	int count = getTotalElements();


	fstream MyExcelFile("TaxTable.txt", ios::in);

	atLeast = new int[count];
	butLessThan = new int[count];
	single = new int[count];
	marriedFilingJointly = new int[count];
	marriedFilingSeparately = new int[count];
	headOfHousehold = new int[count];
	numElements = count;
	for (int row = 0; row < count; row++)
	{

		MyExcelFile >> atLeast[row] >> butLessThan[row]
			>> single[row] >> marriedFilingJointly[row] >> marriedFilingSeparately[row]
			>> headOfHousehold[row];

	}
	
	MyExcelFile.close();

}

IntegerList::~IntegerList()
{ 
	delete[] atLeast;
	atLeast = nullptr;

	delete[] butLessThan;
	butLessThan = nullptr;

	delete[] single;
	single = nullptr;

	delete[] marriedFilingJointly;
	marriedFilingJointly = nullptr;

	delete[] marriedFilingSeparately;
	marriedFilingSeparately = nullptr;

	delete[] headOfHousehold;
	headOfHousehold = nullptr;
}

//***********************************************************
// isValid member function.                                 *
// This private member functon returns true if the argument *
// is a valid subscript, or false otherwise.                *
//***********************************************************

bool IntegerList::isValid(int element) const
{
   bool status;

   if (element < 0 || element >= numElements)
      status = false;
   else
      status = true;
   return status;
}

int IntegerList::binarySearch(const int atLeast[], int size, int value) const
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (atLeast[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (atLeast[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half
	}

	return position + 1;
}

int IntegerList::searchNumber(int numID) const
{
	
	numID = numID - (numID % 50);
	return binarySearch(atLeast, numElements, numID);
}

//***********************************************************
// getElement member function.                              *
// Returns the value stored at the specified element.       *
// If an invalid subscript is passed, the program aborts.   *
//***********************************************************

int IntegerList::getAtLeast(int results) const
{
   if (isValid(results))
	   return atLeast[results];
   else
   {
      cout << "Error: Invalid subscript\n";
      exit(EXIT_FAILURE);
   }
}


int IntegerList::getButLessThan(int results) const
{
	if (isValid(results))
		return butLessThan[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

int IntegerList::getSingle(int results) const
{
	if (isValid(results))
		return single[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

int IntegerList::getMarriedFilingJointly(int results) const
{
	if (isValid(results))
		return marriedFilingJointly[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

int IntegerList::getMarriedFilingSeparately(int results) const
{
	if (isValid(results))
		return marriedFilingSeparately[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

int IntegerList::getHeadOfHousehold(int results) const
{
	if (isValid(results))
		return headOfHousehold[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}


int IntegerList::getTotalElements() const
{
	ifstream countElements;
	string elements;
	countElements.open("TaxTable.txt");
	int count{ 0 };

	while (getline(countElements, elements))
		count++;

	countElements.close();

	return count;

}
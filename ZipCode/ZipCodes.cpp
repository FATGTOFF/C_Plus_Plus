// Implementation file for the ZipCodes class.
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
#include "ZipCodes.h"
using namespace std;



ZipCodes::ZipCodes()
{

	//int count = getTotalElements();
	ifstream countElements;
	//string elements;
	countElements.open("ZipCodes.csv");
	int count{ 0 };

	while (getline(countElements, elements))
	{
		cout << elements << endl;
		count++;
	}
	//count++;

	countElements.close();

	//fstream MyExcelFile("ZipCodes.csv", ios::in);

	//atLeast = new int[count];
	//butLessThan = new string[count];
	//single = new string[count];
	////marriedFilingJointly = new int[count];
	////marriedFilingSeparately = new int[count];
	////headOfHousehold = new int[count];
	//numElements = count;
	//for (int row = 0; row < count; row++)
	//{

	//	MyExcelFile >> atLeast[row]; getline(MyExcelFile, butLessThan[row]);  getline(MyExcelFile, single[row]);
	//	//getline(MyExcelFile, butLessThan[row]);//MyExcelFile >> butLessThan[row];
	//	//MyExcelFile >> single[row];

	//	//cout << atLeast[row] << endl;
	//		//>> single[row] /*>> marriedFilingJointly[row] >> marriedFilingSeparately[row]
	//		//>> headOfHousehold[row]*/;

	//}

	//MyExcelFile.close();

}

ZipCodes::~ZipCodes()
{
	delete[] atLeast;
	atLeast = nullptr;

	delete[] butLessThan;
	butLessThan = nullptr;

	delete[] single;
	single = nullptr;

	//delete[] marriedFilingJointly;
	//marriedFilingJointly = nullptr;

	//delete[] marriedFilingSeparately;
	//marriedFilingSeparately = nullptr;

	//delete[] headOfHousehold;
	//headOfHousehold = nullptr;
}

//***********************************************************
// isValid member function.                                 *
// This private member functon returns true if the argument *
// is a valid subscript, or false otherwise.                *
//***********************************************************

bool ZipCodes::isValid(int element) const
{
	bool status;

	if (element < 0 || element >= numElements)
		status = false;
	else
		status = true;
	return status;
}
int ZipCodes::searchList(const string atLeast[], int size, string value) const
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < size && !found)
	{
		if (atLeast[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}
//int ZipCodes::binarySearch(const int atLeast[], int size, int value) const
//{
//	int first = 0,             // First array element
//		last = size - 1,       // Last array element
//		middle,                // Mid point of search
//		position = -1;         // Position of search value
//	bool found = false;        // Flag
//
//	while (!found && first <= last)
//	{
//		middle = (first + last) / 2;     // Calculate mid point
//		if (atLeast[middle] == value)      // If value is found at mid
//		{
//			found = true;
//			position = middle;
//		}
//		else if (atLeast[middle] > value)  // If value is in lower half
//			last = middle - 1;
//		else
//			first = middle + 1;           // If value is in upper half
//	}
//
//	return position + 1;
//}

int ZipCodes::searchNumber(int numID) const
{

	//numID = numID - (numID % 50);
	return searchList(elements, numElements, numID);
}

//***********************************************************
// getElement member function.                              *
// Returns the value stored at the specified element.       *
// If an invalid subscript is passed, the program aborts.   *
//***********************************************************

int ZipCodes::getAtLeast(int results) const
{
	if (isValid(results))
		return atLeast[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}


string ZipCodes::getButLessThan(int results) const
{
	if (isValid(results))
		return butLessThan[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

string ZipCodes::getSingle(int results) const
{
	if (isValid(results))
		return single[results];
	else
	{
		cout << "Error: Invalid subscript\n";
		exit(EXIT_FAILURE);
	}
}

//int ZipCodes::getMarriedFilingJointly(int results) const
//{
//	if (isValid(results))
//		return marriedFilingJointly[results];
//	else
//	{
//		cout << "Error: Invalid subscript\n";
//		exit(EXIT_FAILURE);
//	}
//}
//
//int ZipCodes::getMarriedFilingSeparately(int results) const
//{
//	if (isValid(results))
//		return marriedFilingSeparately[results];
//	else
//	{
//		cout << "Error: Invalid subscript\n";
//		exit(EXIT_FAILURE);
//	}
//}
//
//int ZipCodes::getHeadOfHousehold(int results) const
//{
//	if (isValid(results))
//		return headOfHousehold[results];
//	else
//	{
//		cout << "Error: Invalid subscript\n";
//		exit(EXIT_FAILURE);
//	}
//}


int ZipCodes::getTotalElements() const
{
	ifstream countElements;
	string elements;
	countElements.open("ZipCodes.csv");
	int count{ 0 };

	while (getline(countElements, elements))
	{
		//cout << elements << endl;
		count++;
	}
		//count++;

	countElements.close();

	return count;

}
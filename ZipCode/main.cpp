#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int binarySearch(const int[], int, int);

int main()
{
	
	string elements;
	int *atLeast{ nullptr };
	string *butLessThan{ nullptr };

	ifstream countNumbers;
	countNumbers.open("ZipCodes.csv");
	int count{ 0 };
	while (getline(countNumbers, elements))
		count++;
	countNumbers.close();

	fstream MyExcelFile("ZipCodes.csv", ios::in);

	atLeast = new int[count];
	butLessThan = new string[count];

	for (int row = 0; row < count; row++)
	{
		MyExcelFile >> atLeast[row]; 
		getline(MyExcelFile, butLessThan[row]);
	}

	int numID{ 0 };
	cout << "What is the number to search: ";
	cin >> numID;

	// Search for the number.
	int results = binarySearch(atLeast, count, numID);

	if (results == -1)
		cout << "The number does not exist.\n";
	else
	{
		string comma = butLessThan[results - 1];
		replace(comma.begin(), comma.end(), ',', ' ');
		cout << setw(5) << comma << "," << setfill('0') << setw(5) << atLeast[results - 1];
	}

	delete[] atLeast;
	atLeast = nullptr;

	delete[] butLessThan;
	butLessThan = nullptr;


	cout << endl;

	return 0;
}

int binarySearch(const int array[], int size, int value)
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (array[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half
	}
	return position + 1;
}
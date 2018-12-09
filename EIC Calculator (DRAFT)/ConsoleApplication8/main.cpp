#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int binarySearch(const int[], int, int);

int main()
{

	string test{ " " };
	int *atLeast{ nullptr };
	int *butLessThan{ nullptr };
	int *single{ nullptr };
	int *marriedFilingJointly{ nullptr };
	int *marriedFilingSeparately{ nullptr };
	int *headOfHousehold{ nullptr };
	int results{ 0 };
	int numID{ 0 };
	ifstream countNumbers;

	countNumbers.open("TaxTable.txt");
	int count{ 0 };

	while (getline(countNumbers, test))
		count++;

	countNumbers.close();
	


	fstream MyExcelFile("TaxTable.txt", ios::in);


	atLeast = new int[count];
	butLessThan = new int[count];
	single = new int[count];
	marriedFilingJointly = new int[count];
	marriedFilingSeparately = new int[count];
	headOfHousehold = new int[count];

	for (int row = 0; row < count; row++)
	{

		MyExcelFile >> atLeast[row] >> butLessThan[row]
			>> single[row] >> marriedFilingJointly[row] >> marriedFilingSeparately[row]
			>> headOfHousehold[row];

			//cout << atLeast[row] << "\t" << butLessThan[row]
			//	<< "\t" << single[row] << "\t" << marriedFilingJointly[row]
			//	<< "\t" << marriedFilingSeparately[row] << "\t" << headOfHousehold[row] << endl;

			
	}
	cout << endl;
	////////////BEGIN TEST ////////////////
	//int test1{ 2334 };
	//cout << test1 % 2 << endl;
	//cout << (test1 % 2) + test1 << endl;
	//cout << "The count is " << count << endl;
	//cout << "Enter the number you wish to search: ";
	//cin >> numID;

	int x{ 34279 };
	x = x - (x % 50);

	// Search for the number.
	results = binarySearch(atLeast, count, x);

	if (results == -1)
		cout << "The number does not exist.\n";
	else
	{
		cout << "The number is found at element " << results;
		cout << " in the array.\n";
		cout << atLeast[results -1] << "\t" << butLessThan[results -1]
			<< "\t" << single[results-1] << "\t" << marriedFilingJointly[results-1]
			<< "\t" << marriedFilingSeparately[results-1] << "\t" << headOfHousehold[results-1] << endl;
	}

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

	MyExcelFile.close();
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
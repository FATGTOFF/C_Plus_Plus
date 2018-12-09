#include <iostream>
#include <string>
#include "IntegerList.h"
using namespace std;


int main()
{
	
	IntegerList taxes;
	const int SIZE = taxes.getTotalElements();
	int results{ 0 };
	int numID{ 0 };

	string test{ "123-45-6789" };

	cout << test.at(1) << endl;
	
	cout << "The count is " << SIZE << endl;

	cout << "Enter the number you wish to search: ";
	cin >> numID;

	results = taxes.searchNumber(numID);

	cout << "The number is found at element " << results;
	cout << " in the array.\n";
	cout << taxes.getAtLeast(results - 1) << "\t" << taxes.getButLessThan(results - 1)
		<< "\t" << taxes.getSingle(results - 1) << "\t" << taxes.getMarriedFilingJointly(results - 1)
		<< "\t" << taxes.getMarriedFilingSeparately(results - 1) << "\t" << taxes.getHeadOfHousehold(results - 1) << endl;
	
	return 0;
}


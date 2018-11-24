// Specification file for the the IntegerList class.
#ifndef ZIPCODES_H
#define ZIPCODES_H
#include <string>
using namespace std;

class ZipCodes
{
private:

	string elements;
	int *atLeast;
	string *butLessThan;
	string *single;
	//int *marriedFilingJointly{ nullptr };
	//int *marriedFilingSeparately{ nullptr };
	//int *headOfHousehold{ nullptr };                // Pointer to the array.
	int numElements;           // Number of elements.
	//int binarySearch(const int atLeast[], int size, int value) const;
	int searchList(const string atLeast[], int size, string value) const;
	bool isValid(int) const;   // Validates subscripts.

public:
	ZipCodes();
	~ZipCodes();            // Destructor
	int searchNumber(int) const;

	int getAtLeast(int) const; // Returns an 
	string getButLessThan(int) const; // Returns an element
	string getSingle(int) const; // Returns an element
	//int getMarriedFilingJointly(int) const; // Returns an element
	//int getMarriedFilingSeparately(int) const; // Returns an element
	//int getHeadOfHousehold(int) const; // Returns an element
	int getTotalElements() const;


};
#endif
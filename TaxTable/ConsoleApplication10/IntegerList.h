// Specification file for the the IntegerList class.
#ifndef INTEGERLIST_H
#define INTEGERLIST_H


class IntegerList
{
private:
	int *atLeast{ nullptr };
	int *butLessThan{ nullptr };
	int *single{ nullptr };
	int *marriedFilingJointly{ nullptr };
	int *marriedFilingSeparately{ nullptr };
	int *headOfHousehold{ nullptr };                // Pointer to the array.
   int numElements;           // Number of elements.
   int binarySearch(const int atLeast[], int size, int value) const;
   bool isValid(int) const;   // Validates subscripts.

public:
	IntegerList();
   ~IntegerList();            // Destructor
   int searchNumber(int) const;

   int getAtLeast(int) const; // Returns an 
   int getButLessThan(int) const; // Returns an element
   int getSingle(int) const; // Returns an element
   int getMarriedFilingJointly(int) const; // Returns an element
   int getMarriedFilingSeparately(int) const; // Returns an element
   int getHeadOfHousehold(int) const; // Returns an element
   int getTotalElements() const;


};
#endif
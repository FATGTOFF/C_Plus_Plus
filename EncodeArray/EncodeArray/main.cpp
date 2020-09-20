//An integer number can be encoded as an array as follows.
//Each digit n of the number is represented by n zeros followed 
//by a 1. So the digit 5 is represented by 0, 0, 0, 0, 0, 1. The 
//encodings of each digit of a number are combined to form the 
//encoding of the number.So the number 1234 is encoded as the 
//array{ 0,1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 }.The first 0, 1 
//is contributed by the digit 1, the next 0, 0, 1 is contributed
//by the digit 2, and so on.There is one other encoding rule : if 
//the number is negative, the first element of the
//encoded array must be - 1, so - 201 is encoded as{ -1, 0, 0, 1, 1, 0, 1 }.
//Note that the 0 digit is represented by no zeros, i.e.there are two 
//consecutive ones!
//Write a function named encodeArray that takes an integer as an 
//argument and returns the encoded array.the function prototype is
//int * encodeArray(int n)
//
//Hints
//Use modulo 10 arithmetic to get digits of number
//Make one pass through the digits of the number to compute the 
//size of the encoded array.
//Make a second pass through the digits of the number to set 
//elements of the encoded array to 1.

#include <iostream>
#include <cstdlib> // For abs function.

int* encodeArray(int);
int arraySize(int);
void printArray(int*, int);

int main()
{
	int num{};

	std::cout << "Enter an integer to encode it: ";
	std::cin >> num;

	const int size{ arraySize(num) };
	int* pArray{ encodeArray(num) };

	printArray(pArray, size);

	//Or

	//std::cout << "{ ";
	//for (int count = 0; count < size; count++)
	//	std::cout << pArray[count] << " ";

	//std::cout << "}\n";

	// Deallocate the memory that was allocated under
	// the positiveNum function or negativeNum function (depending
	// on the user's input of the integer number. The positiveNum or
	// negativeNum function will be called from the encodeArray function.
	delete[] pArray;
	pArray = nullptr;

}

int* encodeArray(int num)
{
	const int size{ arraySize(num) };
	int absoluteValue{ std::abs(num) };

	// Dynamically allocate the array with the size
	// determined by the function arraySize.
	int* arrNum = nullptr;
	arrNum = new int[size];

	if (num < 0) // If the number is negative, an extra element is allocated
	{
		arrNum[0] = -1; // The first element must be -1 for negative numbers.

		// Set index of the encoded array from the second element to 1.
		for (int count = 1; count < size; count++)
			arrNum[count] = 1;
	}

	else
	{
		// Set index of the encoded array to 1.
		for (int count = 0; count < size; count++)
			arrNum[count] = 1;
	}

	int index{ size - 1 }; // Save the last index from the array.

	while (absoluteValue > 0)
	{
		int digit = absoluteValue % 10; // Use the modulus operator to determine a single digit.
		absoluteValue /= 10; // Obtain the other digits to the left of the single digit.

		// Get the difference between the index and the single
		// digit extracted to place the 0s (i.e. if the digit is 2,
		// then the array would be like 0, 0, 2.
		int diffMaxandMinElem{ index - digit };

		// Traverse the array from the last index to place the 0s in 
		// front of the array element. For example, the number 20103 would
		// be 0,0,1,1,0,1,1,0,0,0,1.
		for (int count = index - 1; count >= diffMaxandMinElem || digit == 0; count--)
		{
			// If the digit is 0, then break out of loop
			// to go to the next index of the array.
			if (digit == 0)
			{
				index = count;
				break;
			}

			else
			{
				arrNum[count] = 0;
				index = count - 1;
			}

		}

	}

	return arrNum; // Returns the pointer to the dynamically allocated array.

}

int arraySize(int num)
{
	// Make one pass through the digits of the number 
	// to compute the size of the encoded array.
	int countNumDigits{ 0 };
	int runningTotal{ 0 };
	int absoluteNum{ std::abs(num) };
	int size{ 0 };

	while (absoluteNum > 0)
	{
		int digit = absoluteNum % 10; // Use the modulus operator to determine a single digit.
		absoluteNum /= 10; // Obtain the other digits to the left of the single digit.
		runningTotal += digit; // Add the single digits (i.e. 1234 would equal 10).
		countNumDigits++; // Keep the count of the number of digits (i.e. 123 would count 3).
	}

	// If the num inputted by the user is positive
	if (num > 0)
	{
		size = runningTotal + countNumDigits;
	}

	else// An extra array element to place the -1 as the first element.
	{
		size = (runningTotal + countNumDigits) + 1;
	}

	return size;
}

void printArray(int* arrNum, int size)
{
	std::cout << "{ ";
	for (int count = 0; count < size; count++)
		std::cout << arrNum[count] << " ";

	std::cout << "}\n";
}

#include <iostream>

void reverseArray(int *, int *, int);
void printArray(int *, int);

int main()
{
	const int arraySize = 10;
	int original[arraySize]{23,55,65,11,77,56,43,79,22,34};
	int reverse[arraySize];

	std::cout << "Original order...\n";
	printArray(original, arraySize);
	std::cout << "Reverse order...\n";
	reverseArray(original, reverse, arraySize);
	printArray(reverse, arraySize);

	return 0;
}

/*
	The reverse function will use two parameters that are integer
	pointers to traverse the array from the original order to reverse
	order. It has two counters, which one counter will start at the 
	first element and the other counter will start at the last element
	of the array. The third parameter is the size of the array to be 
	used in the for loop to iterate the elements.
*/
void reverseArray(int *numbers, int* reverse, int arraySize)
{
	int countDec{ arraySize - 1};
	for (int countInc = 0; countInc < arraySize; countInc++)
	{
		*(reverse + countInc) = *(numbers + countDec);
		countDec--;
	}
}

void printArray(int *arr, int arraySize)
{
	for (int count = 0; count < arraySize; count++)
		std::cout << *(arr + count) << std::endl;
}
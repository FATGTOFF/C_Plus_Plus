#include <iostream>

void printArray(int*, int);
void reverseArray(int*, int*, int);

int main()
{
	const int arraySize{ 10 };
	int arrayNumbers[arraySize]{ 23,55,65,11,77,56,43,79,22,34 };
	int *original = &arrayNumbers[0];
	int *reverse = &arrayNumbers[arraySize - 1];


	std::cout << "Original Order:\n";
	printArray(arrayNumbers, arraySize);

	std::cout << "Reversing the Order...\n";
	reverseArray(original, reverse, arraySize);

	std::cout << "Reverse Order:\n";
	printArray(arrayNumbers, arraySize);

	return 0;
}
//
///*
//	The reverse function will use two parameters that are integer
//	pointers to traverse the array from the original order to reverse
//	order. It has two counters, which one counter will start at the 
//	first element and the other counter will start at the last element
//	of the array. The third parameter is the size of the array to be 
//	used in the for loop to iterate the elements.
//*/
void reverseArray(int *original, int* reverse, int arraySize)
{
	while (original <= reverse)
	{
		int temp = *original;
		*original = *reverse;
		*reverse = temp;
		original++;
		reverse--;
	}
}

void printArray(int *arr, int arraySize)
{
	for (int count = 0; count < arraySize; count++)
		std::cout << *(arr + count) << std::endl;
}
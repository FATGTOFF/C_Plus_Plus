/*
Write a menu based system in C++ that will take input from 
user for the following menu. (use array)
Press 1 To Enter Values In Array.
Press 2 To Read Array Elements.
Press 3 To Show Array Elements In Reverse Order.
Press 4 To Show Array Elements Which Are Multiples Of 3.
Press 5 To Show Sum Of All The Elements.
Press 6 To Exit.

Use switch statement for the menu based system.
Use pointers for option 2, 3, 4, 5.

*/

#include <iostream>
#include <cctype> // To be used with the toupper function.

// Function prototypes.
void displayMenu(int&);
void askNumberOfValues(int&);
void enterValuesInArray(int*, const unsigned int);
void readValuesInArray(const int*, const unsigned int);
void showArrayReverseOrder(const int*, const unsigned int);
void showMultiplesThrees(const int*, const unsigned int);
void sumAllTheElements(const int*, const unsigned int);

int main()
{
	int sizeOfArray{};
	int* arrayOfInt{ nullptr };
	int choice{};
	int sum{};
	char deleteArrayChoice{};
	bool keepLooping{ true };

	// Keep looping until the user hits option 6 to close the program.
	while (keepLooping)
	{
		displayMenu(choice);

		switch (choice)
		{
			case 1:
				if (sizeOfArray == 0)
				{
					askNumberOfValues(sizeOfArray);
					arrayOfInt = new int[sizeOfArray];
				}
				else
				{
					std::cout << "This option will override the current array.\n";
					std::cout << "Do you wish to continue (Y/N)?: ";
					std::cin >> deleteArrayChoice;

					if (std::toupper(deleteArrayChoice) == 'Y')
					{
						delete[] arrayOfInt;
						arrayOfInt = nullptr;
						sizeOfArray = 0;

						askNumberOfValues(sizeOfArray);
						arrayOfInt = new int[sizeOfArray];
					}
					else
					{
						break;
					}
					
				}

				enterValuesInArray(arrayOfInt, sizeOfArray);
				keepLooping = true;
				break;

			case 2:
				readValuesInArray(arrayOfInt, sizeOfArray);
				keepLooping = true;
				break;

			case 3:
				showArrayReverseOrder(arrayOfInt, sizeOfArray);
				keepLooping = true;
				break;

			case 4:
				showMultiplesThrees(arrayOfInt, sizeOfArray);
				keepLooping = true;
				break;

			case 5:
				sumAllTheElements(arrayOfInt, sizeOfArray);
				keepLooping = true;
				break;

			case 6:
				std::cout << "Closing the program...\n";
				keepLooping = false;
				break;

			default:
				std::cout << "Please choose between 1 and 6.\n";
				keepLooping = true;
		}
	}

	delete[] arrayOfInt;
	arrayOfInt = nullptr;

	return 0;
}

void displayMenu(int& choice)
{
	std::cout << "\n            Menu Based Array\n";
	std::cout << "-----------------------------------------\n";
	std::cout << "1) Enter Values in Array\n";
	std::cout << "2) Read Array Elements\n";
	std::cout << "3) Display Array in Reverse Order\n";
	std::cout << "4) Display Array Elements in Multiple of 3s.\n";
	std::cout << "5) Display the Sum of the Elements in Array.\n";
	std::cout << "6) Exit the program\n\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;
}

void askNumberOfValues(int& numOfValues)
{
	std::cout << "Enter the number of values in the array: ";
	std::cin >> numOfValues;
}

void enterValuesInArray(int* arrayOfInt, const unsigned int sizeOfArray)
{
	for (unsigned int count = 0; count < sizeOfArray; count++)
	{
		std::cout << "Element number " << count + 1 << " : ";
		std::cin >> *(arrayOfInt + count);
	}
}

void readValuesInArray(const int* arrayOfInt, const unsigned int sizeOfArray)
{
	if (sizeOfArray == 0)
	{
		std::cout << "Array is empty, first enter data in array.\n";
	}
	else
	{
		std::cout << "The array elements are...\n";
		for (unsigned int count = 0; count < sizeOfArray; count++)
		{
			std::cout << "Element number " << count + 1 << " : "
				<< *(arrayOfInt + count) << std::endl;
		}
	}

}

void showArrayReverseOrder(const int* arrayOfInt, const unsigned int sizeOfArray)
{
	if (sizeOfArray == 0)
	{
		std::cout << "Array is empty, first enter data in array.\n";
	}
	else
	{
		std::cout << "The reversed array elements are...\n";
		for (int count = sizeOfArray - 1; count > -1; count--)
		{
			std::cout << "Element number " << count + 1 << " : "
				<< *(arrayOfInt + count) << std::endl;
		}
	}
}

void showMultiplesThrees(const int* arrayOfInt, const unsigned int sizeOfArray)
{
	int countMulOf3s{ 0 };

	if (sizeOfArray == 0)
	{
		std::cout << "Array is empty, first enter data in array.\n";
	}
	else
	{
		std::cout << "Displaying elements with multiple of threes...\n";
		for (unsigned int count = 0; count < sizeOfArray; count++)
		{
			if (*(arrayOfInt + count) % 3 == 0)
			{
				std::cout << "Element number " << count + 1 << " : "
					<< *(arrayOfInt + count) << std::endl;
				countMulOf3s++;
			}
		}

		if (countMulOf3s == 0)
		{
			std::cout << "No elements with multiple of threes in the array\n";
		}
		
	}
}

void sumAllTheElements(const int* arrayOfInt, const unsigned int sizeOfArray)
{
	int sum{};

	if (sizeOfArray == 0)
	{
		std::cout << "Array is empty, first enter data in array\n";
		return;
	}
	else
	{
		for (unsigned int count = 0; count < sizeOfArray; count++)
		{
			sum += *(arrayOfInt + count);
		}
	}

	std::cout << "The sum of all elements in the array is: " << sum << std::endl;

}

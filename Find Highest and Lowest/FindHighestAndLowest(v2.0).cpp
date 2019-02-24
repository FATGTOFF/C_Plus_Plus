#include <iostream>
#include <cctype>

//Function Prototypes.
void inputNumOfPancakes(int[], int);
void findHighest(int[], int, int, int);
void findLowest(int[], int, int, int);

int main()
{
	//Declare the variables.
	const int SIZE{ 10 };
	int amount[SIZE] = { 0 };
	int pos{ 0 }, highest{ 0 }, lowest{ 0 };
	char tryAgain{ ' ' };
	bool keepLooping{true};

	while (keepLooping)
	{
		// Call the function for the user to input the values.
		inputNumOfPancakes(amount, SIZE);

		// Call the function to find the highest value.
		highest = amount[0]; // Initialize the variable with the first array element.
		findHighest(amount, SIZE, pos, highest);

		// Call the function to find the lowest value.
		lowest = amount[0]; // Initialize the variables with the first array element.
		findLowest(amount, SIZE, pos, lowest);

		std::cout << "Do you want to input the numbers again? >>>";
		std::cin >> tryAgain;

		if (toupper(tryAgain) == 'Y')
			keepLooping = true;

		else // If the answer is other than Y/y, then stop the loop.
			keepLooping = false;

	}

	return 0;
}

void inputNumOfPancakes(int amount[], int size)
{
	std::cout << "Please input 10 peoples pancakes consumed" << std::endl;
	for (int count = 0; count < size; count++)
	{
		std::cout << "Person number " << count + 1 << " >>>";
		std::cin >> amount[count];
	}
}

void findHighest(int amount[], int size, int pos, int highest)
{
	for (int count = 1; count < size; count++)
	{
		if (amount[count] > highest)
		{
			highest = amount[count];
			pos = count;
		}
	}

	std::cout << "The person who ate the most is person number " << pos + 1 << " with " <<
		highest << " pancakes" << std::endl;
}

void findLowest(int amount[], int size, int pos, int lowest)
{
	for (int count = 1; count < size; count++)
	{
		if (amount[count] < lowest)
		{
			lowest = amount[count];
			pos = count;
		}
	}

	std::cout << "The person who ate the least is person number " << pos + 1 << " with " <<
		lowest << " pancakes" << std::endl;
}

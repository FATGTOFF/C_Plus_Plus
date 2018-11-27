#include <iostream>
#include <random>
#include <cctype> // For use on toupper function.


//Function Prototypes.
void initialArray(int num[], int numElements);
void staticArray(const int num[], const int numElements);
void reverseArray(const int num[], const int numElements);
void searchList(const int num[], const int numElements, int value);
void sumNumber(const int num[], const int numElements);
int randomChoice(int min, int max);
void displayMenu(char &);

int main()
{

    // Declare and initialize the variables.
    bool tryAgain{ true };
    const int arrElements{ 10 };
    int findNumber{ 0 };
    int numbers[arrElements] = { 0 };
    char choice{ ' ' };


    initialArray(numbers, arrElements); // Call the function to display the array in the original order.


    while (tryAgain) // Use a while loop to continue until the user exit the program (tryAgain = false).
    {

	   displayMenu(choice);

	   // Use the if/else statements to ask the user for the options from the menu.
	   if (toupper(choice) == 'R')
	   {
		  reverseArray(numbers, arrElements);
		  staticArray(numbers, arrElements);
	   }


	   else if (toupper(choice) == 'A')
	   {
		  sumNumber(numbers, arrElements);
		  staticArray(numbers, arrElements);
	   }


	   else if (toupper(choice) == 'S')
	   {
		  std::cout << "What number would you like to find in the list?: ";
		  std::cin >> findNumber;
		  searchList(numbers, arrElements, findNumber);
		  staticArray(numbers, arrElements);
	   }

	   else if (toupper(choice) == 'E')
		  tryAgain = false; // Once the user selects E, set the variable to false to stop the loop.

    }


    return 0;
}

/*
The function initialArray uses two parameters, the num[] is for the array and the
size is for the number of elements in the array. The parameters are setup in main
by the user. The function uses a for-loop to iterate each element in the array,
while it will call the randomChoice function to fill every element with random
numbers. Then it will display the array list to the user on the screen.
*/
void initialArray(int num[], int size)
{
    std::cout << "Entering the following integer numbers(randomly):\n";
    for (int rows = 0; rows < size; rows++)
    {
	   std::cout << "Row # " << rows + 1 << " :";
	   num[rows] = randomChoice(60, 100);
	   std::cout << num[rows] << std::endl;
    }
}

/*
The function staticArray uses two parameters, the const num[] is for the array and the
const size is for the number of elements in the array. The parameters were setup in the
function initialArray by the user. This function is only use to display the original array
after the user makes the selection on the menu. The function uses a for-loop to iterate
each element in the array. Then it will display the array list to the user on the screen.
*/
void staticArray(const int num[], const int size)
{
    std::cout << "Displaying the original order of the array...\n";
    for (int rows = 0; rows < size; rows++)
    {
	   std::cout << "Row # " << rows + 1 << " :";
	   std::cout << num[rows] << std::endl;
    }
}

/*
The function reverseArray uses two parameters, the const num[] is for the array and the
const size is for the number of elements in the array. The parameters were setup in the
function initialArray by the user. This function is only use to display the reverse array.
The function uses a for-loop to iterate each element in the array from the last element
to the first element. Then it will display the array list to the user on the screen.
*/
void reverseArray(const int num[], const int size)
{
    std::cout << "Displaying the array in reverse...\n";
    for (int rows = size - 1; rows > -1; rows--)
    {
	   std::cout << "Row # " << rows + 1 << " :";
	   std::cout << num[rows] << std::endl;
    }
}

/*
The function searchList uses three parameters, the const num[] is for the array, the
const size is for the number of elements in the array and the int value is for the value
setup by the user to find a value in the element. The first two parameters were setup in the
function initialArray by the user.The function uses a for-loop to iterate each element in
to search for the value. If it is found, then it will notify the user of the location(s).
If the number is not found, then it will notify the user as well.
*/
void searchList(const int num[], const int size, int value)
{
    bool found{ false };

    for (int rows = 0; rows < size; rows++)
    {
	   if (num[rows] == value)
	   {
		  std::cout << "Found it on Row #" << rows + 1 << std::endl;
		  found = true;
	   }
    }

    if (found == false)
	   std::cout << "The number " << value << " was not found.\n";
}

/*
The function sumNumber uses two parameters, the const num[] is for the array, the
const size is for the number of elements in the array. The two parameters were setup in the
function initialArray by the user.The function uses a for-loop to iterate each element in
and maintain a running total. It will display the total to the user, if the user selects it
in the menu.
*/
void sumNumber(const int num[], const int size)
{
    int sum{ 0 };
    std::cout << "The sum of the elements on the list is : ";
    for (int rows = 0; rows < size; rows++)
	   sum += num[rows];

    std::cout << sum << std::endl;
}

/*
The function randomChoice uses two parameters, the int min and the int max.
The two parameters were setup inside the function body of the initialArray function by the
programmer.This function utilizes the C++ 11 library random to perform the calculations to
determine the random numbers.
*/
int randomChoice(int min, int max)
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.
    const int randNumber = distributionToss(generator);

    return randNumber;
}

/*
The function displayMenu uses one parameter by reference, the choice.
The menu will display to the user to make a selection and based on the selection
the user makes, the program will run according to the options. The choice is passed by
reference back to the main function.
*/
void displayMenu(char &choice)
{
    std::cout << "\nArray Generator\n\n"
	   << "[R]everse " << " [A]dd " << "[S]earch " << "[E]xit\n"
	   << "Please select an option:_";
    std::cin >> choice;
}

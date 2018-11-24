/*
"Write a program containing a function MatrixMultiplication 
that takes in a multidimensional array of integers and any 
other necessary information and outputs the result of 
multiplying every element in the array by 2. You can choose 
the dimensions for your multidimensional array as long as 
each dimension is greater than 1. The array should be 
initialized by filling it with random numbers between 1 and 
10."
*/

#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>

// Global constant to setup the array size across main and other functions.
const int MAXROWS{ 3 };
const int MAXCOLS{ 3 };

//Function Prototype
void MatrixMultiplication(int arr[][MAXCOLS]);
void RandomizeArrayNumbers(int arr[][MAXCOLS]);

int main()
{
    int arrayNumbers[MAXROWS][MAXCOLS];

    RandomizeArrayNumbers(arrayNumbers); // Call the function to initialized the array with random numbers.
    MatrixMultiplication(arrayNumbers);  // Call the function to display the arrays element multiplies by 2.

    return 0;
}

/*
This function uses a nested-for loops to go thru each element to multiply by 2.
Then, it will display the result in a matrix format.
*/
void MatrixMultiplication(int arr[][MAXCOLS])
{
    std::cout << "Displaying the " << MAXROWS << " x " << MAXCOLS << " array format\n";
    std::cout << "with random numbers multiplied by 2...\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  std::cout << std::right << std::setw(5) << arr[rows][cols] * 2;
	   }

	   std::cout << std::endl;
    }
}

/*
This function will use the random and chrono libraries to provide random numbers
from 1 to 10. Then it will use a nested-for loops to initiliazed each element
with the random number generated.
*/
void RandomizeArrayNumbers(int arrrnd[][MAXCOLS])
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionToss(1, 10); // Set the numbers for int.

    std::cout << "Displaying the " << MAXROWS << " x " << MAXCOLS << " array format\n";
    std::cout << "with random numbers...\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  arrrnd[rows][cols] = distributionToss(generator);
		  std::cout << std::right << std::setw(5) << arrrnd[rows][cols];
	   }
	   std::cout << std::endl;
    }
}

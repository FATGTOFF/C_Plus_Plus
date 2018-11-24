#include <iostream>

//Function Prototype.
double larger(double, double);

int main()
{
    const int SIZE{ 15 }; // Determine the size for the for loop.
    double largestNum{ 0.0 }, inputNum{ 0.0 };

    std::cout << "Please, enter 15 numbers.\n";
    largestNum = larger(inputNum, SIZE); //Call the function and return the largest number.

    std::cout << "The Largest Number is " << largestNum << "\n";

    return 0;
}

double larger(double inputNum, double SIZE)
{
    double maxNumber{ -9999 };

    for (int count = 0; count < SIZE; count++)
    {
	   std::cout << "Number #" << count + 1 << ": ";
	   std::cin >> inputNum;

	   if (inputNum > maxNumber)
		  maxNumber = inputNum;
    }

    return maxNumber;
}

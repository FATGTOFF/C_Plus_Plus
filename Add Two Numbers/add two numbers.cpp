#include <iostream>

int main()
{
    // Declare and initialize the variables.
    double num1{ 0 }, num2{ 0 };

    // Ask the user for their input.
    std::cout << "Enter two positive numbers and I will add them.\n";
    std::cout << "Number 1: ";
    std::cin >> num1;

    // Use the while loop to validate the user input is valid.
    // Ask the user to try again with their input.
    while (num1 < 0)
    {
	   std::cout << "The number " << num1 << " is not positive number.\n";
	   std::cout << "Try again.\n";
	   std::cout << "Number 1: ";
	   std::cin >> num1;
    }

    std::cout << "Number 2: ";
    std::cin >> num2;

    // Use the while loop to validate the user input is valid.
    // Ask the user to try again with their input.
    while (num2 < 0)
    {
	   std::cout << "The number " << num2 << " is not positive number.\n";
	   std::cout << "Try again.\n";
	   std::cout << "Number 2: ";
	   std::cin >> num2;
    }

    // Output the result.
    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;

    return 0;
}

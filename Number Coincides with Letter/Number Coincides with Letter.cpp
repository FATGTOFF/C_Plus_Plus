#include <iostream>
#include <cctype> // For toupper function.

int main()
{
    const int SIZE{ 26 };
    int number{ 0 };
    char tryAgain{ 'Y' };
    char alphabet[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F',
	   'G', 'H', 'I', 'J', 'K',
	   'L', 'M', 'N', 'O', 'P', 'Q',
	   'R', 'S', 'T', 'U', 'V', 'W',
	   'X', 'Y', 'Z' };

    do
    {

	   std::cout << "ABC 123\n";
	   std::cout << "Select the number that coincides with the alphabet.\n";
	   std::cout << "For example, the number 7 should display the letter G.\n";

	   std::cin >> number;
	   while (number < 0 || number > SIZE)
	   {
		  std::cout << "Your input " << number << " is not valid\n";
		  std::cout << "Try again\n";
		  std::cin >> number;
	   }
	   std::cout << alphabet[number - 1] << std::endl; // Arrays element begins with 0 (Off-by-one rule).

	   std::cout << "Would you like to try again?\n";
	   std::cin >> tryAgain;

    } while (toupper(tryAgain) == 'Y');


    return 0;
}

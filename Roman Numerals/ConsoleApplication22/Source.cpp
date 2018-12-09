#include <iostream>
#include <string>


int main()
{
    int user_input{ 0 };
    std::string ROMAN_NUM[20] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
	   "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX" };

    do
    {
	   std::cout << "Enter a number between 1-20. I will convert it to roman numerals." << std::endl;
	   std::cin >> user_input;
	   while (user_input < 0 || user_input > 20)
	   {
		  std::cout << "BETWEEN 1-20." << std::endl;
		  std::cout << "Enter a number between 1-20. I will convert it to roman numerals." << std::endl;
		  std::cin >> user_input;
	   }

	   if (user_input == 0) // If the user enters 0; then return to the OS to end the program.
		  return 0;
	   else
	   std::cout << "Roman numeral form of " << user_input << " is: " << ROMAN_NUM[user_input - 1] << std::endl;

    } while (user_input != 0);

    return 0;
}
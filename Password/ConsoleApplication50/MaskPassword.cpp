#include <iostream>
#include <string>
#include <windows.h>


int main()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    std::string password{ "" };

    std::getline(std::cin, password);

    while (password.size() != 4 || !isdigit(password.at(0)) || !isdigit(password.at(1))
	   || !isdigit(password.at(2)) || !isdigit(password.at(3)))
    {

	   for (unsigned int count = 0; count < password.size(); count++)
	   {
		  std::cout << "*";
	   }
	   std::cout << std::endl;


	   std::cout << "It must be number only\n";
	   std::cout << "Please ensure you enter a four digit number\n";
	   std::getline(std::cin, password);
    }
    

    for (unsigned int count = 0; count < password.size(); count++)
    {
	   std::cout << "*";
    }

    if (password == "1234")
	   std::cout << "\nWelcome...\n";

    else
	   std::cout << "\nIncorrect Password...\n";

    SetConsoleMode(hStdin, mode);

    return 0;
}
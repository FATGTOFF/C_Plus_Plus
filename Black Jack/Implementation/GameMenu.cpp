#include "GameMenu.h"

void GameMenu::programTitle()
{
	std::cout << "\t\t     ----------------------------------\n";
	std::cout << "\t\t         Welcome to Black Jack Game\n";
	std::cout << "\t\t     ----------------------------------\n";
	std::cout << std::endl;
}

void GameMenu::initialMenu(int &choice)
{
	std::cout << "\n\t\t\t=========MAIN MENU==========\n";
	std::cout << "\t\t\t----------------------------\n";
	std::cout << "\t\t\t1. Hit.\n";
	std::cout << "\t\t\t2. Stand.\n";
	std::cout << "\t\t\t3. Double Down.\n";
	std::cout << "\t\t\t4. Surrender\n";
	std::cout << "\t\t\t----------------------------\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;
}

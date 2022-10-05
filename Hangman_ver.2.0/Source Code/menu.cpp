#include <iostream>
#include <string>
#include <iomanip>
#include "Birds.h"
#include "Play.h"
#include "USABirds.h"
#include "KikiBirds.h"
#include "Menu.h"
#include "Dictionary.h"
#include <fstream>
#include <cctype>
#include <Windows.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds


Menu::Menu()
{

	//CreateDirectoryA("C:\\Users\\carlo_000\\Documents\\Visual Studio 2013\\Projects\\Hangman\\Hangman\\Uno", NULL);

	numofStates = 50;
	pos = 0;
	state = " ";
	statesFileName = " ";
	abreviatedState = new std::string[numofStates];
	fullState = new std::string[numofStates];
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	ci.bVisible = FALSE;
	ci.dwSize = 100;
	hWnd = GetConsoleWindow();
	flag = 0;
	notifyPressButton = "Press ENTER button to continue...";
	choice = 0;
	count = 3;
	waitPeriod = '.';
	tryAgain = ' ';
	salida = false;

	setStates();
	SetConsoleCursorInfo(outPut, &ci);
	SetConsoleTitleA("HANGMAN");
	MoveWindow(hWnd, 500, 100, 800, 500, TRUE);
}


Menu::~Menu()
{
	delete[] abreviatedState;
	abreviatedState = nullptr;

	delete[] fullState;
	fullState = nullptr;
}

void Menu::displayTitle() 
{
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(outPut, &ci);
	std::ifstream welcome;
	std::string elements;
	std::string Title = "hangmanWelcome.txt";
	welcome.open(Title);
	int count{ 0 };

	if (welcome.fail())
	{
		SetConsoleCursorPosition(outPut, goTo(10, 7));
		std::cout << "ERROR!: The file [" << Title << "] does not exist\n";
		SetConsoleCursorPosition(outPut, goTo(10, 8));
		std::cout << "Ensure the file [" << Title << "] is in the same folder as the\n";
		SetConsoleCursorPosition(outPut, goTo(10, 9));
		std::cout << "hangman.exe file\n";
		SetConsoleCursorPosition(outPut, goTo(10, 10));
		std::cout << "Press Enter to continue...\n";

	}
	else
	{
		SetConsoleCursorPosition(outPut, goTo(16, 7));
		std::cout << "Welcome to...\n";
		SetConsoleCursorPosition(outPut, goTo(0, 8));
		while (std::getline(welcome, elements))
		{
			std::cout << "\t\t" <<elements << std::endl;
		}
		SetConsoleCursorPosition(outPut, goTo(16, 15));
		std::cout << notifyPressButton << std::endl;
	}

	welcome.close();
}

void Menu::setStatesFileName(std::string st)
{
	statesFileName = st;
}

void Menu::setStates()
{
	std::fstream StatesList("States.txt", std::ios::in);

	if (StatesList)
	{
		for (int count = 0; count < numofStates; count++)
		{
			std::getline(StatesList, abreviatedState[count], '\t');
			std::getline(StatesList, fullState[count]);
		}
	}
	else
	{
		std::cerr << "Error opening the File [States.txt]\n"
			<< "Please, ensure the file is available.\n"
			<< "Closing the program...\n";
		return;
	}

	StatesList.close();
}

void Menu::menu()
{

	do
	{
		displayTitle();

		while (salida == false)
		{

			if (GetAsyncKeyState(VK_RETURN))
			{
				salida = true;
				ClearScreen(0, 0);
				std::cin.ignore();
				std::cin.clear();
				displayMainMenu();
			}

			else if (!GetAsyncKeyState(VK_RETURN))
			{
				SetConsoleCursorPosition(outPut, goTo(16, 15));
				if (flag ^= 1)
					WriteFile(outPut, "Press ENTER button to continue...",
						notifyPressButton.length(), &written, NULL);
				else
					WriteFile(outPut, "                                 ",
						notifyPressButton.length(), &written, NULL);

				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}

		}

		ClearScreen(0, 0);
		displayMainMenu();
		InputNumberOnly(choice, 48, 17);
		ClearScreen(0, 0);
		if (choice == 1)
		{
			ClearScreen(0, 0);
			USABirds birds;

			Play hangman(birds.getWord());
			std::cin >> hangman;
			displayCountdownTimer(5, 25, 17);
			ClearScreen(0, 0);
		}

		else if (choice == 2)
		{
			displaySubMenu();
			InputNumberOnly(choice, 48, 15);
			if (choice == 1)
			{
				ClearScreen(0, 0);
				displayStates();
				displayCountdownTimer(20, 25, 50);
				ClearScreen(0, 0);

			}

			else if (choice == 2)
			{
				ClearScreen(0, 0);
				displayRules();
				displayCountdownTimer(10, 25, 17);
				ClearScreen(0, 0);

			}
			else if (choice == 3)
			{
				ClearScreen(0, 0);
				std::cout << "Type the abbreviated State(i.e. TX) that you would like to play: ";
				std::cin >> state;
				while (state.length() != 2)
				{
					std::cout << "Your input [" << state << "] is the wrong format.\n";
					std::cout << "You have [" << count << "] tries before I will show\n";
					std::cout << "the list of the states.\n";
					std::cout << "Please input in the abbreviated format (i.e TX).\n";
					std::cout << "Try again:\n";
					std::cin >> state;
					count--;

					if (count == 0)
					{
						ClearScreen(0, 0);
						displayStates();
						displayCountdownTimer(20, 25, 50);
						ClearScreen(0, 0);
						break;
					}

				}
				static char temp{ ' ' };
				for (int count = 0; count < 2; count++)
				{
					temp = toupper(state[count]);
					state[count] = temp;
				}

				searchStates(abreviatedState, fullState, numofStates, state);
				Birds birds(getStatesFileName());
				Play hangman(birds.getWord());
				std::cin >> hangman;
				displayCountdownTimer(5, 25, 17);
				ClearScreen(0, 0);

			}

			else if (choice == 4)
			{
				ClearScreen(0, 0);
			}

		}

		else if (choice == 3)
		{
			KIKIBirds birds;
			Play hangman(birds.getWord());
			std::cin >> hangman;
			displayCountdownTimer(5, 25, 17);
			ClearScreen(0, 0);
		}

		else if (choice == 4)
		{
			Dictionary words;
			Play hangman(words.getWord());
			std::cin >> hangman;
			displayCountdownTimer(5, 25, 17);
			ClearScreen(0, 0);
		}

	} while (choice != 5);
	std::cout << "Program will close...\n";

}

void Menu::searchStates(const std::string aStates[], const std::string fState[], int numOfStates, std::string userInput)
{
	int count = 0;
	int position = -1;
	bool found = false;

	while (count < numOfStates && !found)
	{
		if (aStates[count] == userInput)
		{
			found = true;
			position = count;
		}
		count++;
	}

	if (found)
	{
		setStatesFileName(fState[position] + ".txt");
	}
	else
	{
		std::cout << "Could not find the State in the file.\n";
	}

}

void Menu::displayMainMenu()
{
	ci.bVisible = FALSE;
	SetConsoleCursorPosition(outPut, goTo(29, 5));
	std::cout << "   MAIN MENU\n\n";
	SetConsoleCursorPosition(outPut, goTo(29, 7));
	std::cout << "1.  USA Birds\n";
	SetConsoleCursorPosition(outPut, goTo(29, 9));
	std::cout << "2.  Birds Species by State\n";
	SetConsoleCursorPosition(outPut, goTo(29, 11));
	std::cout << "3.  Birds from Kiki's Book\n";
	SetConsoleCursorPosition(outPut, goTo(29, 13));
	std::cout << "4.  Dictionary words\n";
	SetConsoleCursorPosition(outPut, goTo(29, 15));
	std::cout << "5.  Exit the program\n";
	SetConsoleCursorPosition(outPut, goTo(29, 17));
	std::cout << "Enter your choice: ";
}

void Menu::displaySubMenu()
{
	SetConsoleCursorPosition(outPut, goTo(29, 5));
	std::cout << "   BIRDS SPECIES BY STATE\n\n";
	SetConsoleCursorPosition(outPut, goTo(29, 7));
	std::cout << "1.  Display the list of the States\n";
	SetConsoleCursorPosition(outPut, goTo(29, 9));
	std::cout << "2.  Rules of the Game\n";
	SetConsoleCursorPosition(outPut, goTo(29, 11));
	std::cout << "3.  Choose a State to play\n";
	SetConsoleCursorPosition(outPut, goTo(29, 13));
	std::cout << "4.  Return to the main Menu\n";
	SetConsoleCursorPosition(outPut, goTo(29, 15));
	std::cout << "Enter your choice: ";
}

void Menu::displayRules()
{
	SetConsoleCursorPosition(outPut, goTo(27, 5));
	std::cout << "   RULES OF THE GAME\n\n";
	SetConsoleCursorPosition(outPut, goTo(27, 7));
	std::cout << "1.  You have 5 chances to play\n";
	SetConsoleCursorPosition(outPut, goTo(27, 9));
	std::cout << "2.  All characters are lowercase\n";
	SetConsoleCursorPosition(outPut, goTo(27, 11));
	std::cout << "3.  The character '-' and '_' are allowed\n";
	SetConsoleCursorPosition(outPut, goTo(27, 13));
	std::cout << "4.  '-' is for hyphenate words and '_' is for space\n";
	SetConsoleCursorPosition(outPut, goTo(27, 15));
	std::cout << "5.  Enjoy!!!" << std::endl;
}

void Menu::displayCountdownTimer(int time, short xCoord, short yCoord) const
{
	for (int count = time; count > 0; count--)
	{
		ClearScreen(xCoord, yCoord);
		std::cout << count << " seconds left to display";
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		ClearScreen(xCoord, yCoord);

	}

}

void Menu::ClearScreen(short xCoord, short yCoord) const
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { xCoord, yCoord };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

std::string Menu::getStatesFileName() const
{
	return statesFileName;
}

void Menu::InputNumberOnly(int &choice, short xCoord, short yCoord) 
{

	while ((std::cin >> choice).fail() || std::cin.peek() != '\n')
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
		{
			continue;		
			std::cin >> choice;
		}

		while (GetAsyncKeyState(VK_RETURN))
		{
			ClearScreen(xCoord, yCoord);
			SetConsoleCursorPosition(outPut, goTo(xCoord, yCoord));
		}

	}

}

void Menu::displayStates() const
{
	for (int count = 0; count < numofStates; count++)
	{
		std::cout << abreviatedState[count] << "\t" << fullState[count] << std::endl;
	}

}

COORD Menu::goTo(short x, short y)
{
	xCoord = x;
	yCoord = y;

	return{ xCoord, yCoord };
}
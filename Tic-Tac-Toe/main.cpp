#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // For rand and srand function.
#include <ctime> // For the time function.
#include <Windows.h> // Need it for he Sleep function and clear screen.
using namespace std;

//Global Constants.
const int ROWS = 3;
const int COLS = 3;

// Function prototype.
void showTable(const char num[][COLS], char);
void InputNumberOnly(int &num, int player);
void InputNumberOnly(int &num);
void validateMenuSelection(int choice);
void player1Turn(char table[][COLS], char rows, int &choice, int &player);
void player2Turn(char table[][COLS], char rows, int &choice, int &player);
void computer1Turn(char table[][COLS], char rows, int &choice, int &player);
void computer2Turn(char table[][COLS], char rows, int &choice, int &player);
void determineWinner(char table[][COLS], char rows, int &win);
void notifyWinner(int player, int win);
void initialMenu(int& choice);
void programTitle();
char validatetryAgain(char);
void ClearScreen(); // Windows API function to clear the screen.

int main()
{

	int player = 1;
	int choice = 0;
	int menuChoice = 0;
	const int minChoice = 1;
	const int maxChoice = 4;
	int win = -1;
	char table[ROWS][COLS] = { { '1', '2', '3' },
	{ '4', '5', '6' },
	{ '7', '8', '9' } };


	programTitle();


	do
	{
		initialMenu(menuChoice);
		if (menuChoice < minChoice || menuChoice > maxChoice)
			validateMenuSelection(menuChoice);

	} while (menuChoice < minChoice || menuChoice > maxChoice);

    do
    {

	   ClearScreen();
	   programTitle();
			

	   switch (menuChoice)
	   {

	   case 1:
	   {
		  showTable(table, ROWS);
		  if (player == 1)
				player1Turn(table, ROWS, choice, player);

		  else
		  {
				cout << "It is the Computer's Turn\n";
				computer2Turn(table, ROWS, choice, player);
				Sleep(1500);
		  }

	   }
	   break;

	   case 2:
	   {
		  showTable(table, ROWS);
		  if (player == 1)
				player1Turn(table, ROWS, choice, player);

		  else
				player2Turn(table, ROWS, choice, player);
	   }
	   break;

	   case 3:
	   {
		  showTable(table, ROWS);
		  if (player == 1)
		  {
				cout << "It is Player " << player << " turn\n";
				computer1Turn(table, ROWS, choice, player);
				Sleep(1500);
		  }

		  else
		  {
				cout << "It is Player " << player << " turn\n";
				computer2Turn(table, ROWS, choice, player);
				Sleep(1500);
		  }

	   }
	   break;

	   }
						
	   determineWinner(table, ROWS, win);

    } while (win == -1 && menuChoice != maxChoice);

    showTable(table, ROWS);
    notifyWinner(player, win);

    cin.get();
    cout << "Press Enter to exit...\n";
    cin.get();

	return 0;
}


void showTable(const char num[][COLS], char rows)
{
	cout << "\t\t\t  ----------------------\n";
	for (int x = 0; x < rows; x++)
	{
		cout << "\t\t\t  |";
		for (int y = 0; y < COLS; y++)
		{
			cout << setw(4) << num[x][y] << "  |";
		}
		cout << endl;
		cout << "\t\t\t  ----------------------\n";
	}
	
}

void InputNumberOnly(int &num, int player)
{
	while ((cin >> num).fail() || cin.peek() != '\n')
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
			cin >> num;
		}
		cout << "Invalid Move" << endl;
		cout << "Player " << player << " Enter a number: ";
	}
}

void InputNumberOnly(int &num)
{
	while ((cin >> num).fail() || cin.peek() != '\n')
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
			cin >> num;
		}
		cout << "Try again " << endl;
	}
}

/*****************************************************************
Definition of function gettryAgain. This function is called by   *
main and uses a reference variable to ask the user if they want  *
to try again.		    	                                     *
******************************************************************/
void gettryAgain(char &repeat)
{
	cout << "Would you like to try again? (Y/N)";
	cin >> repeat;
	while (toupper(repeat) != 'Y' && toupper(repeat) != 'N')
	{
		repeat = validatetryAgain(repeat);
	}
	cin.ignore();
}

/*****************************************************************
Definition of function validatetryAgain. This function is called *
by gettryAgain and uses the char parameter to validate that the  *
user do not enter a character that is not Y/y or N/n. This       *
function returns a char again value to gettryAgain function.     *
******************************************************************/
char validatetryAgain(char again)
{
	cout << "\nYour answer [" << again << "] is not valid.\n";
	cout << "Select Y/y for Yes or N/n for No.\n";
	cout << "Would you like to try again? (Y/N)";
	cin >> again;

	return again;
}

void player1Turn(char table[][COLS], char rows, int &choice, int &player)
{
	
		cout << "Player " << player << " Enter a number: ";
		InputNumberOnly(choice, player);

		switch (choice)
		{
		case 1:
			if (table[0][0] == 'X' || table[0][0] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[0][0] = 'X';
				player = 2;
			}
			break;

		case 2:
			if (table[0][1] == 'X' || table[0][1] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[0][1] = 'X';
				player = 2;
			}
			break;

		case 3:
			if (table[0][2] == 'X' || table[0][2] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[0][2] = 'X';
				player = 2;
			}
			break;

		case 4:
			if (table[1][0] == 'X' || table[1][0] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[1][0] = 'X';
				player = 2;
			}
			break;

		case 5:
			if (table[1][1] == 'X' || table[1][1] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[1][1] = 'X';
				player = 2;
			}
			break;

		case 6:
			if (table[1][2] == 'X' || table[1][2] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[1][2] = 'X';
				player = 2;
			}
			break;

		case 7:
			if (table[2][0] == 'X' || table[2][0] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[2][0] = 'X';
				player = 2;
			}
			break;

		case 8:
			if (table[2][1] == 'X' || table[2][1] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[2][1] = 'X';
				player = 2;
			}
			break;

		case 9:
			if (table[2][2] == 'X' || table[2][2] == 'O')
			{
				cout << "Invalid Move" << endl;
			}
			else
			{
				table[2][2] = 'X';
				player = 2;
			}
			break;

		default:
			if (choice <= 0)
				cout << "Invalid Move" << endl;
			break;

		}
		
}

void computer2Turn(char table[][COLS], char rows, int &choice, int &player)
{
	const int maxValue = 9;
	const int minValue = 1;
	srand((unsigned int)time(nullptr));
	//unsigned int seed = time(0); // Get the system time.
	//srand(seed); // Seed the random number generator.

	int random[ROWS][COLS] = { (rand() % (maxValue - minValue + 1)) + minValue };

	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLS; y++)
		{
			random[x][y] = (rand() % (maxValue - minValue + 1)) + minValue;
			choice = random[x][y];
		}
	}
	switch (choice)
	{
	case 1:
		if (table[0][0] == 'X' || table[0][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][0] = 'O';
			player = 1;
		}
		break;

	case 2:
		if (table[0][1] == 'X' || table[0][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][1] = 'O';
			player = 1;
		}
		break;

	case 3:
		if (table[0][2] == 'X' || table[0][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][2] = 'O';
			player = 1;
		}
		break;

	case 4:
		if (table[1][0] == 'X' || table[1][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][0] = 'O';
			player = 1;
		}
		break;

	case 5:
		if (table[1][1] == 'X' || table[1][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][1] = 'O';
			player = 1;
		}
		break;

	case 6:
		if (table[1][2] == 'X' || table[1][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][2] = 'O';
			player = 1;
		}
		break;

	case 7:
		if (table[2][0] == 'X' || table[2][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][0] = 'O';
			player = 1;
		}
		break;

	case 8:
		if (table[2][1] == 'X' || table[2][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][1] = 'O';
			player = 1;
		}
		break;

	case 9:
		if (table[2][2] == 'X' || table[2][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][2] = 'O';
			player = 1;
		}
		break;

	default:
		if (choice <= 0)
			cout << "Invalid Move" << endl;
		break;

	}
}

void computer1Turn(char table[][COLS], char rows, int &choice, int &player)
{
	const int maxValue = 9;
	const int minValue = 1;
	srand((unsigned int)time(nullptr));
	//unsigned int seed = time(0); // Get the system time.
	//srand(seed); // Seed the random number generator.

	int random[ROWS][COLS] = { (rand() % (maxValue - minValue + 1)) + minValue };

	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLS; y++)
		{
			random[x][y] = (rand() % (maxValue - minValue + 1)) + minValue;
			choice = random[x][y];
		}
	}
	switch (choice)
	{
	case 1:
		if (table[0][0] == 'X' || table[0][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][0] = 'X';
			player = 2;
		}
		break;

	case 2:
		if (table[0][1] == 'X' || table[0][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][1] = 'X';
			player = 2;
		}
		break;

	case 3:
		if (table[0][2] == 'X' || table[0][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][2] = 'X';
			player = 2;
		}
		break;

	case 4:
		if (table[1][0] == 'X' || table[1][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][0] = 'X';
			player = 2;
		}
		break;

	case 5:
		if (table[1][1] == 'X' || table[1][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][1] = 'X';
			player = 2;
		}
		break;

	case 6:
		if (table[1][2] == 'X' || table[1][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][2] = 'X';
			player = 2;
		}
		break;

	case 7:
		if (table[2][0] == 'X' || table[2][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][0] = 'X';
			player = 2;
		}
		break;

	case 8:
		if (table[2][1] == 'X' || table[2][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][1] = 'X';
			player = 2;
		}
		break;

	case 9:
		if (table[2][2] == 'X' || table[2][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][2] = 'X';
			player = 2;
		}
		break;

	default:
		if (choice <= 0)
			cout << "Invalid Move" << endl;
		break;

	}
}


void player2Turn(char table[][COLS], char rows, int &choice, int &player)
{
	cout << "Player " << player << " Enter a number: ";
	InputNumberOnly(choice, player);

	switch (choice)
	{
	case 1:
		if (table[0][0] == 'X' || table[0][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][0] = 'O';
			player = 1;
		}
		break;

	case 2:
		if (table[0][1] == 'X' || table[0][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][1] = 'O';
			player = 1;
		}
		break;

	case 3:
		if (table[0][2] == 'X' || table[0][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[0][2] = 'O';
			player = 1;
		}
		break;

	case 4:
		if (table[1][0] == 'X' || table[1][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][0] = 'O';
			player = 1;
		}
		break;

	case 5:
		if (table[1][1] == 'X' || table[1][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][1] = 'O';
			player = 1;
		}
		break;

	case 6:
		if (table[1][2] == 'X' || table[1][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[1][2] = 'O';
			player = 1;
		}
		break;

	case 7:
		if (table[2][0] == 'X' || table[2][0] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][0] = 'O';
			player = 1;
		}
		break;

	case 8:
		if (table[2][1] == 'X' || table[2][1] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][1] = 'O';
			player = 1;
		}
		break;

	case 9:
		if (table[2][2] == 'X' || table[2][2] == 'O')
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			table[2][2] = 'O';
			player = 1;
		}
		break;

	default:
		if (choice <= 0)
			cout << "Invalid Move" << endl;
		break;

	}
}

void initialMenu(int& choice)
{
	cout << "\n\t\t\t=========MAIN MENU==========\n";
	cout << "\t\t\t----------------------------\n";
	cout << "\t\t\t1. Single Player.\n";
	cout << "\t\t\t2. Multiplayer.\n";
	cout << "\t\t\t3. Demo.\n";
	cout << "\t\t\t4. Exit the program\n";
	cout << "\t\t\t----------------------------\n";
	cout << "Enter your choice: ";
	InputNumberOnly(choice);
	
}

void programTitle()
{
	cout << "\t\t     ----------------------------------\n";
	cout << "\t\t     Welcome to the Tic Tac Toe Program\n";
	cout << "\t\t       Player 1 (X)  ||  Player 2 (O)\n";
	cout << "\t\t     ----------------------------------\n";
	cout << endl;
}

void validateMenuSelection(int choice)
{
	cout << "=====The selection " << choice << " is not valid=====\n";
	cout << "=====Please, select a valid choice from the menu below=====\n";
}

void determineWinner(char table[][COLS], char rows, int &win)
{
	if (table[0][0] == table[0][1] && table[0][1] == table[0][2])
		win = 1;
	else if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
		win = 1;
	else if (table[0][0] == table[1][0] && table[1][0] == table[2][0])
		win = 1;
	else if (table[0][1] == table[1][1] && table[1][1] == table[2][1])
		win = 1;
	else if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
		win = 1;
	else if (table[0][2] == table[1][2] && table[1][2] == table[2][2])
		win = 1;
	else if (table[1][0] == table[1][1] && table[1][1] == table[1][2])
		win = 1;
	else if (table[2][0] == table[2][1] && table[2][1] == table[2][2])
		win = 1;
	else if (table[0][0] != '1' && table[0][1] != '2' && table[0][2] != '3' && table[1][0] != '4' &&

		table[1][1] != '5' && table[1][2] != '6' && table[2][0] != '7' && table[2][1] != '8' && table[2][2] != '9')
		win = 0;
	else
		win = -1;
}
void notifyWinner(int player, int win)
{
	
	if (win == 1)
	{
		if (player == 1)
		{
			player = 2;
		}
		else if (player == 2)
		{
			player = 1;
		}
		cout << "\aPlayer " << player << " win " << endl;

	}
	else
	{
		cout << "\aGame draw" << endl;
	}
}

void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

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

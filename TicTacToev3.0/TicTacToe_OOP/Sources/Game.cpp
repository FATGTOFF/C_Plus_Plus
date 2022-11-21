#include <iostream>
#include <Windows.h> // Need it for clear screen.
#include "..\Headers\Game.h"

Game::Game() : TicTacToe()
{
	player = 0;
	winner = false;
	tie = false;
	computer = false;
	initialMenu(choice);
}

void Game::turn()
{
	player = TicTacToe::getPlayer();

	if (player == 1 && choice == 1)
	{
		computer = false;
		TicTacToe::player1Turn(player, computer);
	}

	else if (player == 1 && choice == 2)
	{
		TicTacToe::player1Turn(player, computer);
	}

	else if (player == 1 && choice == 3)
	{
		TicTacToe::player1Turn(player, computer);
	}
	else if (player == 2)
		TicTacToe::player2Turn(player, computer);
}

void Game::displayTable()
{
	clearScreen();
	TicTacToe::displayTable(table);
}

bool Game::determineWinner()
{
	TicTacToe::determineWinner(winner, tie);
	if (tie && !winner)
		std::cout << "No winners\n";

	else if (winner)
		return winner;

	return winner;
}

void Game::initialMenu(USHORT &c)
{
	TicTacToe::initialMenu(c);
	//bool keepLooping = true;

	while (/*keepLooping ||*/ (!winner && !tie))
	{
		switch (c)
		{
		case 1:
			displayTable();
			computer = true;
			turn();
			break;

		case 2:
			displayTable();
			computer = false;
			turn();
			break;

		case 3:
			displayTable();
			computer = true;
			turn();
			break;

		case 4:
			std::cout << "Program ending.\n";
			//keepLooping = false;
			break;

		default:
			std::cout << "Your choice is not correct.\n";
		}
		winner = determineWinner();

	}
	displayTable();
	notifyWinner();
}

void Game::notifyWinner()
{
	TicTacToe::notifyWinner(player, winner);
}

void Game::clearScreen()
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
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

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
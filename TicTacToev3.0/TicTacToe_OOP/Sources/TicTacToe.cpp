#include <iostream>
#include <iomanip>
#include <random>
#include <thread> // Need it to use the thread
#include <chrono> // Need it to use it with conjunction of thread library
#include "..\Headers\TicTacToe.h"

USHORT TicTacToe::getPlayer() const
{
	return player;
}

void TicTacToe::prepareInitialTable()
{
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			table[row][col] = counter + '0'; // '0' is int 48.
			counter++;
		}
	}
}

void TicTacToe::programTitle()
{
	std::cout << "\t\t     ----------------------------------\n";
	std::cout << "\t\t     Welcome to the Tic Tac Toe Program\n";
	std::cout << "\t\t       Player 1 (X)  ||  Player 2 (O)\n";
	std::cout << "\t\t     ----------------------------------\n";
	std::cout << std::endl;
}

USHORT TicTacToe::randomNumber(USHORT min, USHORT max)
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<USHORT> distrib(min, max);

	const USHORT random = distrib(rng);

	return random;
}

TicTacToe::TicTacToe()
{
	minChoice = 1;
	maxChoice = 4;
	player = 1;
	choice = 0;
	counter = 1;
	nextPlayer = false;
#ifndef UNIT_TEST
	programTitle();
#endif // !UNIT_TEST
	prepareInitialTable();
}

void TicTacToe::player1Turn(USHORT p, bool computer)
{

	player = p;
	std::cout << "Player " << player << " Enter a number: ";

	if (!computer)
	{
		std::cin >> choice;
	}

	else if (computer)
	{
		choice = randomNumber(1, 9);
		std::this_thread::sleep_for(std::chrono::seconds(1)); //this_thread::sleep_for(1s);
		std::cout << choice << std::endl;
	}

	switch (choice)
	{
	case 1:
		if (table[0][0] == 'X' || table[0][0] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[0][0] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 2:
		if (table[0][1] == 'X' || table[0][1] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[0][1] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 3:
		if (table[0][2] == 'X' || table[0][2] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[0][2] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 4:
		if (table[1][0] == 'X' || table[1][0] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[1][0] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 5:
		if (table[1][1] == 'X' || table[1][1] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[1][1] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 6:
		if (table[1][2] == 'X' || table[1][2] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[1][2] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 7:
		if (table[2][0] == 'X' || table[2][0] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[2][0] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 8:
		if (table[2][1] == 'X' || table[2][1] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[2][1] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	case 9:
		if (table[2][2] == 'X' || table[2][2] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[2][2] = 'X';
			player = 2;
			nextPlayer = true;
		}
		break;

	default:
		if (choice <= 0)
			std::cout << "Invalid Move" << std::endl;
		break;

	}
}

void TicTacToe::player2Turn(USHORT p, bool computer)
{
	
	player = p;
	std::cout << "Player " << player << " Enter a number: ";

	if (!computer)
	{
		std::cin >> choice;
	}

	else if (computer)
	{
		choice = randomNumber(1,9);
		std::this_thread::sleep_for(std::chrono::seconds(1)); //this_thread::sleep_for(1s);
		std::cout << choice << std::endl;
	}

	switch (choice)
	{
	case 1:
		if (table[0][0] == 'X' || table[0][0] == 'O')
		{
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
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
			std::cout << "Invalid Move" << std::endl;
		}
		else
		{
			table[2][2] = 'O';
			player = 1;
		}
		break;

	default:
		if (choice <= 0)
			std::cout << "Invalid Move" << std::endl;
		break;

	}
}

void TicTacToe::displayTable(const char table1[][cols])
{
	std::cout << "\t\t\t  ----------------------\n";
	for (int x = 0; x < rows; x++)
	{
		std::cout << "\t\t\t  |";
		for (int y = 0; y < cols; y++)
		{
			std::cout << std::setw(4) << table1[x][y] << "  |";
		}
		std::cout << std::endl;
		std::cout << "\t\t\t  ----------------------\n";
	}
}

void TicTacToe::determineWinner(bool& winner, bool& tie)
{
	if (table[0][0] == table[0][1] && table[0][1] == table[0][2])
		winner = true;
	else if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
		winner = true;
	else if (table[0][0] == table[1][0] && table[1][0] == table[2][0])
		winner = true;
	else if (table[0][1] == table[1][1] && table[1][1] == table[2][1])
		winner = true;
	else if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
		winner = true;
	else if (table[0][2] == table[1][2] && table[1][2] == table[2][2])
		winner = true;
	else if (table[1][0] == table[1][1] && table[1][1] == table[1][2])
		winner = true;
	else if (table[2][0] == table[2][1] && table[2][1] == table[2][2])
		winner = true;
	else if (table[0][0] != '1' && table[0][1] != '2' && table[0][2] != '3' && table[1][0] != '4' &&

		table[1][1] != '5' && table[1][2] != '6' && table[2][0] != '7' && table[2][1] != '8' && table[2][2] != '9')
		tie = true;
	else
		winner = false;
}

void TicTacToe::notifyWinner(USHORT& p, bool winner)
{
	if (winner)
	{
		std::cout << "Player " << p << " win\n";
	}
	else
	{
		std::cout << "Game draw\n";
	}
}

void TicTacToe::initialMenu(USHORT& menuChoice)
{
	std::cout << "\n\t\t\t=========MAIN MENU==========\n";
	std::cout << "\t\t\t----------------------------\n";
	std::cout << "\t\t\t1. Single Player.\n";
	std::cout << "\t\t\t2. Multiplayer.\n";
	std::cout << "\t\t\t3. Demo.\n";
	std::cout << "\t\t\t4. Exit the program\n";
	std::cout << "\t\t\t----------------------------\n";
	std::cout << "Enter your choice: ";
	std::cin >> menuChoice;
}

bool TicTacToe::getNextPlayer() const
{
	return nextPlayer;
}
#include <iostream>
#include <random>
#include <iomanip>
#include "TicTacToe.h"

void TicTacToe::setPlayerOneChoice(int r, int c)
{
	row = r - 1;
	col = c - 1;
	board[row][col] = 'X';
}

void TicTacToe::setPlayerTwoChoice(int r, int c)
{
	row = r - 1;
	col = c - 1;
	board[row][col] = 'O';
}

int TicTacToe::randomNumber(int min, int max)
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.
	const int randNumber = distributionToss(generator);

	return randNumber;
}

void TicTacToe::checkWinner(char board[][size], bool &player1, bool &player2)
{
	bool foundWinner{ false };
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		std::cout << "Player 2 Won!!!\n";
		player2 = true;
	}

	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		std::cout << "Player 2 Won!!!\n";
		player2 = true;
	}

	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		std::cout << "Player 2 Won!!!\n";
		player2 = true;
	}

	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		std::cout << "Player Two Won!!!\n";
		player2 = true;
	}

	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		std::cout << "Player Two Won!!!\n";
		player2 = true;
	}

	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		std::cout << "Player Two Won!!!\n";
		player2 = true;
	}

	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		std::cout << "Player Two Won!!!\n"; 
		player2 = true;
	}

	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
	{
		std::cout << "Player One Won!!!\n";
		player1 = true;
	}

	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
	{
		std::cout << "Player Two Won!!!\n";
		player2 = true;
	}
	else if (choiceAvailable() == 0)
	{
		std::cout << "Is a tied!!!\n";
		player1 = false;
		player2 = false;
	}
}

void TicTacToe::validateUserInput(char b[][size], int &userRowSelect, int &userColSelect)
{

	while (b[userRowSelect - 1][userColSelect - 1] != '*')
	{
		std::cout << "Your Row choice " << userRowSelect << " and your Column\n";
		std::cout << "choice " << userRowSelect << " was already selected.\n";
		std::cout << "Try again.\n";
		std::cout << "Row: ";
		std::cin >> userRowSelect;
		std::cout << "Col: ";
		std::cin >> userColSelect;
	}
}

void TicTacToe::validatePosNumOnly(int &num)
{
	while (num < min || num > size)
	{
		std::cout << "Your input [" << num << "] is not a valid number.\n";
		std::cout << "Your input must be between " << min << " (inclusive) and " << size << " (inclusive).\n";
		std::cout << "Try Again: >>> ";
		std::cin >> num;
	}
}

TicTacToe::TicTacToe()
{
	for (unsigned int rows = 0; rows < size; rows++)
		for (unsigned int cols = 0; cols < size; cols++)
			board[rows][cols] = '*';

	min = 1;
	row = 0;
	col = 0;
}

void TicTacToe::displayBoard()
{
	std::cout << std::setw(58) << "\tCol\tCol\tCol \n";
	std::cout << std::setw(57) << "1 \t2 \t3 \n";
	for (unsigned int rows = 0; rows < size; rows++)
	{
		std::cout << std::setw(46) << "Row  "  << rows + 1 << '\t';
		for (unsigned int cols = 0; cols < size; cols++)
		{
			std::cout << board[rows][cols] << '\t';
		}

		std::cout << std::endl;

	}
	std::cout << std::endl;
}

void TicTacToe::playerOneChoice()
{
	int userRowSelect{};
	int userColSelect{};

	std::cout << "Player's 1 Turn\n";
	std::cout << "Row: ";
	std::cin >> userRowSelect;
	validatePosNumOnly(userRowSelect);
	std::cout << "Col: ";
	std::cin >> userColSelect;
	validatePosNumOnly(userColSelect);
	validateUserInput(board, userRowSelect, userColSelect);

	std::cout << "Player One selected row " << userRowSelect << " and col "
		<< userColSelect << std::endl;
	setPlayerOneChoice(userRowSelect, userColSelect);

}

void TicTacToe::playerTwoChoice()
{
	int userRowSelect{};
	int userColSelect{};

	std::cout << "Player's 2 Turn\n";
	std::cout << "Row: ";
	std::cin >> userRowSelect;
	validatePosNumOnly(userRowSelect);
	std::cout << "Col: ";
	std::cin >> userColSelect;
	validatePosNumOnly(userColSelect);
	validateUserInput(board, userRowSelect, userColSelect);

	std::cout << "Player Two selected row " << userRowSelect << " and col "
		<< userColSelect << std::endl;
	setPlayerTwoChoice(userRowSelect, userColSelect);
}

void TicTacToe::computerChoice()
{
	int compRowSelect{randomNumber(1,size)};
	int compColSelect{ randomNumber(1,size) };

	std::cout << "Computer's turn.\n";
	while (board[compRowSelect - 1][compColSelect - 1] != '*')
	{
		compRowSelect = randomNumber(1, size);
		compColSelect = randomNumber(1, size);
	}

	std::cout << "Computer selected row " << compRowSelect << " and col "
		<< compColSelect << std::endl;
	setPlayerTwoChoice(compRowSelect, compColSelect);

}

bool TicTacToe::checkWinner()
{
	bool foundWinner{false};
	bool player1{ false };
	bool player2{ false };
	checkWinner(board, player1, player2);

	if (player1 == true)
	{
		foundWinner = true;
	}
	else if (player2 == true)
	{
		foundWinner = true;
	}
	else if (choiceAvailable() == 0)
		foundWinner = true;

	else
		foundWinner = false;

	return foundWinner;
	
}

int TicTacToe::choiceAvailable()
{
	int countAvailableChoices{0};
	for (unsigned int rows = 0; rows < size; rows++)
	{
		for (unsigned int cols = 0; cols < size; cols++)
		{
			if (board[rows][cols] == '*')
			{
				countAvailableChoices++;
			}

		}
	}

	return countAvailableChoices;
}

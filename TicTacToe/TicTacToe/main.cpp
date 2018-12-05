#include <iostream>
#include "TicTacToe.h"

void programTitle();
int mainMenu();
void onePlayerGame(TicTacToe&);
void twoPlayerGame(TicTacToe&);

int main()
{
	enum menuChoice{ONE_PLAYER = 1, TWO_PLAYER, EXIT};

	programTitle();

	bool keepLooping{ true };
	while (keepLooping)
	{
		TicTacToe game{};
		const int choice{ mainMenu() };
		switch (choice)
		{
		case ONE_PLAYER:
			onePlayerGame(game);
			keepLooping = true;
			break;

		case TWO_PLAYER:
			twoPlayerGame(game);
			keepLooping = true;
			break;

		case EXIT:
			std::cout << "Program ending.\n";
			keepLooping = false;
			break;

		default:
			std::cout << "Your choice " << choice << " is incorrect.\n";
			std::cout << "Your choices are between " << ONE_PLAYER <<
				" and " << EXIT << std::endl;
		}
	}

	return 0;
}

void programTitle()
{
	std::cout << "\t\t\t\t\t  ----------------------------------\n";
	std::cout << "\t\t\t\t\t  Welcome to the Tic Tac Toe Program\n";
	std::cout << "\t\t\t\t\t  ----------------------------------\n\n";
}

int mainMenu()
{
	int choice{};
	std::cout << "\n\t\t\t\t\t     =========MAIN MENU==========\n";
	std::cout << "\t\t\t\t\t     ----------------------------\n";
	std::cout << "\t\t\t\t\t     1. One Player vs Computer.\n";
	std::cout << "\t\t\t\t\t     2. Two Players.\n";
	std::cout << "\t\t\t\t\t     3. Exit the program\n";
	std::cout << "\t\t\t\t\t     ----------------------------\n";
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	return choice;
}

void onePlayerGame(TicTacToe &game)
{
	bool keepLooping{ true };
	while (keepLooping)
	{
		game.displayBoard();
		game.playerOneChoice();
		bool winner{ game.checkWinner() };
		if (!winner)
			keepLooping = true;

		else if (game.choiceAvailable() == 0 || winner)
			break;

		game.displayBoard();
		game.computerChoice();
		winner = game.checkWinner();

		if (!game.checkWinner())
			keepLooping = true;

		else if (game.choiceAvailable() == 0 || winner)
			break;
	}

	game.displayBoard();
}

void twoPlayerGame(TicTacToe &game)
{
	bool keepLooping{ true };
	while (keepLooping)
	{
		game.displayBoard();
		game.playerOneChoice();

		bool winner{ game.checkWinner() };

		if (!winner)
			keepLooping = true;

		else if (game.choiceAvailable() == 0 || winner)
			break;

		game.displayBoard();
		game.playerTwoChoice();
		winner = game.checkWinner();

		if (!game.checkWinner())
			keepLooping = true;

		else if (game.choiceAvailable() == 0 || winner)
			break;
	}

	game.displayBoard();
}
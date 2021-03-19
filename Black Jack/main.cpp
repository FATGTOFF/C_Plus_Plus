#include <iostream>
#include "Player.h"
#include "DeckOfCards.h"


int main()
{
	int numOfPlayers{};
	std::cout << "Determine the number of players (1 - 7) >>> ";
	std::cin >> numOfPlayers;
	while (numOfPlayers < 1 || numOfPlayers > 7)
	{
		std::cout << "Input " << numOfPlayers << " is not correct\n";
		std::cout << "Determine the number of players (1 - 7) >>> ";
		std::cin >> numOfPlayers;
	}
	
	Player game(numOfPlayers);
	game.shuffleCards();
	game.displayCards();
	game.deal();
	game.displayTotalScores();

	int playersTurn{ 1 };
	int totalNumOfPlayers = numOfPlayers + 1; // +1 means that includes the dealer.
	int choice{};
	bool keepLooping{ true };
	while (playersTurn <= totalNumOfPlayers && keepLooping)
	{
		game.initialMenu(choice);

		if (choice == 5)
			playersTurn++;

		else
		{
			game.playerChoice(playersTurn, choice);
			game.displayCards();
			game.deal();
			game.displayTotalScores();
			if (game.getPlayerScores(playersTurn) > 21)
			{
				std::cout << "Player " << playersTurn << " busted\n";
				keepLooping = false;
			}
			else
				keepLooping = true;
		}

		//playersTurn++;
	}
	//game.initialMenu()


	
}
#include "Player.h"


void Player::deal()
{
	deal(numOfPlayers);
	displayInitialCards(numOfPlayers);
}

void Player::deal(int numPlayers)
{
	int nextCardToDeal = 0;
	for (int cardIssueNum = 0; cardIssueNum < 2; cardIssueNum++)
	{
		for (int numOfPlayer = 0; numOfPlayer < numPlayers; numOfPlayer++)
		{
			playerNum[numOfPlayer][cardIssueNum] = nameOfCardsShuffled[nextCardToDeal];
			playerScores[numOfPlayer][cardIssueNum] = arrOfCardScoresShuffled[nextCardToDeal];
			playerRunningTotalScores[numOfPlayer] += playerScores[numOfPlayer][cardIssueNum];
			nextCardToDeal++;

			if (DEBUG)
			{
				std::cerr << "\nA*** playerNum[numOfPlayer][cardIssueNum] = " <<
					playerNum[numOfPlayer][cardIssueNum] << std::endl;
			}

		}
	}
}

void Player::displayTotalScores(int numPlayers)
{
	for (int numOfPlayer = 0; numOfPlayer < numPlayers; numOfPlayer++)
	{
		playerRunningTotalScores[numOfPlayer] = 0;
		for (int cardIssueNum = 0; cardIssueNum < countDealtCards(numOfPlayer)/*2*/; cardIssueNum++)
		{
			playerRunningTotalScores[numOfPlayer] += playerScores[numOfPlayer][cardIssueNum];

			if (DEBUG)
			{
				printf("\nB*** countDealtCards(numOfPlayer) = %d \r\n", countDealtCards(numOfPlayer));
				printf("\nC*** numOfPlayer = %d \r\n", numOfPlayer);
				printf("\nD*** cardIssueNum = %d \r\n", cardIssueNum);
				printf("\nE*** playerScores[numOfPlayer][cardIssueNum] = %d \r\n", playerScores[numOfPlayer][cardIssueNum]);
				printf("\nF*** playerRunningTotalScores[numOfPlayer] = %d \r\n", playerRunningTotalScores[numOfPlayer]);
			}
		}

		if (numOfPlayer == (numPlayers - 1)) // If the player's number is the last one, that is the dealer.
		{
			std::cout << "\nDealer   Score: " << playerRunningTotalScores[numOfPlayer]
				<< std::endl;
		}
		else
		{
			std::cout << "\nPlayer " << numOfPlayer + 1 << " Score: " << playerRunningTotalScores[numOfPlayer]
				<< std::endl;
		}

	}
}

void Player::displayInitialCards(int numPlayers)
{
	int cardIssueNum{ 0 };

	for (int numOfPlayer = 0; numOfPlayer < numPlayers; numOfPlayer++)
	{

		if (numOfPlayer == (numPlayers - 1))// If the player's number is the last one, that is the dealer.
		{

			std::cout << std::right << "\nDealer's   cards dealt are:\n";
			printPlayerCards(numOfPlayer);
		}
		else
		{
			std::cout << std::right << "\nPlayer " << numOfPlayer + 1 << "'s cards dealt are:\n";
			printPlayerCards(numOfPlayer);
		}

		std::cout << std::endl;
	}
}

void Player::playerChoice(int numOfPlayer, int choice)
{
	int numPlayer = numOfPlayer - 1;

	switch (choice)
	{
		case HIT:

			if (nextCard >= TOTALNUMOFCARDS)
			{
				std::cout << "Ran out of cards in the stack\n";
			}

			else
			{
				playerNum[numPlayer][countDealtCards(numPlayer)] = nameOfCardsShuffled[nextCard];
				playerScores[numPlayer][countDealtCards(numPlayer) - 1] = arrOfCardScoresShuffled[nextCard];
				playerRunningTotalScores[numPlayer] += playerScores[numPlayer][countDealtCards(numPlayer) - 1];

				if (DEBUG)
				{
					printf("\nG*** numPlayer = %d \r\n", numPlayer);
					printf("\nH*** nextCard = %d \r\n", nextCard);
					printf("\nI*** countDealtCards(numPlayer) = %d \r\n", countDealtCards(numPlayer));

					std::cerr << "\nJ*** nameOfCardsShuffled[nextCard] = "
						<< nameOfCardsShuffled[nextCard] << std::endl;

					std::cerr << "\nK*** playerNum[numPlayer][countDealtCards(numPlayer) - 1] = " <<
						playerNum[numPlayer][countDealtCards(numPlayer) - 1] << std::endl;

					printf("\nL*** playerScores[numPlayer][countDealtCards(numPlayer) - 1] = %d \r\n",
						playerScores[numPlayer][countDealtCards(numPlayer) - 1]);

					printf("\nM*** playerRunningTotalScores[numPlayer] = %d \r\n",
						playerRunningTotalScores[numPlayer]);
				}


			}
			nextCard++;
			break;

		case STAND:

			numOfPlayer++;
			break;
	}
}

void Player::displayTotalScores()
{
	displayTotalScores(numOfPlayers);
}

//int Player::getPlayerScores() const
//{
//	return 0;
//}

int Player::countDealtCards(int numOfPlayer)
{
	int cardIssueNum = 0;
	while (playerNum[numOfPlayer][cardIssueNum] != "None")
	{
		cardIssueNum++;
	}
	return cardIssueNum;
}

void Player::printPlayerCards(int numOfPlayer)
{
	std::cout << std::endl;
	for (int cardIssueNum_counter = 0; cardIssueNum_counter < countDealtCards(numOfPlayer); cardIssueNum_counter++)
	{
		{
			std::cout << std::left << std::setw(2) << "|" << std::setw(17)
				<< playerNum[numOfPlayer][cardIssueNum_counter] << "|";
		}
	}
}

int Player::getPlayerScores(int numOfPlayer) const
{
	int numPlayer = numOfPlayer - 1;

	return playerRunningTotalScores[numPlayer];
}

Player::Player(int numPlayers)
{
	numOfPlayers = numPlayers + 1;
	nextCard = numOfPlayers * 2; // Total of cards dealt at initial deal.
	playerOptions = nullptr;
	playerOptions = new int[NUMOFPLAYEROPTIONS];
	for (int count = 0; count < NUMOFPLAYEROPTIONS; count++)
	{
		playerOptions[count] = 0;
	}
	playerCards = nullptr;
	playerCards = new int[TOTALNUMOFCARDS];
	dealerCards = nullptr;
	dealerCards = new int[TOTALNUMOFCARDS];

	for (int count = 0; count < TOTALNUMOFCARDS; count++)
	{
		playerCards[count] = 0;
		dealerCards[count] = 0;
	}

	playerRunningTotalScores = nullptr;
	playerRunningTotalScores = new int[numOfPlayers];

	playerScores = nullptr;
	playerScores = new int*[numOfPlayers];
	for (int row = 0; row < numOfPlayers; row++)
	{
		playerScores[row] = new int[TOTALNUMOFCARDS];
		playerRunningTotalScores[row] = 0;
		for (int col = 0; col < TOTALNUMOFCARDS; col++)
		{
			playerScores[row][col] = 0;
		 }
		//playerScores[count] = 0;
	}

	playerNum = nullptr;
	playerNum = new std::string*[numOfPlayers];
	for (int row = 0; row < numOfPlayers; row++)
	{
		playerNum[row] = new std::string[TOTALNUMOFCARDS];
		for (int col = 0; col < TOTALNUMOFCARDS; col++)
		{
			playerNum[row][col] = "None";
		}
	}

	programTitle(); //From GameMenu.h

}

Player::~Player()
{
	if (playerOptions != nullptr)
	{
		delete[] playerOptions;
		playerOptions = nullptr;
	}

	if (playerCards != nullptr)
	{
		delete[] playerCards;
		playerCards = nullptr;
	}

	if (dealerCards != nullptr)
	{
		delete[] dealerCards;
		dealerCards = nullptr;
	}

	if (playerRunningTotalScores != nullptr)
	{
		delete[] playerRunningTotalScores;
		playerRunningTotalScores = nullptr;
	}

	if (playerScores != nullptr)
	{
		for (int count = 0; count < numOfPlayers; count++)
		{
			delete[] playerScores[count];
		}

		delete[] playerScores;
		playerScores = nullptr;
	}

	if (playerNum != nullptr)
	{
		for (int count = 0; count < numOfPlayers; count++)
		{
			delete[] playerNum[count];
		}

		delete[] playerNum;
		playerNum = nullptr;
	}
}

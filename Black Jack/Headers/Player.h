#ifndef PLAYER_H
#define PLAYER_H
#include "DeckOfCards.h"
#include "GameMenu.h"
#include "Debug.h"
#include <iomanip>
#include <iostream>
#include <string>

class DeckOfCards;
class GameMenu;

class Player : public DeckOfCards, public GameMenu
{
	private:
		static const int NUMOFPLAYEROPTIONS = 5;
		enum Player_Options{HIT = 1, STAND, DOUBLE_DOWN, SPLIT, SURRENDER};
		enum NumOfPlayers{TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT};
		int numOfPlayers;
		int nextCard; // Counter to determine when is the next available card to deal when the player uses "HIT". 
		int *playerOptions;
		int *playerCards;
		int *dealerCards;
		int *playerRunningTotalScores;
		int **playerScores;
		std::string **playerNum;
		void deal(int);
		void displayTotalScores(int);
		void displayInitialCards(int);

		int countDealtCards(int);
		void printPlayerCards(int);


		

	public:
		//Player();
		Player(int);
		~Player();
		void deal();
		void playerChoice(int, int);
		void displayTotalScores();
		int getPlayerScores(int) const;
		//int getPlayerScores() const;
};
#endif


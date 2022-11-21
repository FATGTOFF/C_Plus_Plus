#ifndef GAME_H
#define GAME_H
#include "..\Headers\TicTacToe.h"

class Game : public TicTacToe
{
	private:
		USHORT player;
		USHORT choice;
		bool winner;
		bool tie;
		bool computer;

	public:
		Game();
		void turn();
		void displayTable();
		bool determineWinner();
		void initialMenu(USHORT&);
		void notifyWinner();
		void clearScreen();
};
#endif
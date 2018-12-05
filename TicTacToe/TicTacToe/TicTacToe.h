#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
private:

	static const int size{ 3 };
	char board[size][size];
	int min;
	int row;
	int col;

	void setPlayerOneChoice(int, int);
	void setPlayerTwoChoice(int, int);
	int randomNumber(int, int);
	void checkWinner(char[][size], bool&, bool&);
	void validateUserInput(char [][size], int&, int&);
	void validatePosNumOnly(int&);

public:
	TicTacToe();

	void displayBoard();
	void playerOneChoice();
	void playerTwoChoice();
	void computerChoice();
	bool checkWinner();
	int choiceAvailable();

};
#endif
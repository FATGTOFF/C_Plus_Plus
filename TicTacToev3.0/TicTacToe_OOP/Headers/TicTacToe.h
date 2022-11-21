#ifndef TICTACTOE_H
#define TICTACTOE_H

#define UNIT_TEST

typedef unsigned int short USHORT;

class TicTacToe
{
protected:
	USHORT choice;
	USHORT minChoice;
	USHORT maxChoice;
	static const USHORT rows = 3;
	static const USHORT cols = 3;
	bool nextPlayer;

	USHORT getPlayer() const;

private:
	USHORT player;
	USHORT counter;
	void programTitle();
	USHORT randomNumber(USHORT, USHORT);

#ifdef UNIT_TEST
public:
	void prepareInitialTable();
	char table[rows][cols];
#endif

#ifndef UNIT_TEST
private:
	void prepareInitialTable();
protected:
	char table[rows][cols];
#endif // !UNIT_TEST


public:
	TicTacToe();
	virtual void player1Turn(USHORT, bool);
	virtual void player2Turn(USHORT, bool);
	virtual void displayTable(const char[][cols]);
	virtual void determineWinner(bool&, bool&);
	virtual void notifyWinner(USHORT&, bool);
	virtual void initialMenu(USHORT&);
	bool getNextPlayer() const;

};
#endif

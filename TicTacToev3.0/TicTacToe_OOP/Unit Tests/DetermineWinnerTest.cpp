#include "pch.h"
#include <gtest/gtest.h>
#include "..\Tic-Tac-Toe-OOP\TicTacToe.cpp"


class TicTacToeTest : public::testing::Test
{
protected:
	TicTacToe* tictactoe;

public:
	TicTacToeTest()
	{
		tictactoe = new TicTacToe;
	}

	virtual ~TicTacToeTest()
	{
		delete tictactoe;
	}
};
/*
	The board layout to demonstrate the
	different ways the winner can be
	determined.

		  Column #
		 1   2   3

	Row# 1	 1 | 2 | 3
	Row# 2	 4 | 5 | 6
	Row# 3	 7 | 8 | 9
*/
TEST_F(TicTacToeTest, WinnerFound_Row1)
{
	tictactoe->table[0][0] = 'X';
	tictactoe->table[0][1] = 'X';
	tictactoe->table[0][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerFound_Row2)
{
	tictactoe->table[1][0] = 'X';
	tictactoe->table[1][1] = 'X';
	tictactoe->table[1][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerFound_Row3)
{
	tictactoe->table[2][0] = 'X';
	tictactoe->table[2][1] = 'X';
	tictactoe->table[2][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerFound_Col1)
{
	tictactoe->table[0][0] = 'X';
	tictactoe->table[1][0] = 'X';
	tictactoe->table[2][0] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerFound_Col2)
{
	tictactoe->table[0][1] = 'X';
	tictactoe->table[1][1] = 'X';
	tictactoe->table[2][1] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerFound_Col3)
{
	tictactoe->table[0][2] = 'X';
	tictactoe->table[1][2] = 'X';
	tictactoe->table[2][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

/*
	This test check if the winner can be
	accross from the top left corner to
	the bottom right corner (1,5,9)
*/
TEST_F(TicTacToeTest, WinnerFound_Cross1)
{
	tictactoe->table[0][0] = 'X';
	tictactoe->table[1][1] = 'X';
	tictactoe->table[2][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

/*
	This test check if the winner can be
	accross from the top right corner to
	the bottom left corner (3,5,7)
*/
TEST_F(TicTacToeTest, WinnerFound_Cross2)
{
	tictactoe->table[0][2] = 'X';
	tictactoe->table[1][1] = 'X';
	tictactoe->table[2][0] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_TRUE(winner);
	EXPECT_FALSE(tie);
}

/*
	This test load the initial table with
	the values 1-9. There should not be
	any winners, because this is the
	initial setup prior to the beginning
	of the game.
*/
TEST_F(TicTacToeTest, WinnerNotFound)
{
	tictactoe->prepareInitialTable();

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_TRUE(tie);
}

/*
	The following tests are to confirm
	there are no winners by inserting
	a 'O' in a row/column
*/
TEST_F(TicTacToeTest, WinnerNotFound_Row1)
{
	tictactoe->table[0][0] = 'O';
	tictactoe->table[0][1] = 'X';
	tictactoe->table[0][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerNotFound_Row2)
{
	tictactoe->table[1][0] = 'X';
	tictactoe->table[1][1] = 'O';
	tictactoe->table[1][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerNotFound_Row3)
{
	tictactoe->table[2][0] = 'X';
	tictactoe->table[2][1] = 'X';
	tictactoe->table[2][2] = 'O';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerNotFound_Col1)
{
	tictactoe->table[0][0] = 'O';
	tictactoe->table[1][0] = 'X';
	tictactoe->table[2][0] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerNotFound_Col2)
{
	tictactoe->table[0][1] = 'X';
	tictactoe->table[1][1] = 'O';
	tictactoe->table[2][1] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

TEST_F(TicTacToeTest, WinnerNotFound_Col3)
{
	tictactoe->table[0][2] = 'X';
	tictactoe->table[1][2] = 'X';
	tictactoe->table[2][2] = 'O';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

/*
	This test check if there are no
	winner accross from the top left corner to
	the bottom right corner (1,5,9)
*/
TEST_F(TicTacToeTest, WinnerNotFound_Cross1)
{
	tictactoe->table[0][0] = 'X';
	tictactoe->table[1][1] = 'O';
	tictactoe->table[2][2] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

/*
	This test check if there are no winner
	accross from the top right corner to
	the bottom left corner (3,5,7)
*/
TEST_F(TicTacToeTest, WinnerNotFound_Cross2)
{
	tictactoe->table[0][2] = 'O';
	tictactoe->table[1][1] = 'X';
	tictactoe->table[2][0] = 'X';

	bool winner{};
	bool tie{};
	tictactoe->determineWinner(winner, tie);

	EXPECT_FALSE(winner);
	EXPECT_FALSE(tie);
}

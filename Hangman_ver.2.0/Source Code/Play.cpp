#include <iostream>
#include <string>
#include <Windows.h>
#include "play.h"
#include "Gallow.h"
#include "Menu.h"


Play::Play(std::string w) : Gallow(), Menu()
{
	answer = new char[1000];
	MAX_TRIES = 5;
	countWrongGuess = 0;
	word = w;
	displayGallow();
}

Play::~Play()
{
	delete[] answer;
	answer = nullptr;
}

int Play::letterFill(char guess, std::string secretword, std::string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;

		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

std::istream & operator >> (std::istream& cin, Play &play)
{
	std::string unk(play.word.length(), '*');
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ci;
	ci.bVisible = TRUE;
	ci.dwSize = 100;
	SetConsoleCursorInfo(output, &ci);

	while (play.countWrongGuess < play.MAX_TRIES)
	{

		
		std::cout << unk << std::endl;
		std::cout << "Guess a letter: ";
		cin >> play.answer;

		while (play.answer[1] > 1 || play.answer[1] == '_' || play.answer[1] == '-')
		{
			std::cout << "Your answer [" << play.answer << "] is NOT valid.\n";
			std::cout << "Please, only input a SINGLE character (letter, - , _ )\n";
			cin >> play.answer;
		}
		 
		//Menu menu;
		//menu.ClearScreen(0, 0);
		system("cls");
		if (play.letterFill(*play.answer, play.word, unk) == 0)
		{
			SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_RED);

			std::cout << "Sorry, but there is no [" << play.answer << "] in this word.\n";
			play.countWrongGuess++;
			if (play.countWrongGuess == 1)
				play.displayHead();

			else if (play.countWrongGuess == 2)
				play.displayLeftArm();

			else if (play.countWrongGuess == 3)
				play.displayRightArm();

			else if (play.countWrongGuess == 4)
				play.displayRightLeg();

			else if (play.countWrongGuess == 5)
				play.displayLeftLeg();
		}
		
		else
		{
			
			SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			std::cout << "Good job! the letter [" << play.answer << "] is in the word.\n";
		}

		if (play.word == unk)
		{
			std::cout << play.word << std::endl;
			std::cout << "Congralutations!!!" << " You got it!!!\n";
			break;
		}
	}
	if (play.countWrongGuess == play.MAX_TRIES)
	{
		std::cout << "\nSorry, you lose...you've been hanged.\n";	
		std::cout << "The word was : ";
		SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		std::cout  << play.word << std::endl << std::endl << std::endl;
	}

	ci.bVisible = FALSE;
	SetConsoleCursorInfo(output, &ci);
	SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	return cin;
}
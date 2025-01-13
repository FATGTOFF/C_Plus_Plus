#ifndef HANGMAN_H
#define HANGMAN_H

// Required to avoid conflict with max().
#define NOMINMAX

#include "Debug.h"
#include "Dictionary.h"
#include "Gallow.h"
#include "Logger.h"
#include "SharedMemory.h"
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <thread>
#include <Windows.h>
#include <winerror.h>


class Hangman : public SharedMemory
{

private:

	
	Dictionary dictionary{};
    const Logger *logger = getLoggerMemAddress();
	Gallow gallow{};
	const std::string notifyPressButton{ "Press ENTER button to continue..." };
	std::string answer{};
	std::string word{};
	const HANDLE outPut{ GetStdHandle(STD_OUTPUT_HANDLE) };
	CONSOLE_CURSOR_INFO ci{};
	HWND hWnd{ GetConsoleWindow() };
	DWORD flag{};
	DWORD written{};
	const int MAX_TRIES{ 5 };
	int countWrongGuess{ 0 };
	bool salida{ false };

	std::size_t letterFill(char, std::string, std::string&) const;
	void clearScreen(const short xCoord, const short yCoord) const;
	void displayTitle();
	COORD goTo(short, short) const;
	bool tryAgain();

public:
	Hangman();
	~Hangman();

	bool play();
};

#endif // !HANGMAN_H
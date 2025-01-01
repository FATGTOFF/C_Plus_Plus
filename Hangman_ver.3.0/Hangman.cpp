#include "Hangman.h"

std::size_t Hangman::letterFill(char guess, std::string secretWord, std::string &guessWord) const
{
	auto matches = 0;
	auto len = secretWord.length();

	for (std::size_t singleElement = 0; singleElement < len; ++singleElement)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessWord.at(singleElement))
			return 0;

		// Is the guess in the secret word?
		if (guess == secretWord.at(singleElement))
		{
			guessWord.at(singleElement) = guess;
			matches++;
		}
	}
	return matches;
}

void Hangman::clearScreen(const short xCoord, const short yCoord) const
{
	HANDLE                     hStdOut{};
	CONSOLE_SCREEN_BUFFER_INFO csbi{};
	DWORD                      count{};
	DWORD                      cellCount{};
	const COORD                homeCoords{ xCoord, yCoord };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void Hangman::displayTitle()
{
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(outPut, &ci);

		SetConsoleCursorPosition(outPut, goTo(16, 7));
		std::cout << "Welcome to...\n";
		SetConsoleCursorPosition(outPut, goTo(0, 8));
		std::cout << "\t\t _    _          _   _  _____ __  __          _   _ \n";
		std::cout << "\t\t| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |\n";
		std::cout << "\t\t| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |\n";
		std::cout << "\t\t|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |\n";
		std::cout << "\t\t| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |\n";
		std::cout << "\t\t|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|\n";
		SetConsoleCursorPosition(outPut, goTo(16, 15));
		std::cout << notifyPressButton << '\n';

	while (salida == false)
	{

		if (GetAsyncKeyState(VK_RETURN))
		{
			salida = true;
			clearScreen(0, 0);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
		}

		else if (!GetAsyncKeyState(VK_RETURN))
		{
			SetConsoleCursorPosition(outPut, goTo(16, 15));
			if (flag ^= 1)
				WriteFile(outPut, "Press ENTER button to continue...",
					static_cast<DWORD>(notifyPressButton.length()), &written, nullptr);
			else
				WriteFile(outPut, "                                 ",
					static_cast<DWORD>(notifyPressButton.length()), &written, nullptr);

			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

	}
}

COORD Hangman::goTo(const short xCoord, const short yCoord) const
{
	return { xCoord, yCoord };
}

bool Hangman::tryAgain()
{
	std::string tryAgain{ ' ' };
	std::cout << "\n\nTry again? (Y/y or N/n): ";
	std::getline(std::cin, tryAgain);


	while (tryAgain.length() > 1 || ('y' != tolower(tryAgain.at(0)) && 'n' != tolower(tryAgain.at(0))))
	{
		std::cout << "Your answer [" << tryAgain << "] is NOT valid.\n";
		std::cout << "Please select Y (for Yes) or N (for No)\n";
		std::getline(std::cin, tryAgain);
	}

	if ('y' == std::tolower(tryAgain.at(0)))
	{
		clearScreen(0, 0);

		countWrongGuess = 0;

		gallow.displayGallow();
		word = dictionary.getModifiedWord();

		return true;
	}
	else if ('n' == std::tolower(tryAgain.at(0)))
	{
		return false;
	}

	return false;
}

Hangman::Hangman()
{
	SetConsoleCursorInfo(outPut, &ci);
	SetConsoleTitleA("HANGMAN");
	MoveWindow(hWnd, 500, 100, 800, 500, TRUE);

	displayTitle();

	dictionary.loadAllData();
	gallow.displayGallow();

	if (DEBUG)
	{
		std::ofstream listOfWords{};
		listOfWords.open("listOfWords_Randomized.txt", std::ios_base::app);

		if (listOfWords.fail())
		{
			std::cerr << "Error creating the file.\n";
			return;
		}
		else
		{
			for (int count = 0; count < dictionary.getTotalCountOfWords(); ++count)
			{
				listOfWords << dictionary.getModifiedWord() << '\n';
			}

		}

		listOfWords.close();

	}
	else
	{
		word = dictionary.getModifiedWord();
	}


}

bool Hangman::play()
{
	std::string unk(word.length(), '*');
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	ci.bVisible = TRUE;
	ci.dwSize = 100;
	SetConsoleCursorInfo(output, &ci);

	while (countWrongGuess < MAX_TRIES)
	{
		std::cout << unk << std::endl;
		std::cout << "Guess a letter: ";
		std::getline(std::cin, answer);

		while (answer.length() > 1)
		{
			std::cout << "Your answer [" << answer << "] is NOT valid.\n";
			std::cout << "Please, only input a SINGLE character (letter, number or space)\n";
			std::getline(std::cin, answer);
		}

		clearScreen(0, 0);

		if (letterFill(*answer.c_str(), word, unk) == 0)
		{
			SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_RED);

			std::cout << "Sorry, but there is no [" << answer << "] in this word.\n";
			++countWrongGuess;
			if (countWrongGuess == 1)
				gallow.displayHead();

			else if (countWrongGuess == 2)
				gallow.displayLeftArm();

			else if (countWrongGuess == 3)
				gallow.displayRightArm();

			else if (countWrongGuess == 4)
				gallow.displayRightLeg();

			else if (countWrongGuess == 5)
				gallow.displayLeftLeg();
		}

		else
		{
			SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			std::cout << "Good job! [" << answer << "] is in the word.\n";
		}

		if (word == unk)
		{
			std::cout << word << '\n';
			std::cout << "Congralutations!!!" << " You got it!!!\n\n\n";
			dictionary.findTheWord(dictionary.getOriginalWord());

			if (tryAgain())
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (countWrongGuess == MAX_TRIES)
		{
			std::cout << "\nSorry, you lose...you've been hanged.\n";
			std::cout << "The word was : ";
			SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
			std::cout << word << '\n' << '\n' << '\n';
			dictionary.findTheWord(dictionary.getOriginalWord());

			if (tryAgain())
			{
				return true;
			}
			else
			{
				return false;
			}

		}

	}

	ci.bVisible = FALSE;
	SetConsoleCursorInfo(output, &ci);
	SetConsoleTextAttribute(output, FOREGROUND_INTENSITY | FOREGROUND_GREEN);

	return false;
}

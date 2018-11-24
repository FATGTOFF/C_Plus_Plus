#include <iostream>
#include <random>
#include <chrono>

void guessArray(char guess[][4], int& rows);
void answerArray(char answer[][4], int rows);
void playerTurn(char guess[][4], char answer[][4], int rows);
void completedWord(char guess[][4], char answer[][4], int rows);
int randomChoice(int min, int max);
int countAsterisks(char guess[][4], int rows);
void displayInstructions();

int main()
{
    int rowNumber{ 0 };
    bool tryAgain{ true };
    char again{ 'Y' };
    char guessWord[5][4] = { { 'C', '*', 'R', '*' },
				    { '*', 'R', '*', '*' },
				    { '*', 'O', '*', 'T' },
				    { '*', 'R', '*', 'E' },
				    { '*', '*', 'N', '*' } };

    char answerWord[5][4] = { { 'C', 'A', 'R', 'S' },
				    { 'A', 'R', 'M', 'S' },
				    { 'B', 'O', 'A', 'T' },
				    { 'T', 'R', 'E', 'E' },
				    { 'L', 'I', 'N', 'K' } };


    displayInstructions();

    while (tryAgain)
    {

	   guessArray(guessWord, rowNumber);
	   playerTurn(guessWord, answerWord, rowNumber);
	   answerArray(answerWord, rowNumber);

	   std::cout << "Try Again?(Y/N)";
	   std::cin >> again;

	   if (again == 'Y')
		  tryAgain = true;

	   else if (again == 'N')
		  tryAgain = false;

	   else
	   {
		  std::cout << "Your input was not Y/N.\n";
		  std::cout << "I will assume is N\n";
		  tryAgain = false;
	   }
    }

    return 0;
}

void guessArray(char word[][4], int& rows)
{

    rows = randomChoice(0, 4);
    for (int cols = 0; cols < 4; cols++)
    {
	   std::cout << word[rows][cols];
    }

    std::cout << std::endl;
}

void answerArray(char word[][4], int rows)
{
    std::cout << "The answer was : ";
    for (int cols = 0; cols < 4; cols++)
    {
	   std::cout << word[rows][cols];
    }

    std::cout << std::endl;
}

void playerTurn(char guess[][4], char answer[][4], int rows)
{

    int numberOfGuesses{ 8 };
    int countAsterisk = countAsterisks(guess, rows);
    char letter{ ' ' };

    while (countAsterisk !=0 && numberOfGuesses !=0)
    {
	   std::cout << "Enter a letter to guess the word.\n";
	   std::cin >> letter;

	   for (int cols = 0; cols < 4; cols++)
	   {

		  if (answer[rows][cols] == letter && guess[rows][cols] == '*')
		  {
			 std::cout << "Letter was found.\n";
			 guess[rows][cols] = letter;
			 countAsterisk--;

			 if (numberOfGuesses < 9)
				numberOfGuesses++;
		  }

	   }

	   if (countAsterisk == 0)
		  completedWord(guess, answer, rows);

	   else
	   {
 		numberOfGuesses--;
		std::cout << "You have " << numberOfGuesses << " tries left.\n";
	   }

    }

    std::cout << std::endl;

}

void completedWord(char guess[][4], char answer[][4], int rows)
{
    bool completeWord{ false };

    for (int cols = 0; cols < 4; cols++)
    {
	   if (guess[rows][cols] == '*')
		  completeWord = false;

	   else if (guess[rows][cols] != '*')
		  completeWord = true;
    }

    if (completeWord == false)
    {
	   std::cout << "You did not complete the word.\n";
	   answerArray(answer, rows);
	}

    else if (completeWord == true)
    {
	   std::cout << "You got it correct.";
	   answerArray(answer, rows);
    }

    std::cout << std::endl;

}

int randomChoice(int min, int max)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.

    return distributionToss(generator);

}

int countAsterisks(char guess[][4], int rows)
{
    int countAsterisk{ 0 };

    for (int cols = 0; cols < 4; cols++)
    {
	   if (guess[rows][cols] == '*')
		  countAsterisk++;
    }

    return countAsterisk;
}

void displayInstructions()
{
    std::cout << "The guessing game.\n";
    std::cout << "The user will try and guess a word.\n";
    std::cout << "You will try and guess the missing letters in the word.\n";
    std::cout << "You will only be allowed 8 guesses and then you will lose the game.\n";
    std::cout << "Good luck!!!\n";
}

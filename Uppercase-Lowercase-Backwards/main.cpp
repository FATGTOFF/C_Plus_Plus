/*
This program will display a number menu to the user.
The program will ask the user to select an option from
the menu and to enter a sentence. If they do not put in
a valid option the program will continue to ask them until
they do. To exit the program the user will insert -999. The
user will have 4 options, display the middle character if
it exists, display the sentence in uppercase, display the
sentence in lowercase, and display the sentence backwards.

You are not allowed to use the lolower() method, toupper()
method, vectors, or any method that reverses the sentence
automatically. You are only allowed to have one "return 0"
statement in your program. 

*/

#include <iostream>
#include <string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main()
{
	string sentence;
	int selection = 0;
	int exitProgram = -999; // sentinel
	char letter;

	while (selection != exitProgram)
	{
		cout << "Welcome to my program. Enter a sentence and select one of the options below.\n"
			<< "Enter -999 to exit the program.\n"
			<< "==============================================================================\n"
			<< "1. Display the middle character if there is one.\n"
			<< "2. Convert to uppercase\n"
			<< "3. Convert to lowercase\n"
			<< "4. Display backwards\n";

		cout << "Enter a sentence: ";
		getline(cin, sentence);
		cin.clear();

		cout << "Selection: ";
		cin >> selection;

		while (selection != 1 && selection != 2 && selection != 3 
			&& selection != 4 && selection != -999)
		{
			cout << "Your " << selection << " is not correct\n";
			cout << "Selection: ";
			cin >> selection;
		}

		if (1 == selection)
		{
			cout << "   MIDDLE   \n"
				<< "=============\n";
			char middleLetter = sentence.at(sentence.length() / 2);
			
			cout << "The middle character is: " << middleLetter << endl;
		}

		else if (2 == selection)
		{
			cout << " UPPERCASE \n"
				<< "=============\n";

			for (size_t count = 0; count < sentence.length(); count++)
			{
				letter = sentence.at(count);
				if (letter >= 'a' && letter <= 'z')
					letter = letter - 32;
				cout << letter;
			}
			cout << endl;
		}

		else if (3 == selection)
		{
			cout << " LOWERCASE \n"
				<< "=============\n";

			for (size_t count = 0; count < sentence.length(); count++)
			{
				letter = sentence.at(count);
				if (letter >= 'A' && letter <= 'Z')
					letter = letter + 32;
				cout << letter;
			}
			cout << endl;
		}

		else if (4 == selection)
		{
			cout << " BACKWARDS \n"
				<< "=============\n";

			for (int count = sentence.length() - 1; count >= 0; count--)
			{
				cout << sentence.at(count);
			}
			cout << endl;
		}

		cin.ignore();

	}

}
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include "DVDCollection.h"

void addRecords(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters, 
	const unsigned int numActors);
void displayRecords(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters,
	unsigned int numActors);
void updateRecords(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters,
	unsigned int& choice, const unsigned int numActors);
void deleteRecords(std::vector<DVDCollection>& dvd, unsigned int& choice);
void displayMenu(unsigned int&);
void InputNumberOnly(unsigned int &);
bool menuSelection(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters, 
	unsigned int& choice, const unsigned int numActors);
void validateRowSelection(std::vector<DVDCollection>& dvd, unsigned int& row);
void inputMovieLength(std::string title, std::string& length);
std::string convertMinsToHHMM(std::string length);
void inputMovieYear(std::string title, std::string& year);

int main()
{
	std::vector<DVDCollection> dvd;
	std::vector <std::string> actors{};
	std::vector <std::string> characters{};
	bool keepLooping{ true };
	unsigned int choice{};
	const unsigned int numActors{2};

	while (keepLooping)
	{
		displayMenu(choice);
		keepLooping = menuSelection(dvd, actors, characters, choice, numActors);
	}

	return 0;
}

void addRecords(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters, 
	const unsigned int numActors)
{

	std::string title{};
	std::string length{};
	std::string year{};
	std::string nameActor{};
	std::string nameCharacter{};
	unsigned int numberActors{};

	std::cin.ignore();
	for (std::size_t countA{ 0 }; countA < 1; countA++)
	{
		std::cout << "Movie Title: ";
		std::getline(std::cin, title);

		std::cout << "Movie Length (mins): ";
		inputMovieLength(title, length);
		length = convertMinsToHHMM(length);

		std::cout << "Movie Year: ";
		inputMovieYear(title, year);


		for (std::size_t countB{ 0 }; countB < numActors; countB++)
		{
			std::cout << "Movie " << title << " Actor # " << countB + 1 << " : ";
			std::getline(std::cin, nameActor);
			actors.push_back(nameActor);

			std::cout << "Movie " << title << " Characters # " << countB + 1 << " : ";
			std::getline(std::cin, nameCharacter);
			characters.push_back(nameCharacter);
		}
		DVDCollection newDvd(title, length, year, actors, characters);
		dvd.push_back(newDvd);

	}
	actors.clear();
	characters.clear();
}

void displayRecords(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters,
	unsigned int numActors)
{
	
	if (!dvd.empty())
	{
		std::cout << std::endl;
		std::cout << std::left << std::setw(3) << "#" << std::setw(24) << "Movie Title" << std::setw(7) << "Length" << std::setw(8)
			<< "Year" << std::setw(18) << "Actor/Actress " << "Character" << std::endl;


		for (std::size_t count{ 0 }; count < dvd.size(); count++)
		{
			std::cout << std::left << std::setw(3) << count + 1 << std::setw(24) << dvd[count].getMovieTitle() << std::setw(7) << dvd[count].getMovieLength() << std::setw(8)
				<< dvd[count].getMovieYear() << std::setw(18) << dvd[count].getActorsActressName(0) << dvd[count].getCharacters(0) << std::endl;

			for (std::size_t num{ 1 }; num < numActors; num++)
			{
				std::cout << std::left << std::setw(42) << " " << std::left << std::setw(18) << dvd[count].getActorsActressName(num) << std::setw(18) << dvd[count].getCharacters(num);
				std::cout << std::endl;
			}

		}
		
	}
	else
	{
		std::cout << std::endl;
		std::cout << std::left << std::setw(3) << "#" << std::setw(24) << "Movie Title" << std::setw(7) << "Length" << std::setw(8)
			<< "Year" << std::setw(18) << "Actor/Actress " << "Character" << std::endl;
		std::cout << "========================THE DATABASE IS EMPTY========================\n";
	}
}

void updateRecords(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters, unsigned int& choice,
	const unsigned int numActors)
{
	unsigned int row{};
	std::cout << "Select the row to update: ";
	validateRowSelection(dvd, row);
	std::cout << "You selected row number: " << row << std::endl;

	std::string title{};
	std::string length{};
	std::string year{};
	std::string nameActor{};
	std::string nameCharacter{};

	std::cin.ignore();
	for (std::size_t countA{ 0 }; countA < 1; countA++)
	{
		std::cout << "Movie Title: ";
		std::getline(std::cin, title);

		std::cout << "Movie Length(mins): ";
		inputMovieLength(title, length);
		length = convertMinsToHHMM(length);


		std::cout << "Movie Year: ";
		inputMovieYear(title, year);

		for (std::size_t countB{ 0 }; countB < numActors; countB++)
		{
			std::cout << "Movie " << title << " Actor # " << countB + 1 << " : ";
			std::getline(std::cin, nameActor);
			actors.push_back(nameActor);

			std::cout << "Movie " << title << " Characters # " << countB + 1 << " : ";
			std::getline(std::cin, nameCharacter);
			characters.push_back(nameCharacter);

		}
		DVDCollection newDvd(title, length, year, actors, characters);
		dvd.at(row - 1) = newDvd;

	}
	actors.clear();
	characters.clear();
}

void deleteRecords(std::vector<DVDCollection>& dvd, unsigned int& choice)
{
	unsigned int row{};
	std::cout << "Select the row to delete: ";
	validateRowSelection(dvd, row);
	std::cout << "You selected row number: " << row << std::endl;
	dvd.erase(dvd.begin() + (row - 1));
}

void displayMenu(unsigned int &choice)
{
	std::cout << "\n            DVD Collection\n";
	std::cout << "-----------------------------------------\n";
	std::cout << "1) Add movie information\n";
	std::cout << "2) Delete one movie record\n";
	std::cout << "3) Update the movie record\n";
	std::cout << "4) Display the information for the DVDs in the collection.\n";
	std::cout << "5) Exit the program\n\n";
	std::cout << "Enter your choice: ";
	InputNumberOnly(choice);
}

void InputNumberOnly(unsigned int &num)
{
	while ((std::cin >> num).fail() || std::cin.peek() != '\n')
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
		{
			continue;
			std::cin >> num;
		}
		std::cout << "Your choice is incorrect. Try again: ";
	}
}

bool menuSelection(std::vector<DVDCollection>& dvd, std::vector<std::string>& actors, std::vector<std::string>& characters, unsigned int & choice,
	const unsigned int numActors)
{
	bool keepLooping{ true };
	enum options { ADD_RECORDS = 1, REMOVE_RECORDS, UPDATE_RECORDS, DISPLAY_RECORDS, EXIT_PROGRAM };

	switch (choice)
	{
	case ADD_RECORDS:
		addRecords(dvd, actors, characters, numActors);
		keepLooping = true;
		break;

	case REMOVE_RECORDS:
		if (!dvd.empty())
		{
			deleteRecords(dvd, choice);
			keepLooping = true;
			break;
		}
		else
		{
			displayRecords(dvd, actors,characters, numActors);
			keepLooping = true;
			break;
		}

	case UPDATE_RECORDS:
		if (!dvd.empty())
		{
			updateRecords(dvd, actors, characters, choice, numActors);
			keepLooping = true;
			break;
		}
		else
		{
			displayRecords(dvd, actors, characters, numActors);
			keepLooping = true;
			break;
		}

	case DISPLAY_RECORDS:
		displayRecords(dvd, actors, characters, numActors);
		keepLooping = true;
		break;

	case EXIT_PROGRAM:
		std::cout << "Closing the program...\n";
		keepLooping = false;
		break;

	default:
		std::cout << "Please choose between " << ADD_RECORDS << " and " << EXIT_PROGRAM << "\n";
		keepLooping = true;
	}

	return keepLooping;
}

void validateRowSelection(std::vector<DVDCollection>& dvd, unsigned int& row)
{
	const unsigned int minRowAvailable{ 1 };
	const std::size_t maxRowAvailable{ dvd.size() };
	InputNumberOnly(row);
	while (row < 1 || row > dvd.size())
	{
		std::cout << "Your row selection [" << row << "] is incorrect\n";
		std::cout << "You may choose from " << minRowAvailable << " to " << maxRowAvailable << std::endl;
		std::cout << "Select the row: ";
		InputNumberOnly(row);
	}
}

void inputMovieLength(std::string title, std::string& length)
{
	std::getline(std::cin, length);
	for (std::size_t pos{ 0 }; pos < length.size(); pos++)
	{
		if (std::isdigit(length.at(pos)))
			continue;

		else
		{
			std::cout << "Your input [" << length << "] is the wrong format.\n";
			std::cout << "Please, input it in the digits format (i.e. 123).\n";
			std::cout << "Try again.\n";
			std::cout << "What is the length of " << title << " >>> ";
			inputMovieLength(title, length);
		}
	}

}

std::string convertMinsToHHMM(std::string length)
{
	int totalMins{ std::stoi(length) };
	int min{ (totalMins % 60) };
	int hrs{ totalMins / 60 };

	std::string hour = std::to_string(hrs);
	std::string minutes = std::to_string(min);

	if (min < 10)
	{
		hour.append(":");
		hour.append(1, '0');
		hour.append(minutes);
		length = hour;
	}

	else
	{
		hour.append(":");
		hour.append(minutes);
		length = hour;
	}

	return length;
}

void inputMovieYear(std::string title, std::string& year)
{
	std::getline(std::cin, year);
	while (year.size() != 4)
	{
		std::cout << "Your input [" << year << "] is the wrong format.\n";
		std::cout << "Please, input it in the digits format (i.e. 1987).\n";
		std::cout << "Try again.\n";
		std::cout << "What is the year of " << title << " >>> ";
		std::getline(std::cin, year);
	}

	for (std::size_t pos{ 0 }; pos < 4; pos++)
	{

		if (std::isdigit(year.at(pos)))
			continue;

		else
		{
			std::cout << "Your input [" << year << "] is the wrong format.\n";
			std::cout << "Please, input it in the digits format (i.e. 1987).\n";
			std::cout << "Try again.\n";
			std::cout << "What is the year of " << title << " >>> ";
			std::getline(std::cin, year);
		}
	}
}

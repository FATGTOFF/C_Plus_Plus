#include <iostream>
#include <cctype> // For toupper

//Global variables for the MAX size of the map.
const int ROWS{9};
const int COLS{9};

//Function prototypes.
void determineMapSize(const int, const int, int&);
void resetMap(char[][COLS], int);
void displayMap(char[][COLS], int);
void updateTreasureCoord(char[][COLS], int&, int&, int);
void updateXLocation(char[][COLS], int, int);
void updateTreasureVector(char [][COLS], char&, int&, int&, int&, int);
void mainMenu(int&);

int main()
{
	const int minMapSize{5}, maxMapSize{9};
	int choiceMapSize{}, row{}, col{}, distance{}, choice{};
	char map[ROWS][COLS]{};
	char direction{};
	bool keepLooping{true};


	while (keepLooping)
	{
		mainMenu(choice);
	
		switch (choice)
		{
			case 1: determineMapSize(minMapSize, maxMapSize, choiceMapSize);
					resetMap(map, choiceMapSize);
					updateTreasureCoord(map, row, col, choiceMapSize);
					updateXLocation(map, row, col);
					displayMap(map, choiceMapSize);
					keepLooping = true;
					break;

			case 2: updateTreasureVector(map, direction, distance, row, col, choiceMapSize);
					resetMap(map, choiceMapSize);
					updateXLocation(map, row, col);
					displayMap(map, choiceMapSize);
					keepLooping = true;
					break;

			case 3: std::cout << "Exiting Program.\n";
					keepLooping = false;
					break;

			default: std::cout << "Your choice is not valid.\n";
		}

	}
	return 0;
}

void determineMapSize(const int minMapSize, const int maxMapSize, int &choiceMapSize)
{
	std::cout << "Enter a map size between " << minMapSize <<
		" and " << maxMapSize << ": ";
	std::cin >> choiceMapSize;
	while (choiceMapSize < minMapSize || choiceMapSize > maxMapSize)
	{
		std::cout << "Invalid map size.\n";
		std::cout << "Enter a map size between " << minMapSize <<
			" and " << maxMapSize << ": ";
		std::cin >> choiceMapSize;
	}
	std::cout << "Map size set to " << choiceMapSize << std::endl;
}

void resetMap(char map[][COLS], int choiceMapSize)
{
	for (int rowCount = 0; rowCount < choiceMapSize; rowCount++)
		for (int colCount = 0; colCount < choiceMapSize; colCount++)
			map[rowCount][colCount] = '-';
}

void displayMap(char map[][COLS], int choiceMapSize)
{
	for (int rowCount = 0; rowCount < choiceMapSize; rowCount++)
	{
		std::cout << rowCount << " ";
		for (int colCount = 0; colCount < choiceMapSize; colCount++)
		{
			std::cout << map[rowCount][colCount] << "  ";
		}
		std::cout << std::endl;
	}

	for (int colCount = 0; colCount < choiceMapSize; colCount++)
		std::cout << "  " << colCount;
	std::cout << std::endl;
}

void updateTreasureCoord(char map[][COLS], int& row, int& col, int choiceMapSize)
{
	std::cout << "Initial location of X (row column): ";
	std::cin >> row >> col;
	while ((row < 0 || row > (choiceMapSize - 1)) || (col < 0 || col > (choiceMapSize - 1)))
	{
		std::cout << "Coordinates must be between 0 and " << choiceMapSize - 1 << std::endl;
		std::cout << "Initial location of X (row column): ";
		std::cin >> row >> col;
	}
	std::cout << "Treasure coordinates assigned to row " << row << " column " << col << std::endl;
}

void updateXLocation(char map[][COLS], int row, int col)
{
	if (map[row][col] == '-')
	{
		map[row][col] = 'X';
	}

	else
		return;
}

void updateTreasureVector(char map[][COLS], char& direction, int& distance,
	int& row, int& col, int choiceMapSize)
{
	updateXLocation(map, row, col);
	std::cout << "Shift X (N,S,E,W) and unit number: ";
	std::cin >> direction >> distance;

	if (toupper(direction) == 'E')
	{
		if (distance > ((choiceMapSize - 1) - col))
		{
			std::cout << "Treasure cannot move beyond the map.\n";
			return;
		}

		else
		{ 
			col += distance;
			map[row][col] = 'X';
			updateXLocation(map, row, col);
		}
	}

	else if (toupper(direction) == 'W')
	{
		if (distance < 0 || distance > (col))
		{
			std::cout << "Treasure cannot move beyond the map.\n";
			return;
		}

		else
		{ 
			col -= distance;
			map[row][col] = 'X';
			updateXLocation(map, row, col);
		}
	}

	else if (toupper(direction) == 'N')
	{
		if (distance < 0 || distance > row)
		{
			std::cout << "Treasure cannot move beyond the map.\n";
			return;
		}

		else
		{ 
			row -= distance;
			map[row][col] = 'X';
			updateXLocation(map, row, col);
		}
	}

	else if (toupper(direction) == 'S')
	{
		if (distance > ((choiceMapSize - 1) - row))
		{
			std::cout << "Treasure cannot move beyond the map.\n";
			return;
		}

		else
		{ 
			row += distance;
			map[row][col] = 'X';
			updateXLocation(map, row, col);
		}
	}

}

void mainMenu(int &choice)
{
	std::cout << "1) Update treasure coordinates (row/column)\n";
	std::cout << "2) Shift X (N S E W)\n";
	std::cout << "3) Exit Program\n";
	std::cin >> choice;
}

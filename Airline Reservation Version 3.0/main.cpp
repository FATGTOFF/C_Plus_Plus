#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// Function prototype.
void setupFirstClassSeatingChart(char[][4], int, int);
void setupFirst5CoachSeatingChart(char[][6], int, int);
void setupLast5CoachSeatingChart(char[][6], int, int);
void readFile(double[], const int);
void displayMenu(int& choice);
void reserveFirstClassRows(char[][4], double, const int,
	const int, int&);
void reserveFirst5CoachRows(char[][6], double, const int,
	const int, int&);
void reserveLast5CoachRows(char[][6], double, const int,
	const int, int&);
void totalNumOfSeatsSoldFirstClass(int);
void totalNumOfSeatsSoldCoach(int, int);
void determineNumOfTotalEmptySeats(int&, const int, char[][4], const int, char[][6],
	const int, char[][6]);
int countEmptyFirstClassSeats(char[][4], const int, const int);
int countEmptyCoachSeats(char[][6], const int, const int, char[][6], const int, const int);
void displayFirstClassSeats(char[][4], const int, const int);
void displayFirst5CoachSeats(char[][6], const int, const int);
void displayLast5CoachSeats(char[][6], const int, const int);
void InputNumberOnly(int& num);


int main()
{
	// Variables for First Class.
	const int firstClassRows{ 5 };
	const int firstClassAisle{ 4 };
	char firstClassSeats[firstClassRows][firstClassAisle];

	setupFirstClassSeatingChart(firstClassSeats, firstClassRows, firstClassAisle);

	// Variables for First 5 Coach Rows.
	const int first5CoachRows{ 10 };
	const int first5CoachAisle{ 6 };
	char first5CoachSeats[first5CoachRows][first5CoachAisle];

	setupFirst5CoachSeatingChart(first5CoachSeats, first5CoachRows, first5CoachAisle);

	// Variables for Last 5 Coach Rows.
	const int last5CoachRows{ 15 };
	const int last5CoachAisle{ 6 };
	char last5CoachSeats[last5CoachRows][last5CoachAisle];

	setupLast5CoachSeatingChart(last5CoachSeats, last5CoachRows, last5CoachAisle);

	// Variables for the Seat Prices.
	const int PRICES{ 3 };
	double seatPrices[PRICES];

	// Variables for the menu.
	int choice{ 0 };
	int countFirst{ 0 }; // To initializa accumulator.
	int countFirst5Coach{ 0 };
	int countLast5Coach{ 0 };
	int countEmptyRows{ 0 };
	int countFirstClassEmptyTotal{ 0 };
	int countCoachEmptyTotal{ 0 };
	double total{ 0.0 };

	// Call the function readFile to red the prices per class seat.
	readFile(seatPrices, PRICES);
	double firstclassprice = seatPrices[0];
	double coachfirst5price = seatPrices[1];
	double coachlast5price = seatPrices[2];

	bool keepLooping{ true };
	while (keepLooping)
	{

		displayMenu(choice);
		switch (choice)
		{

		case 1: reserveFirstClassRows(firstClassSeats, firstclassprice, firstClassRows,
			firstClassAisle, countFirst); keepLooping = true;
			break;

		case 2: reserveFirst5CoachRows(first5CoachSeats, coachfirst5price, first5CoachRows,
			first5CoachAisle, countFirst5Coach); keepLooping = true;
			break;

		case 3: reserveLast5CoachRows(last5CoachSeats, coachlast5price, last5CoachRows,
			last5CoachAisle, countLast5Coach); keepLooping = true;
			break;

		case 4: totalNumOfSeatsSoldFirstClass(countFirst); keepLooping = true;
			break;

		case 5: totalNumOfSeatsSoldCoach(countFirst5Coach, countLast5Coach); keepLooping = true;
			break;

		case 6: determineNumOfTotalEmptySeats(countEmptyRows, firstClassAisle, firstClassSeats, first5CoachAisle, first5CoachSeats,
			last5CoachAisle, last5CoachSeats); keepLooping = true;
			break;

		case 7: std::cout << "There are " << countEmptyFirstClassSeats(firstClassSeats, firstClassRows, firstClassAisle) << " empty seats total.\n";
			keepLooping = true;
			break;

		case 8: std::cout << "There are " << countEmptyCoachSeats(first5CoachSeats, first5CoachRows, first5CoachAisle, last5CoachSeats,
			last5CoachRows, last5CoachAisle) << " empty seats total.\n"; keepLooping = true;
			break;

		case 9:
		{
			total = (countFirst * firstclassprice) + (countFirst5Coach * coachfirst5price) +
				(countFirst5Coach * coachfirst5price);

			std::cout << "The total amount of sales is [$" << total << "]\n";
		}
		keepLooping = true;
		break;

		case 10: std::cout << "Closing the program...\n"; keepLooping = false;
			break;

		default: std::cout << "Please choose between 1-10\n"; keepLooping = true;

		}

	}

	return 0;
}

void readFile(double prices[], const int size)
{

	int count = 0;
	std::ifstream inputFile;
	std::string fileName{ "SeatPrices.txt" };
	//Open the file.
	inputFile.open(fileName);

	if (inputFile)
	{
		while (count < size + 1 && inputFile >> prices[count])
			count++;

		//Close the file.
		inputFile.close();
	}
	else
		std::cout << "Error opening the file " << fileName << "\n";
}

void displayMenu(int& choice)
{
	std::cout << "\t\t\t\tAirline Reservation\n\n"
		<< "\t\t\t1.  Reserve First Class Seat\n"
		<< "\t\t\t2.  Reserve Coach Seat (First 5 Rows)\n"
		<< "\t\t\t3.  Reserve Coach Seat (Last 5 Rows)\n"
		<< "\t\t\t4.  Display Total Number of Seat Solds (First Class)\n"
		<< "\t\t\t5.  Display Total Number of Seat Solds (Coach)\n"
		<< "\t\t\t6.  Display Total Number of Seats empty in a Row\n"
		<< "\t\t\t7.  Display Total Number of First Class Empty Seats\n"
		<< "\t\t\t8.  Display Total Number of Coach Empty Seats\n"
		<< "\t\t\t9.  Display Total amount of sales\n"
		<< "\t\t\t10. Exit the Program\n"
		<< "\t\t\tEnter your choice: ";
	InputNumberOnly(choice);
}

void InputNumberOnly(int& num)
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

void setupFirst5CoachSeatingChart(char first5CoachSeats[][6], int first5CoachRows, int first5CoachAisle)
{
	for (int x = 5; x < first5CoachRows; x++)
		for (int y = 0; y < first5CoachAisle; y++)
			first5CoachSeats[x][y] = '#';
}

void setupLast5CoachSeatingChart(char last5CoachSeats[][6], int last5CoachRows, int last5CoachAisle)
{
	for (int x = 5; x < last5CoachRows; x++)
		for (int y = 0; y < last5CoachAisle; y++)
			last5CoachSeats[x][y] = '#';
}

void reserveFirstClassRows(char firstClassSeats[][4], double firstclassprice, const int firstClassRows,
	const int firstClassAisle, int& countFirst)
{
	displayFirstClassSeats(firstClassSeats, firstClassRows, firstClassAisle);

	int rowFirstClass{ 0 };
	// Ask the user to select the row and seat.
	std::cout << "The price for First Class seat is $" << firstclassprice << std::endl;
	std::cout << "What Row would you like to reserve? ";
	InputNumberOnly(rowFirstClass);
	while (rowFirstClass < 1 || rowFirstClass > firstClassRows)
	{
		std::cout << "Your choice [" << rowFirstClass << "] is incorrect. Try again: ";
		InputNumberOnly(rowFirstClass);
	}

	int seatFirstClass{ 0 };
	std::cout << "What Seat would you like to reserve? ";
	InputNumberOnly(seatFirstClass);
	while (seatFirstClass < 1 || seatFirstClass > firstClassAisle)
	{
		std::cout << "Your choice [" << seatFirstClass << "] is incorrect. Try again: ";
		InputNumberOnly(seatFirstClass);
	}

	// If the seat is available, then it can be reserved. Otherwise, notify the user to select again.
	if (firstClassSeats[rowFirstClass - 1][seatFirstClass - 1] != '*')
	{

		firstClassSeats[rowFirstClass - 1][seatFirstClass - 1] = '*';
		std::cout << std::endl << "======RESERVED======\n";
		countFirst++;
	}

	else
	{
		std::cout << "======SEAT IS OCCUPIED======" << std::endl;
	}
}

void reserveFirst5CoachRows(char first5CoachSeats[][6], double coachfirst5price, const int first5CoachRows,
	const int first5CoachAisle, int& countFirst5Coach)
{
	displayFirst5CoachSeats(first5CoachSeats, first5CoachRows, first5CoachAisle);

	int rowFirst5Coach{ 0 };
	// Ask the user to select the row and seat.
	std::cout << "The price for Coach (First 5 Rows) seat is $" << coachfirst5price << std::endl;
	std::cout << "What Row would you like to reserve? ";
	InputNumberOnly(rowFirst5Coach);
	while (rowFirst5Coach < 6 || rowFirst5Coach > first5CoachRows)
	{
		std::cout << "Your choice [" << rowFirst5Coach << "] is incorrect. Try again: ";
		InputNumberOnly(rowFirst5Coach);
	}
	int seatFirst5Coach{ 0 };
	std::cout << "What Seat would you like to reserve? ";
	InputNumberOnly(seatFirst5Coach);
	while (seatFirst5Coach < 1 || seatFirst5Coach > first5CoachAisle)
	{
		std::cout << "Your choice [" << seatFirst5Coach << "] is incorrect. Try again: ";
		InputNumberOnly(seatFirst5Coach);
	}

	// If the seat is available, then it can be reserved. Otherwise, notify the user to select again.
	if (first5CoachSeats[rowFirst5Coach - 1][seatFirst5Coach - 1] != '*')
	{

		first5CoachSeats[rowFirst5Coach - 1][seatFirst5Coach - 1] = '*';
		std::cout << std::endl << "======RESERVED======\n";
		countFirst5Coach++;
	}

	else
	{
		std::cout << "======SEAT IS OCCUPIED======" << std::endl;
	}
}
void reserveLast5CoachRows(char last5CoachSeats[][6], double coachlast5price, const int last5CoachRows,
	const int last5CoachAisle, int& countLast5Coach)
{
	displayLast5CoachSeats(last5CoachSeats, last5CoachRows, last5CoachAisle);

	int rowLast5Coach{ 0 };
	// Ask the user to select the row and seat.
	std::cout << "The price for Coach (Last 5 Rows) seat is $" << coachlast5price << std::endl;
	std::cout << "What Row would you like to reserve? ";
	InputNumberOnly(rowLast5Coach);
	while (rowLast5Coach < 11 || rowLast5Coach > last5CoachRows)
	{
		std::cout << "Your choice [" << rowLast5Coach << "] is incorrect. Try again: ";
		InputNumberOnly(rowLast5Coach);
	}
	int seatLast5Coach{ 0 };
	std::cout << "What Seat would you like to reserve? ";
	InputNumberOnly(seatLast5Coach);
	while (seatLast5Coach < 1 || seatLast5Coach > last5CoachAisle)
	{
		std::cout << "Your choice [" << seatLast5Coach << "] is incorrect. Try again: ";
		InputNumberOnly(seatLast5Coach);
	}

	// If the seat is available, then it can be reserved. Otherwise, notify the user to select again.
	if (last5CoachSeats[rowLast5Coach - 1][seatLast5Coach - 1] != '*')
	{

		last5CoachSeats[rowLast5Coach - 1][seatLast5Coach - 1] = '*';
		std::cout << std::endl << "======RESERVED======\n";
		countLast5Coach++;
	}

	else
		std::cout << "======SEAT IS OCCUPIED======" << std::endl;
}

void totalNumOfSeatsSoldFirstClass(int countFirst)
{
	std::cout << "The Total Number of Seat Solds <First Class> is " <<
		countFirst << std::endl;
}

void totalNumOfSeatsSoldCoach(int countFirst5Coach, int countLast5Coach)
{
	std::cout << "The Total Number of Seat Solds <Coach> is " <<
		countFirst5Coach + countLast5Coach << std::endl;
}

void determineNumOfTotalEmptySeats(int& countEmptyRows, const int firstClassAisle, 
	char firstClassSeats[][4], const int first5CoachAisle, char first5CoachSeats[][6],
	const int last5CoachAisle, char last5CoachSeats[][6])
{
	int row{ 0 };
	std::cout << "Please select a row to determine the number of empty seats: ";
	InputNumberOnly(row);

	if (row > 0 && row < 6)
	{
		int countEmptyRows{ 0 };
		for (int y = 0; y < firstClassAisle; y++)
		{

			if (firstClassSeats[row - 1][y] == '#')
			{
				countEmptyRows++;
			}

		}
		std::cout << "There are " << countEmptyRows << " empty seats in Row # " << row << std::endl;
	}

	else if (row > 5 && row < 11)
	{
		int countEmptyRows{ 0 };
		for (int y = 0; y < first5CoachAisle; y++)
		{

			if (first5CoachSeats[row - 1][y] == '#')
			{
				countEmptyRows++;
			}

		}
		std::cout << "There are " << countEmptyRows << " empty seats in Row # " << row << std::endl;
	}

	else if (row > 10 && row < 16)
	{
		int countEmptyRows{ 0 };
		for (int y = 0; y < last5CoachAisle; y++)
		{

			if (last5CoachSeats[row - 1][y] == '#')
			{
				countEmptyRows++;
			}

		}
		std::cout << "There are " << countEmptyRows << " empty seats in Row # " << row << std::endl;
	}

	else
		std::cout << "The row [" << row << "] is not correct. Try again.\n";
}

int countEmptyFirstClassSeats(char firstClassSeats[][4], const int firstClassRows, const int firstClassAisle)
{
	displayFirstClassSeats(firstClassSeats, firstClassRows, firstClassAisle);

	int countFirstClassEmptyTotal{ 0 };

	for (int x = 0; x < firstClassRows; x++)
	{
		for (int y = 0; y < firstClassAisle; y++)
		{
			if (firstClassSeats[x][y] == '#')
			{
				countFirstClassEmptyTotal++;
			}
		}
	}
	return countFirstClassEmptyTotal;
}

int countEmptyCoachSeats(char first5CoachSeats[][6], const int first5CoachRows, 
	const int first5CoachAisle, char last5CoachSeats[][6],
	const int last5CoachRows, const int last5CoachAisle)
{

	std::cout << "# - Available Seats\n";
	std::cout << "* - Occupied seats\n";
	std::cout << "Available Seats for you are :\n";
	std::cout << "       1 2 3 4 5 6\n";
	for (int x = 5; x < first5CoachRows; x++)
	{
		std::cout << std::right << std::setw(2) << "Row " << std::setw(2) << x + 1;
		for (int y = 0; y < first5CoachAisle; y++)
			std::cout << std::setw(2) << first5CoachSeats[x][y];

		std::cout << std::endl;
	}

	for (int x = 10; x < last5CoachRows; x++)
	{
		std::cout << std::right << std::setw(2) << "Row " << std::setw(2) << x + 1;
		for (int y = 0; y < last5CoachAisle; y++)
			std::cout << std::setw(2) << last5CoachSeats[x][y];

		std::cout << std::endl;
	}

	int countCoachEmptyTotal{ 0 };
	for (int x = 0; x < last5CoachRows; x++)
	{
		for (int y = 0; y < last5CoachAisle; y++)
		{
			if (last5CoachSeats[x][y] == '#')
			{
				countCoachEmptyTotal++;
			}
		}
	}

	for (int x = 0; x < first5CoachRows; x++)
	{
		for (int y = 0; y < first5CoachAisle; y++)
		{
			if (first5CoachSeats[x][y] == '#')
			{
				countCoachEmptyTotal++;
			}
		}
	}
	return countCoachEmptyTotal;
}
void setupFirstClassSeatingChart(char firstClassSeats[][4], int maxRows, int maxCols)
{
	for (int x = 0; x < maxRows; x++)
		for (int y = 0; y < maxCols; y++)
			firstClassSeats[x][y] = '#';
}

void displayFirstClassSeats(char firstClassSeats[][4], const int firstClassRows, const int firstClassAisle)
{
	std::cout << "# - Available Seats\n";
	std::cout << "* - Occupied seats\n";
	std::cout << "Available Seats for you are :\n";
	std::cout << "       1 2 3 4\n";
	for (int x = 0; x < firstClassRows; x++)
	{
		std::cout << std::right << std::setw(2) << "Row " << std::setw(2) << x + 1;
		for (int y = 0; y < firstClassAisle; y++)
			std::cout << std::setw(2) << firstClassSeats[x][y];

		std::cout << std::endl;
	}
}

void displayFirst5CoachSeats(char first5CoachSeats[][6], const int first5CoachRows, const int first5CoachAisle)
{
	std::cout << "# - Available Seats\n";
	std::cout << "* - Occupied seats\n";
	std::cout << "Available Seats for you are :\n";
	std::cout << "       1 2 3 4 5 6\n";
	for (int x = 5; x < first5CoachRows; x++)
	{
		std::cout << std::right << std::setw(2) << "Row " << std::setw(2) << x + 1;
		for (int y = 0; y < first5CoachAisle; y++)
			std::cout << std::setw(2) << first5CoachSeats[x][y];

		std::cout << std::endl;
	}
}

void displayLast5CoachSeats(char last5CoachSeats[][6], const int last5CoachRows, const int last5CoachAisle)
{
	std::cout << "# - Available Seats\n";
	std::cout << "* - Occupied seats\n";
	std::cout << "Available Seats for you are :\n";
	std::cout << "       1 2 3 4 5 6\n";
	for (int x = 10; x < last5CoachRows; x++)
	{
		std::cout << std::right << std::setw(2) << "Row " << std::setw(2) << x + 1;
		for (int y = 0; y < last5CoachAisle; y++)
			std::cout << std::setw(2) << last5CoachSeats[x][y];

		std::cout << std::endl;
	}
}


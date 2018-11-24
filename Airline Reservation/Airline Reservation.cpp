#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Function prototype.
double readFile(double[], int);
void displayMenu(int &choice);
void InputNumberOnly(int &num);
void firstClassRows();



int main()
{
	// Variables for First Class.
	const int firstClassRows{ 5 };
	const int firstClassAisle{ 4 };
	char firstClassSeats[firstClassRows][firstClassAisle];

	// Variables for First 5 Coach Rows.
	const int first5CoachRows{ 10 };
	const int first5CoachAisle{ 6 };
	char first5CoachSeats[first5CoachRows][first5CoachAisle];

	// Variables for Last 5 Coach Rows.
	const int last5CoachRows{ 15 };
	const int last5CoachAisle{ 6 };
	char last5CoachSeats[last5CoachRows][last5CoachAisle];

	// Variables for the Seat Prices.
	const int PRICES{ 3 };
	double seatPrices[PRICES];

	// Variables for the menu.
	int choice{ 0 };
	int row{ 0 };
	int rowFirstClass{ 0 };
	int seatFirstClass{ 0 };
	int countFirst{ 0 }; // To initializa accumulator.
	int rowFirst5Coach{ 0 };
	int seatFirst5Coach{ 0 };
	int countFirst5Coach{ 0 };
	int rowLast5Coach{ 0 };
	int seatLast5Coach{ 0 };
	int countLast5Coach{ 0 };
	int countEmptyRows{ 0 };
	int countFirstClassEmptyTotal{ 0 };
	int countCoachEmptyTotal{ 0 };
	double total{ 0.0 };

	// Call the function readFile to red the prices per class seat.
	double firstclassprice = readFile(seatPrices, 0);
	double coachfirst5price = readFile(seatPrices, 1);
	double coachlast5price = readFile(seatPrices, 2);

	

	for (int x = 0; x < firstClassRows; x++)
		for (int y = 0; y < firstClassAisle; y++)
			firstClassSeats[x][y] = '#';

	for (int x = 5; x < first5CoachRows; x++)
		for (int y = 0; y < first5CoachAisle; y++)
			first5CoachSeats[x][y] = '#';

	for (int x = 10; x < last5CoachRows; x++)
		for (int y = 0; y < last5CoachAisle; y++)
			last5CoachSeats[x][y] = '#';

	do
	{

		displayMenu(choice);
		switch (choice)
		{

		case 1:
		{
			cout << "# - Available Seats\n";
			cout << "* - Occupied seats\n";
			cout << "Available Seats for you are :\n";
			cout << "       1 2 3 4\n";
			for (int x = 0; x < firstClassRows; x++)
			{
				cout << right << setw(2) << "Row " << setw(2) << x + 1;
				for (int y = 0; y < firstClassAisle; y++)
					cout << setw(2) << firstClassSeats[x][y];

				cout << endl;
			}

			// Ask the user to select the row and seat.
			cout << "The price for First Class seat is $" << firstclassprice << endl;
			cout << "What Row would you like to reserve?";
			InputNumberOnly(rowFirstClass);
			while (rowFirstClass < 1 || rowFirstClass > firstClassRows)
			{
				cout << "Your choice [" << rowFirstClass << "] is incorrect. Try again: ";
				InputNumberOnly(rowFirstClass);
			}


			cout << "What Seat would you like to reserve?";
			InputNumberOnly(seatFirstClass);
			while (rowFirstClass < 1 || seatFirstClass > firstClassAisle)
			{
				cout << "Your choice [" << seatFirstClass << "] is incorrect. Try again: ";
				InputNumberOnly(seatFirstClass);
			}

			// If the seat is available, then it can be reserved. Otherwise, notify the user to select again.
			if (firstClassSeats[rowFirstClass - 1][seatFirstClass - 1] != '*')
			{

				firstClassSeats[rowFirstClass - 1][seatFirstClass - 1] = '*';
				cout << endl << "======RESERVED======\n";
				countFirst++;
			}

			else
			{
				cout << "======SEAT IS OCCUPIED======" << endl;
			}

		}
		break;

		case 2:
		{
			cout << "# - Available Seats\n";
			cout << "* - Occupied seats\n";
			cout << "Available Seats for you are :\n";
			cout << "       1 2 3 4 5 6\n";
			for (int x = 5; x < first5CoachRows; x++)
			{
				cout << right << setw(2) << "Row " << setw(2) << x + 1;
				for (int y = 0; y < first5CoachAisle; y++)
					cout << setw(2) << first5CoachSeats[x][y];

				cout << endl;
			}

			// Ask the user to select the row and seat.
			cout << "The price for Coach (First 5 Rows) seat is $" << coachfirst5price << endl;
			cout << "What Row would you like to reserve?";
			InputNumberOnly(rowFirst5Coach);
			while (rowFirst5Coach < 6 || rowFirst5Coach > first5CoachRows)
			{
				cout << "Your choice [" << rowFirst5Coach << "] is incorrect. Try again: ";
				InputNumberOnly(rowFirst5Coach);
			}

			cout << "What Seat would you like to reserve?";
			InputNumberOnly(seatFirst5Coach);
			while (seatFirst5Coach < 1 || seatFirst5Coach > first5CoachAisle)
			{
				cout << "Your choice [" << seatFirst5Coach << "] is incorrect. Try again: ";
				InputNumberOnly(seatFirst5Coach);
			}


			// If the seat is available, then it can be reserved. Otherwise, notify the user to select again.
			if (first5CoachSeats[rowFirst5Coach - 1][seatFirst5Coach - 1] != '*')
			{

				first5CoachSeats[rowFirst5Coach - 1][seatFirst5Coach - 1] = '*';
				cout << endl << "======RESERVED======\n";
				countFirst5Coach++;
			}

			else
			{
				cout << "======SEAT IS OCCUPIED======" << endl;
				//break;
			}

		}
		break;

		case 3:
		{
			cout << "# - Available Seats\n";
			cout << "* - Occupied seats\n";
			cout << "Available Seats for you are :\n";
			cout << "       1 2 3 4 5 6\n";
			for (int x = 10; x < last5CoachRows; x++)
			{
				cout << right << setw(2) << "Row " << setw(2) << x + 1;
				for (int y = 0; y < last5CoachAisle; y++)
					cout << setw(2) << last5CoachSeats[x][y];

				cout << endl;
			}

			// Ask the user to select the row and seat.
			cout << "The price for Coach (Last 5 Rows) seat is $" << coachlast5price << endl;
			cout << "What Row would you like to reserve?";
			InputNumberOnly(rowLast5Coach);
			while (rowLast5Coach < 11 || rowLast5Coach > last5CoachRows)
			{
				cout << "Your choice [" << rowLast5Coach << "] is incorrect. Try again: ";
				InputNumberOnly(rowLast5Coach);
			}

			cout << "What Seat would you like to reserve?";
			InputNumberOnly(seatLast5Coach);
			while (seatLast5Coach < 1 || seatLast5Coach > last5CoachAisle)
			{
				cout << "Your choice [" << seatLast5Coach << "] is incorrect. Try again: ";
				InputNumberOnly(seatLast5Coach);
			}

			// If the seat is available, then it can be reserved. Otherwise, notify the user to select again.
			if (last5CoachSeats[rowLast5Coach - 1][seatLast5Coach - 1] != '*')
			{

				last5CoachSeats[rowLast5Coach - 1][seatLast5Coach - 1] = '*';
				cout << endl << "======RESERVED======\n";
				countLast5Coach++;
			}

			else
				cout << "======SEAT IS OCCUPIED======" << endl;

		}
		break;

		case 4:
		{
			cout << "The Total Number of Seat Solds <First Class> is " <<
				countFirst << endl;
		}
		break;

		case 5:
		{
			cout << "The Total Number of Seat Solds <Coach> is " <<
				countFirst5Coach + countLast5Coach << endl;
		}
		break;

		case 6:
		{

			cout << "Please select a row to determine the number of empty seats: ";
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
				cout << "There are " << countEmptyRows << " empty seats in Row # " << row << endl;
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
				cout << "There are " << countEmptyRows << " empty seats in Row # " << row << endl;
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
				cout << "There are " << countEmptyRows << " empty seats in Row # " << row << endl;
			}

			else
				cout << "The row [" << row << "] is not correct. Try again.\n";
		}
		break;

		case 7:
		{

			cout << "# - Available Seats\n";
			cout << "* - Occupied seats\n";
			cout << "Available Seats for you are :\n";
			cout << "       1 2 3 4\n";
			for (int x = 0; x < firstClassRows; x++)
			{
				cout << right << setw(2) << "Row " << setw(2) << x + 1;
				for (int y = 0; y < firstClassAisle; y++)
					cout << setw(2) << firstClassSeats[x][y];

				cout << endl;
			}

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
			cout << "There are " << countFirstClassEmptyTotal << " empty seats total.\n";

		}
		break;

		case 8:
		{
			cout << "# - Available Seats\n";
			cout << "* - Occupied seats\n";
			cout << "Available Seats for you are :\n";
			cout << "       1 2 3 4 5 6\n";
			for (int x = 5; x < first5CoachRows; x++)
			{
				cout << right << setw(2) << "Row " << setw(2) << x + 1;
				for (int y = 0; y < first5CoachAisle; y++)
					cout << setw(2) << first5CoachSeats[x][y];

				cout << endl;
			}

			for (int x = 10; x < last5CoachRows; x++)
			{
				cout << right << setw(2) << "Row " << setw(2) << x + 1;
				for (int y = 0; y < last5CoachAisle; y++)
					cout << setw(2) << last5CoachSeats[x][y];

				cout << endl;
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

			cout << "There are " << countCoachEmptyTotal++ << " empty seats total.\n";

		}
		break;

		case 9:
		{

			total = (countFirst * firstclassprice) + (countFirst5Coach * coachfirst5price) +
			(countFirst5Coach * coachfirst5price);

			cout << "The total amount of sales is [$" << total << "]\n";

		}
		break;

		default:
			cout << "Your choice " << choice << " is not correct.\n";
		}

	} while (choice != 10);

	return 0;
}

double readFile(double prices[], int size)
{

	int count = 0;
	ifstream inputFile;

	//Open the file.
	inputFile.open("SeatPrices.txt");

	while (count < size + 1 && inputFile >> prices[count])
		count++;


	//Close the file.
	inputFile.close();


	return prices[size];
}

void displayMenu(int &choice)
{
	cout << "\t\t\t\tAirline Reservation\n\n"
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

void InputNumberOnly(int &num)
{
	while ((cin >> num).fail() || cin.peek() != '\n')
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			continue;
			cin >> num;
		}
		cout << "Your choice is incorrect. Try again: ";
	}
}


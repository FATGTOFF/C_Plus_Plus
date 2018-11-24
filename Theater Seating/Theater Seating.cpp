/*Here is the assignment : Write a program that can be used by a small theater to sell
tickets for performances.The theater’s auditorium has 15 rows of seats, with 30 seats
in each row.The program should display a screen that shows which seats are available
and which are taken.For example, the following screen shows a chart depicting each
seat in the theater.Seats that are taken are represented by an * symbol, and seats that
are available are represented by a # symbol :
Seats
      123456789012345678901234567890
Row 1 * **###***###*########*****####
Row 2 ####*************####*******##
Row 3 * *###**********########****###
Row 4 * *######**************##******
Row 5 * *******#####*********########
Row 6 ##############************####
Row 7 #######************###########
Row 8 * ***********##****############
Row 9 #########*****############****
Row 10 #####*************############
Row 11 #**********#################**
Row 12 #############********########*
Row 13 ###***********########**######
Row 14 ##############################
Row 15 ##############################
Here is a list of tasks this program must perform :
• When the program begins, it should ask the user to enter the seat prices for each row.
The prices can be stored in a separate array. (Alternatively, the prices may be read
from a file.)
• Once the prices are entered, the program should display a seating chart similar to
the one shown above.The user may enter the row and seat numbers for tickets being
sold.Every time a ticket or group of tickets is purchased, the program should display
the total ticket prices and update the seating chart.
• The program should keep a total of all ticket sales.The user should be given an
option of viewing this amount.
• The program should also give the user an option to see a list of how many seats
have been sold, how many seats are available in each row, and how many seats are
available in the entire auditorium.
Input Validation : When tickets are being sold, do not accept row or seat numbers that
do not exist.When someone requests a particular seat, the program should make sure
that seat is available before it is sold.*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib> // Needed for the exit function.

//Function Prototypes.
void displayColsNumber();
void setupInitialSeatingChart(char[][30], int, int);
void displaySubsequentSeatingChart(char[][30], int, int);
void readFile(double[], int);
void displayMenu(int &);
void reservePlatinumRows(char[][30], double[], double&, int&);
void reserveGoldRows(char[][30], double[], double&, int&);
void reserveEconomyRows(char[][30], double[], double&, int&);
void countEmptySeatsInRow(char seats[][30], int chooseRows, int MAXCOLS);
void InputNumber(int&);
void validateColsInput(int&);
void displayPrices(double[]);

int main()
{
    const int MAXCOLS{ 30 };
    const int MAXROWS{ 15 };
    const int TOTALSEATS{ MAXCOLS * MAXROWS };
    char seats[MAXROWS][MAXCOLS];
    int choice{ 0 };
    int chooseRows{ 0 };
    double prizes[3];
    double runningTotal{ 0.0 };
    int countSoldSeats{ 0 };


    readFile(prizes, 3);

    setupInitialSeatingChart(seats, MAXROWS, MAXCOLS);

    bool keepLooping{ true };
    while (keepLooping)
    {
	   displayMenu(choice);
	   switch (choice)
	   {

		  case 1: displaySubsequentSeatingChart(seats, MAXROWS, MAXCOLS); keepLooping = true;
				break; 

		  case 2: displayPrices(prizes);
				break;

		  case 3: reservePlatinumRows(seats, prizes, runningTotal, countSoldSeats); keepLooping = true;
				break;

		  case 4: reserveGoldRows(seats, prizes, runningTotal, countSoldSeats); keepLooping = true;
				break;

		  case 5: reserveEconomyRows(seats, prizes, runningTotal, countSoldSeats); keepLooping = true;
				break;

		  case 6: std::cout << "The Total of Number of Seat Solds is " << countSoldSeats << std::endl; keepLooping = true;
				break;

		  case 7: countEmptySeatsInRow(seats, chooseRows, MAXCOLS); keepLooping = true;
				break;

		  case 8: std::cout << "The Total Number of Available Seats in the Auditorium is " << TOTALSEATS - countSoldSeats << std::endl; keepLooping = true;
				break;

		  case 9: std::cout << "The Total Amount of Sales is $" << runningTotal << std::endl; keepLooping = true;
				break;
		  case 10: std::cout << "Closing the program...\n"; keepLooping = false;
				break;

		  default: std::cout << "Please choose between 1-10\n"; keepLooping = true;

	  }

   }

    return 0;
}

void displayColsNumber()
{
    std::cout << std::right << std::setw(7) << "\t   ";
    for (int count = 0; count < 9; count++)
    {
	   std::cout << count + 1;
    }

    for (int count = 0; count < 10; count++)
    {
	   std::cout << count;
    }

    for (int count = 0; count < 10; count++)
    {
	   std::cout << count;

	   if (count == 9)
	   {
		  count = 0;
		  std::cout << count;
		  break;
	   }

    }

    std::cout << std::endl;
}

void setupInitialSeatingChart(char seats[][30], int MAXROWS, int MAXCOLS)
{

    for (int numRows = 0; numRows < MAXROWS; numRows++)
	   for (int numCols = 0; numCols < MAXCOLS; numCols++)
		  seats[numRows][numCols] = '#';
}

void displaySubsequentSeatingChart(char seats[][30], int MAXROWS, int MAXCOLS)
{
    displayColsNumber();
    for (int numRows = 0; numRows < MAXROWS; numRows++)
    {
	   std::cout << std::left << std::setw(2) << "Row " << std::setw(2) << numRows + 1 << "\t   ";

	   for (int numCols = 0; numCols < MAXCOLS; numCols++)
		  std::cout << std::setw(1) << seats[numRows][numCols];

	   std::cout << std::endl;
    }
}

void readFile(double prices[], int size)
{
    std::ifstream prizesFile;
    int count{ 0 };

    prizesFile.open("SeatPrices.txt");

    if (prizesFile)
    {
	   while (prizesFile >> prices[count] && count < size)
		  count++;
	   std::cout << "Prices loaded successful.\n";
	   prizesFile.close();
    }
    else
    {
	   std::cout << "Error opening the file SeatPrices.txt\n";
	   std::cout << "Ensure the file is in the same place as the .exe file\n";
	   std::cout << "The program will close now...\n";
	   exit(0); // Needed to close the program for the user to ensure the file exist.
    }




}

void displayMenu(int &choice)
{
    std::cout << "\t\t\tTheater Seating\n\n"
	   << "\t\t1.   Display the Seating Chart\n"
	   << "\t\t2.   Display the Prizes of the Seats\n"
	   << "\t\t3.   Reserve Platinum Class Rows (1-5)\n"
	   << "\t\t4.   Reserve Gold Class Rows (6-10)\n"
	   << "\t\t5.   Reserve Economy Class Rows (11-15)\n"
	   << "\t\t6.   Display Total Number of Seat Solds\n"
	   << "\t\t7.   Display Total Number of Available Seats per Row\n"
	   << "\t\t8.   Display Total Number of Available Seats in the Auditorium\n"
	   << "\t\t9.   Display Total amount of sales\n"
	   << "\t\t10.  Exit the Program\n"
	   << "\t\tEnter your choice: ";
    InputNumber(choice);
}

void reservePlatinumRows(char seats[][30], double prizes[], double& runningTotal, int& countSoldSeats)
{
    int chooseRows{ 0 }, chooseCols{ 0 };

    std::cout << "Choose the Seating Row [1-5]: ";
    InputNumber(chooseRows);
    
    while (chooseRows < 1 || chooseRows > 5)
    {
	   std::cout << "The Platinum Rows are from 1 to 5\n";
	   std::cout << "Choose the Seating Row [1-5]: ";
	   InputNumber(chooseRows);
    }

    std::cout << "Choose the Seating Column [1-30]: ";
    InputNumber(chooseCols);

    validateColsInput(chooseCols);

    if (seats[chooseRows - 1][chooseCols - 1] == '#')
    {

	   if (chooseRows < 6)
	   {

		  std::cout << "The price for the row [" << chooseRows << "] is $" << prizes[0] << std::endl;
		  runningTotal += prizes[0];
		  std::cout << "The Total price for the seats is $" << runningTotal << std::endl;
	   }

	   seats[chooseRows - 1][chooseCols - 1] = '*';
	   std::cout << "===SEAT RESERVED===\n";
	   countSoldSeats++;
    }

    else if (seats[chooseRows - 1][chooseCols - 1] == '*')
    {
	   std::cout << "===SEAT IS OCCUPIED===\n";
	   std::cout << "Choose another seat.\n";
    }
}

void reserveGoldRows(char seats[][30], double prizes[], double& runningTotal, int& countSoldSeats)
{
    int chooseRows{ 0 }, chooseCols{ 0 };

    std::cout << "Choose the Seating Row [6-10]: ";
    InputNumber(chooseRows);

    while (chooseRows < 6 || chooseRows > 10)
    {
	   std::cout << "The Gold Rows are from 6 to 10\n";
	   std::cout << "Choose the Seating Row [6-10]: ";
	   InputNumber(chooseRows);
    }

    std::cout << "Choose the Seating Column [1-30]: ";
    InputNumber(chooseCols);

    validateColsInput(chooseCols);

    if (seats[chooseRows - 1][chooseCols - 1] == '#')
    {

	   if (chooseRows > 5 && chooseRows < 11)
	   {
		  std::cout << "The price for the row [" << chooseRows << "] is $" << prizes[1] << std::endl;
		  runningTotal += prizes[1];
		  std::cout << "The Total price for the seats is $" << runningTotal << std::endl;
	   }

	   seats[chooseRows - 1][chooseCols - 1] = '*';
	   std::cout << "===SEAT RESERVED===\n";
	   countSoldSeats++;
    }

    else if (seats[chooseRows - 1][chooseCols - 1] == '*')
    {
	   std::cout << "===SEAT IS OCCUPIED===\n";
	   std::cout << "Choose another seat.\n";
    }
}

void reserveEconomyRows(char seats[][30], double prizes[], double& runningTotal, int& countSoldSeats)
{
    int chooseRows{ 0 }, chooseCols{ 0 };

    std::cout << "Choose the Seating Row [11-15]: ";
    InputNumber(chooseRows);

    while (chooseRows < 11 || chooseRows > 15)
    {
	   std::cout << "The Economy Rows are from 11 to 15\n";
	   std::cout << "Choose the Seating Row [11-15]: ";
	   InputNumber(chooseRows);
    }

    std::cout << "Choose the Seating Column [1-30]: ";
    InputNumber(chooseCols);

    validateColsInput(chooseCols);

    if (seats[chooseRows - 1][chooseCols - 1] == '#')
    {
	   if (chooseRows > 10 && chooseRows < 16)
	   {
		  std::cout << "The price for the row [" << chooseRows << "] is $" << prizes[2] << std::endl;
		  runningTotal += prizes[2];
		  std::cout << "The Total price for the seats is $" << runningTotal << std::endl;
	   }

	   seats[chooseRows - 1][chooseCols - 1] = '*';
	   std::cout << "===SEAT RESERVED===\n";
	   countSoldSeats++;
    }

    else if (seats[chooseRows - 1][chooseCols - 1] == '*')
    {
	   std::cout << "===SEAT IS OCCUPIED===\n";
	   std::cout << "Choose another seat.\n";
    }
}

void countEmptySeatsInRow(char seats[][30], int chooseRows, int MAXCOLS)
{
    int countEmptyRows{ 0 };
    std::cout << "Please select a row to determine the number of empty seats: ";
    InputNumber(chooseRows);

    for (int count = 0; count < MAXCOLS; count++)
    {
	   if (seats[chooseRows - 1][count] == '#')
		  countEmptyRows++;
    }

    std::cout << "There are " << countEmptyRows << " empty seats in Row # " << chooseRows << std::endl;
}

void InputNumber(int& choice)
{
    bool bFail{ false };

    do
    {
	   std::cin >> choice;
	   bFail = std::cin.fail();
	   if (bFail)
		  std::cout << "Ensure your input is numbers only: ";
	   
	   std::cin.clear();
	   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (bFail == true);
}

void validateColsInput(int& chooseCols)
{

    while (chooseCols < 1 || chooseCols > 30)
    {
	   std::cout << "The Colums number are from 1-30\n";
	   std::cout << "Choose the Seating Column [1-30]: ";
	   InputNumber(chooseCols);
    }
}

void displayPrices(double prizes[])
{
    std::cout << "The following are the Prices for the seating:\n";
    std::cout << "Platinum Seats : $" << prizes[0] << std::endl;
    std::cout << "Gold Seats :\t $" << prizes[1] << std::endl;
    std::cout << "Economy Seats :\t $" << prizes[2] << std::endl;
}

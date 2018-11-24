#include <iostream>
#include <fstream>
#include "DVDCollection.h"
#include "listOfDVDs.h"
using std::cin;
using std::cout;

void displayMenu(int&);
void InputNumberOnly(int &);

int main()
{
    const int sizeOfRecords{ 5 };
    std::ifstream inFile;
    std::ofstream outputFile;
    int countOfRecords{ 0 };
    int choice{ 0 };
	ListOfDVDs records;
	DVDCollection dvd(sizeOfRecords);
    bool keepLooping{ true };


    while (keepLooping)
    {
	   records.countNumberOfFiles(countOfRecords, sizeOfRecords);
	   displayMenu(choice);
	   records.determineNumberOfRecordsInFile(dvd, inFile, countOfRecords);
	   switch (choice)
	   {
	   case 1: 
		   if (records.notFull(countOfRecords, sizeOfRecords))
		   {
			   cout << "You chose to add a movie.\n";
			   dvd.displayDVDList(countOfRecords);
			   records.addRecord(dvd, outputFile, countOfRecords, sizeOfRecords);
			   //dvd.displayDVDList(countOfRecords);
			   keepLooping = true;
			   break;
		   }
		   else
		   {
			   dvd.displayDVDList(countOfRecords);
			   break;
		   }
			   //break;
			   //cout << "You chose to add a movie.\n";
			   //dvd.displayDVDList(countOfRecords);
			   //records.addRecord(dvd, outputFile, countOfRecords, sizeOfRecords);
			   //dvd.displayDVDList(countOfRecords);
			   //keepLooping = true;
			   //break;
	   case 2: cout << "You chose to delete a movie.\n";
		  dvd.displayDVDList(countOfRecords);
		  records.deleteRecord(dvd, outputFile, dvd.selectRow(countOfRecords), countOfRecords, sizeOfRecords);
		  dvd.displayDVDList(countOfRecords);
		  keepLooping = true;
		  break;

	   case 3: cout << "You chose to update a movie.\n";
		  dvd.displayDVDList(countOfRecords);
		  records.updateRecord(dvd, outputFile, dvd.selectRow(countOfRecords), countOfRecords, sizeOfRecords);
		  dvd.displayDVDList(countOfRecords);
		  keepLooping = true;
		  break;

	   case 4: cout << "You chose to display the contents of the records.\n";
		  dvd.displayDVDList(countOfRecords);
		  keepLooping = true;
		  break;

	   case 5: cout << "Closing the program...\n"; 
		  keepLooping = false;
		  break;

	   default: cout << "Please choose between 1-5\n"; 
		  keepLooping = true;
	   }
    }

    return 0;
}

void displayMenu(int &choice)
{
    cout << "\n            DVD Collection\n";
    cout << "-----------------------------------------\n";
    cout << "1) Add movie information\n";
    cout << "2) Delete one movie record\n";
    cout << "3) Update the movie record\n";
    cout << "4) Display the information for the DVDs in the collection.\n";
    cout << "5) Exit the program\n\n";
    cout << "Enter your choice: ";
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
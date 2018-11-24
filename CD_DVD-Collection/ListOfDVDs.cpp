#include "DVDCollection.h"
#include "listOfDVDs.h"
#include <iostream>
#include <memory>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::left;
using std::ios;
using std::unique_ptr;
using std::to_string;
using std::stoi;


bool ListOfDVDs::notFull(int count, const int sizeOfRecords)
{
	if (count != sizeOfRecords)
		return true;
	else
		return false;
}


void ListOfDVDs::countNumberOfFiles(int& count, const int sizeOfRecords)
{
    ifstream inFile;
    inFile.open("record.txt");
    string title, length, actors;
    int year{ 0 };

    count = 0;
    while (getline(inFile, title, '\n') && count < sizeOfRecords)
	   count++;

	if (count == 0)
		cout << "\nThe file is empty.\n";

	else if (count < sizeOfRecords)
		cout << "\nThere are " << count << " records in the file...\n";

	else if (count == sizeOfRecords)
	{
		//notFull(count, sizeOfRecords);
		cout << "\n***The file is full.***\n";
	}

    inFile.close();
}

void ListOfDVDs::determineNumberOfRecordsInFile(DVDCollection &countRecordsInFile, ifstream& inFile, int countOfRecords)
{
    unique_ptr<string[]> title(new string[countOfRecords]);
    unique_ptr<string[]> length(new string[countOfRecords]);
    unique_ptr<string[]> year(new string[countOfRecords]);
    unique_ptr<string[]> firstActors(new string[countOfRecords]);
	unique_ptr<string[]> secondActors(new string[countOfRecords]);

    inFile.open("record.txt");

    for (int count = 0; count < countOfRecords; count++)
    {
	   int counttimeDivider{ 0 };
	   getline(inFile, title[count], '\t');
	   countRecordsInFile.setMovieTitle(count, title[count]);
	   getline(inFile, length[count], '\t');

	   for (unsigned int pos = 0; pos < length[count].size(); pos++)
	   {
		  if (!isdigit(length[count].at(pos)))
		  {
			 counttimeDivider++;
		  }
	   }

	   if (counttimeDivider == 0)
	   {
		  int totalMins = stoi(length[count]);
		  int min = ((totalMins % 60));
		  int hrs = { totalMins / 60 };

		  string hour = to_string(hrs);
		  string minutes = to_string(min);

		  if (min < 10)
		  {
			 hour.append(":");
			 hour.append(1, '0');
			 hour.append(minutes);
			 length[count] = hour;
		  }
		  else
		  {
			 hour.append(":");
			 hour.append(minutes);
			 length[count] = hour;
		  }

		  countRecordsInFile.setMovieLength(count, length[count]);
		  getline(inFile, year[count], '\t');
		  countRecordsInFile.setMovieYear(count, year[count]);
		  getline(inFile, firstActors[count], '\t');
		  countRecordsInFile.setFirstActors(count, firstActors[count]);
		  getline(inFile, secondActors[count], '\n');
		  countRecordsInFile.setSecondActors(count, secondActors[count]);
	   }

	   else
	   {
		  countRecordsInFile.setMovieLength(count, length[count]);
		  getline(inFile, year[count], '\t');
		  countRecordsInFile.setMovieYear(count, year[count]);
		  getline(inFile, firstActors[count], '\t');
		  countRecordsInFile.setFirstActors(count, firstActors[count]);
		  getline(inFile, secondActors[count], '\n');
		  countRecordsInFile.setSecondActors(count, secondActors[count]);
	   }

    }
    inFile.close();
    //countRecordsInFile.displayDVDList(countOfRecords);
}

void ListOfDVDs::addRecord(DVDCollection& dvd, ofstream& outputFile, int& countOfRecords, const int sizeOfRecords)
{
    unique_ptr<string[]> title(new string[sizeOfRecords]);
    unique_ptr<string[]> length(new string[sizeOfRecords]);
    unique_ptr<string[]> year(new string[sizeOfRecords]);
	unique_ptr<string[]> firstName(new string[sizeOfRecords]);
	unique_ptr<string[]> secondActors(new string[sizeOfRecords]);

    cin.ignore();
    cout << "Movie Entry " << countOfRecords + 1 << " of " << sizeOfRecords;
    cout << "\nWhat is the movie title?>>> ";
    getline(cin, title[countOfRecords]);
    dvd.setMovieTitle(countOfRecords, title[countOfRecords]);
    cout << "What is the length of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
    getline(cin, length[countOfRecords]);

    for (unsigned int pos = 0; pos < length[countOfRecords].size(); pos++)
    {

	   if (isdigit(length[countOfRecords].at(pos)))
		  continue;

	   else
	   {
		  cout << "Your input [" << length[countOfRecords] << "] is the wrong format.\n";
		  cout << "Please, input it in the digits format (i.e. 123).\n";
		  cout << "Try again.\n";
		  cout << "What is the length of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
		  getline(cin, length[countOfRecords]);
	   }
    }

    int totalMins = stoi(length[countOfRecords]);
    int min = ((totalMins % 60));
    int hrs = { totalMins / 60 };

    string hour = to_string(hrs);
    string minutes = to_string(min);

    if (min < 10)
    {
	   hour.append(":");
	   hour.append(1, '0');
	   hour.append(minutes);
	   length[countOfRecords] = hour;
    }
    else
    {
	   hour.append(":");
	   hour.append(minutes);
	   length[countOfRecords] = hour;
    }

    dvd.setMovieLength(countOfRecords, length[countOfRecords]);
    cout << "What is the year of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
    getline(cin, year[countOfRecords]);

    while (year[countOfRecords].size() != 4)
    {
	   cout << "Your input [" << year[countOfRecords] << "] is the wrong format.\n";
	   cout << "Please, input it in the digits format (i.e. 1987).\n";
	   cout << "Try again.\n";
	   cout << "What is the year of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
	   getline(cin, year[countOfRecords]);
    }

    for (unsigned int pos = 0; pos < 4; pos++)
    {

	   if (isdigit(year[countOfRecords].at(pos)))
		  continue;

	   else
	   {
		  cout << "Your input [" << year[countOfRecords] << "] is the wrong format.\n";
		  cout << "Please, input it in the digits format (i.e. 1987).\n";
		  cout << "Try again.\n";
		  cout << "What is the year of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
		  getline(cin, year[countOfRecords]);
	   }
    }

    dvd.setMovieYear(countOfRecords, year[countOfRecords]);
    cout << "What is the first actor/actress name of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
    getline(cin, firstName[countOfRecords]);
    dvd.setFirstActors(countOfRecords, firstName[countOfRecords]);
	cout << "What is the second actor/actress name of " << dvd.getMovieTitle(countOfRecords) << " >>> ";
	getline(cin, secondActors[countOfRecords]);
	dvd.setSecondActors(countOfRecords, secondActors[countOfRecords]);

    if (countOfRecords < (sizeOfRecords - 1))
	   cout << "Press the [ENTER] Key to continue...";

    else
	   dvd.displayDVDList(sizeOfRecords);

    countOfRecords++;
    dvd.outPutFile(outputFile, countOfRecords);

}

void ListOfDVDs::deleteRecord(DVDCollection& dvd, ofstream& outputFile, int element, int& countOfRecords, const int sizeOfRecords)
{

    if (element == sizeOfRecords)
    {
	   dvd.setMovieTitle(element - 1, "");
	   dvd.setMovieLength(element - 1, "");
	   dvd.setMovieYear(element - 1, "");
	   dvd.setFirstActors(element - 1, "");
	   dvd.setSecondActors(element - 1, "");
    }

    else
    {
	   while (dvd.getMovieTitle(element - 1) == "" || element < sizeOfRecords)
	   {
		  dvd.setMovieTitle(element - 1, dvd.getMovieTitle(element));
		  dvd.setMovieLength(element - 1, dvd.getMovieLength(element));
		  dvd.setMovieYear(element - 1, dvd.getMovieYear(element));
		  dvd.setFirstActors(element - 1, dvd.getFirstActors(element));
		  dvd.setSecondActors(element - 1, dvd.getSecondActors(element));
		  element++;
	   }
	   dvd.setMovieTitle((sizeOfRecords - 1), "");
	   dvd.setMovieLength((sizeOfRecords - 1), "");
	   dvd.setMovieYear((sizeOfRecords - 1), "");
	   dvd.setFirstActors((sizeOfRecords - 1), "");
	   dvd.setSecondActors((sizeOfRecords - 1), "\n");
    }
    countOfRecords--;

    outputFile.open("record.txt", ios::trunc);
    for (int count = 0; count < (countOfRecords); count++)
	   outputFile << left << dvd.getMovieTitle(count) << "\t" << dvd.getMovieLength(count)
	   << "\t" << dvd.getMovieYear(count) << "\t" << dvd.getFirstActors(count) <<"\t" << dvd.getSecondActors(count) << '\n';

    outputFile << "";

    outputFile.close();
}

void ListOfDVDs::updateRecord(DVDCollection& dvd, ofstream& outputFile, int recordsToUpdate, int countOfRecords, const int sizeOfRecords)
{
    unique_ptr<string[]> title(new string[sizeOfRecords]);
    unique_ptr<string[]> length(new string[sizeOfRecords]);
    unique_ptr<string[]> year(new string[sizeOfRecords]);
	unique_ptr<string[]> firstActors(new string[sizeOfRecords]);
	unique_ptr<string[]> secondActors(new string[sizeOfRecords]);

    cin.ignore();
    cout << "Update Movie Info on # " << recordsToUpdate << " of " << sizeOfRecords;
    cout << "\nWhat is the movie title?>>> ";
    getline(cin, title[recordsToUpdate - 1]);
    dvd.setMovieTitle(recordsToUpdate - 1, title[recordsToUpdate - 1]);
    cout << "What is the length of " << dvd.getMovieTitle(recordsToUpdate - 1) << " >>> ";
    getline(cin, length[recordsToUpdate - 1]);

    for (unsigned int pos = 0; pos < length[recordsToUpdate - 1].size(); pos++)
    {
	   if (isdigit(length[recordsToUpdate - 1].at(pos)))
		  continue;

	   else
	   {
		  cout << "Your input [" << length[recordsToUpdate - 1] << "] is the wrong format.\n";
		  cout << "Please, input it in the digits format (i.e. 123).\n";
		  cout << "Try again.\n";
		  cout << "What is the length of " << dvd.getMovieTitle(recordsToUpdate - 1) << " >>> ";
		  getline(cin, length[recordsToUpdate - 1]);
	   }
    }

    int totalMins = stoi(length[recordsToUpdate - 1]);
    int min = ((totalMins % 60));
    int hrs = { totalMins / 60 };

    string hour = to_string(hrs);
    string minutes = to_string(min);

    if (min < 10)
    {
	   hour.append(":");
	   hour.append(1, '0');
	   hour.append(minutes);
	   length[recordsToUpdate - 1] = hour;
    }
    else
    {
	   hour.append(":");
	   hour.append(minutes);
	   length[recordsToUpdate - 1] = hour;
    }

    dvd.setMovieLength(recordsToUpdate - 1, length[recordsToUpdate - 1]);
    cout << "What is the year of " << dvd.getMovieTitle(recordsToUpdate - 1) << " >>> ";
    getline(cin, year[recordsToUpdate - 1]);

    for (unsigned int pos = 0; pos < 4; pos++)
    {
	   if (isdigit(year[recordsToUpdate - 1].at(pos)))
		  continue;

	   else
	   {
		  cout << "Your input [" << year[recordsToUpdate - 1] << "] is the wrong format.\n";
		  cout << "Please, input it in the digits format (i.e. 1987).\n";
		  cout << "Try again.\n";
		  cout << "What is the year of " << dvd.getMovieTitle(recordsToUpdate - 1) << " >>> ";
		  getline(cin, year[recordsToUpdate - 1]);
	   }
    }

    dvd.setMovieYear(recordsToUpdate - 1, year[recordsToUpdate - 1]);
	cout << "What is the first actor/actress name of " << dvd.getMovieTitle(recordsToUpdate - 1) << " >>> ";
	getline(cin, firstActors[recordsToUpdate - 1]);
	dvd.setFirstActors(recordsToUpdate - 1, firstActors[recordsToUpdate - 1]);
	cout << "What is the second actor/actress name of " << dvd.getMovieTitle(recordsToUpdate - 1) << " >>> ";
	getline(cin, secondActors[recordsToUpdate - 1]);
	dvd.setSecondActors(recordsToUpdate - 1, secondActors[recordsToUpdate - 1]);

    dvd.outPutFile(outputFile, countOfRecords);

}
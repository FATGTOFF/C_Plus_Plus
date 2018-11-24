#include "CD Collection.h"
#include <iostream>
#include <iomanip>
#include <memory>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::left;
using std::setw;
using std::ios;

DVDCollection::DVDCollection(int size)
{
    numElements = size;
    titleOfTheMovie = new string[size];
    lengthOfTheMovie = new string[size];
    yearOfTheMovie = new string[size];
    namesOfActors = new string[(size)];
    for (int count = 0; count < size; count++)
    {
	   titleOfTheMovie[count] = "";
	   lengthOfTheMovie[count] = "";
	   yearOfTheMovie[count] = "";
	   namesOfActors[count] = "";
    }

}

DVDCollection::~DVDCollection()
{
    delete[] titleOfTheMovie;
    titleOfTheMovie = nullptr;
    delete[] lengthOfTheMovie;
    lengthOfTheMovie = nullptr;
    delete[] yearOfTheMovie;
    yearOfTheMovie = nullptr;
    delete[] namesOfActors;
    namesOfActors = nullptr;

}

bool DVDCollection::isValid(int element) const
{
    bool status{ true };

    if (element < 0 || element >= numElements)
	   status = false;
    else
	   status = true;
    return status;
}

void DVDCollection::displayDVDList(int element)
{
    cout << endl;
    cout << left << setw(3) << "#" << setw(24) << "Movie Title" << setw(7) << "Length" << setw(10)
	   << "Year" << setw(20) << "Actors/Actress" << endl;

    for (int count = 0; count < element; count++)
    {
	   if (getMovieTitle(count) != "")
		  cout << left << setw(3) << count + 1 << setw(24) << getMovieTitle(count) << setw(7) << getMovieLength(count)
			 << setw(10) << getMovieYear(count) << setw(25) << getActors(count) << endl;
    }

}


void DVDCollection::setMovieTitle(int element, string title)
{
    if (isValid(element))
	   titleOfTheMovie[element] = title;
    else
	   cout << "Error: Invalid subscript\n";
}

void DVDCollection::setMovieLength(int element, string length)
{
    if (isValid(element))
	   lengthOfTheMovie[element] = length;
    else
	   cout << "Error: Invalid subscript\n";
}

void DVDCollection::setMovieYear(int element,string year)
{
    if (isValid(element))
	   yearOfTheMovie[element] = year;
    else
	   cout << "Error: Invalid subscript\n";
}

void DVDCollection::setActors(int element, string name)
{
    if (isValid(element))
	   namesOfActors[element] = name;
    else
	   cout << "Error: Invalid subscript\n";
}

string DVDCollection::getMovieTitle(int element) const
{
    if (isValid(element))
	   return titleOfTheMovie[element];
    else
	   return "Error: Invalid subscript\n";
}

string DVDCollection::getMovieLength(int element) const
{
    if (isValid(element))
	   return lengthOfTheMovie[element];
    else
	   return "Error: Invalid subscript\n";
}

string DVDCollection::getMovieYear(int element) const
{
    if (isValid(element))
	   return yearOfTheMovie[element];
    else
	   return "Error: Invalid subscript\n";
}

string DVDCollection::getActors(int element) const
{
    if (isValid(element))
	   return namesOfActors[element];
    else
	   return "Error: Invalid subscript\n";
}

int DVDCollection::selectRow() const
{
    int num{ 0 };
    cout << "Select the Row. >>>";
    cin >> num;

    return num;
}

void DVDCollection::outPutFile(ofstream& outputFile, const int sizeOfRecords)
{
    outputFile.open("record.txt", ios::trunc);
    for (int count = 0; count < (sizeOfRecords); count++)
		  outputFile << left << getMovieTitle(count) << "\t" << getMovieLength(count)
		  << "\t" << getMovieYear(count) << "\t" << getActors(count) << '\n';

    outputFile.close();
}

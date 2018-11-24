#ifndef DVDCOLLECTION_H
#define DVDCOLLECTION_H

#include <string>
#include <fstream>
using std::string;
using std::ofstream;

class DVDCollection
{
private:
    string *titleOfTheMovie;
    string *lengthOfTheMovie; // Change it from String to int.
    string *yearOfTheMovie;// Change it from String to int.
    string *namesOfFirstActors;
	string *namesOfSecondActors;
    int numElements;

public:
    // Constructor
    //DVDCollection();
    DVDCollection(int);
    ~DVDCollection();

    //Setters
    void setMovieTitle(int, string);
    void setMovieLength(int, string);
    void setMovieYear(int, string);
    void setFirstActors(int, string);
	void setSecondActors(int, string);
    void outPutFile(ofstream&, const int);
    int selectRow(int) /*const*/;

    //Getters.
    string getMovieTitle(int) const;
    string getMovieLength(int) const;
    string getMovieYear(int) const;
    string getFirstActors(int) const;
	string getSecondActors(int) const;
    bool isValid(int) const;
    void displayDVDList(int);


};
#endif
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
    string *namesOfActors;
    int numElements;

public:
    // Constructor
    DVDCollection();
    DVDCollection(int);
    ~DVDCollection();

    //Setters
    void setMovieTitle(int, string);
    void setMovieLength(int, string);
    void setMovieYear(int, string);
    void setActors(int, string);
    void outPutFile(ofstream&, const int);
    int selectRow() const;

    //Getters.
    string getMovieTitle(int) const;
    string getMovieLength(int) const;
    string getMovieYear(int) const;
    string getActors(int) const;
    bool isValid(int) const;
    void displayDVDList(int);


};
#endif
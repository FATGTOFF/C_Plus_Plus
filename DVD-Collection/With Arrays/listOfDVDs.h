#ifndef LISTOFDVDS_H
#define LISTOFDVDS_H
#include "DVDCollection.h"
using std::ifstream;


class ListOfDVDs
{
public:

	bool notFull(int, const int);
    void countNumberOfFiles(int&, const int);
    void determineNumberOfRecordsInFile(DVDCollection &, ifstream&, int);
    void addRecord(DVDCollection&,ofstream&, int&, const int);
    void deleteRecord(DVDCollection&, ofstream&, int, int&, const int);
    void updateRecord(DVDCollection&, ofstream&, int, int, const int);
}; 
#endif
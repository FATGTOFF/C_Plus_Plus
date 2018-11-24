/****************************************************************************
Header for the FileNotFound class.

Carlos Vazquez

This is an exception class that will have a data member that is a string
value called fileName. This data member will be set in the constructor via the
parameter. It provides a member function called getFileName which
returns fileName data member.
The class has the following constructors:
- A default constructor that sets the data members' value to 0.

This class contains the following data members:
- fileName (It is called when the exception is thrown)
****************************************************************************/
#ifndef FILENOTFOUND_H
#define FILENOTFOUND_H
#include<iostream>
#include<string>
using namespace std;


class FileNotFound
{
private:

	string fileName;

public:

	FileNotFound(string);

	string getFileName();

};
#endif
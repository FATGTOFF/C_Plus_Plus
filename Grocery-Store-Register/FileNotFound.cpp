//Implementation for FileNotFound class.
#include <iostream>
#include <string>
#include "FileNotFound.h"
using namespace std;


/****************************************************************************
Constructor: FileNotFound - accepts an argument  to record the file name.

Input Parameters:  fileName.
****************************************************************************/
FileNotFound::FileNotFound(string fn)
{
	fileName = fn;
}

/****************************************************************************
Function name:  getFileName

Description:	This function returns the file name from the user input.

Input Parameters:  None.

Return Type:  string
****************************************************************************/
string FileNotFound::getFileName()
{
	return fileName;
}
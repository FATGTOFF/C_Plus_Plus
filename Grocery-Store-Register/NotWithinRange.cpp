// Implementation file for the NotWithinRange class
#include <iostream>
#include "NotWithinRange.h"
using namespace std;

/****************************************************************************
Constructor: NotWithinRange(s) - accepts an argument  to record the times.

Input Parameters:  times.
****************************************************************************/
NotWithinRange::NotWithinRange(int t)
{
	times = t;
}

/****************************************************************************
Function name:  getNumberofTimes

Description:	This function returns the times from the user input.

Input Parameters:  None.

Return Type:  int
****************************************************************************/
int NotWithinRange::getNumberofTimes()
{
	return times;
}
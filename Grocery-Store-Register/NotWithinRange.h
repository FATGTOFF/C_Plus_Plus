/****************************************************************************
Header for the NotWithinRange class.

Carlos Vazquez

This is an exception class that will have a data member that is an integer
value called times. This data member will be set in the constructor via the
parameter. It provides a member function called getNumberofTimes which
returns times data member.
The class has the following constructors:
- A default constructor that sets the data members' value to 0.

This class contains the following data members:
- times (It is called when the exception is thrown)
****************************************************************************/
#ifndef NOTWITHINRANGE_H
#define NOTWITHINRANGE_H

using namespace std;

class NotWithinRange 
{
private:
	int times;

public:

	NotWithinRange(int);

	int getNumberofTimes();

};
#endif
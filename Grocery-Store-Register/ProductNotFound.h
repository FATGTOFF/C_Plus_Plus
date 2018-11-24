/****************************************************************************
Header for the ProductNotFound class.

Carlos Vazquez

This is an exception class that will have a data member that is a int
value called productNumber. This data member will be set in the constructor via the
parameter. It provides a member function called getProductName which
returns productNumber data member.
The class has the following constructors:
- A default constructor that sets the data members' value to 0.

This class contains the following data members:
- productNumber (It is called when the exception is thrown)
****************************************************************************/
#ifndef PRODUCTNOTFOUND_H
#define PRODUCTNOTFOUND_H
#include<iostream>
using namespace std;

class ProductNotFound
{
private:

	int productNumber;

public:

	ProductNotFound(int);

	int getProductNumber();

};
#endif
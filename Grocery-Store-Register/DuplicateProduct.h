/****************************************************************************
Header for the DuplicateProduct class.

Carlos Vazquez

This is an exception class that will have a data member that is an integer
value called productNumber. This data member will be set in the constructor via the
parameter. It provides a member function called getProductNumber which
returns productNumber data member.
The class has the following constructors:
- A default constructor that sets the data members' value to 0.

This class contains the following data members:
- productNumber (It is called when the exception is thrown)
****************************************************************************/
#ifndef DUPLICATEPRODUCT_H
#define DUPLICATEPRODUCT_H
#include<iostream>
using namespace std;


class DuplicateProduct
{
private:

	int productNumber;

public:

	DuplicateProduct(int);

	int getProductNumber();

};
#endif
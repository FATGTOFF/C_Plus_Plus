//Implementation of the ProductNotFound class.
#include <iostream>
#include "ProductNotFound.h"
using namespace std;

/****************************************************************************
Constructor: ProductNotFound - accepts an argument  to record the product
Number.

Input Parameters:  productNumber.
****************************************************************************/
ProductNotFound::ProductNotFound(int pn)
{
	productNumber = pn;
}

/****************************************************************************
Function name:  getProductNumber

Description:	This function returns the product number from the user input.

Input Parameters:  None.

Return Type:  int
****************************************************************************/
int ProductNotFound::getProductNumber()
{
	return productNumber;
}
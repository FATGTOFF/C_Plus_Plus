//Implementation for DuplicateProduct class.
#include <iostream>
#include "DuplicateProduct.h"
using namespace std;

/****************************************************************************
Constructor: DuplicateProduct - accepts an argument  to record the product
Number.

Input Parameters:  productNumber.
****************************************************************************/
DuplicateProduct::DuplicateProduct(int pn)
{
	productNumber = pn;

}

/****************************************************************************
Function name:  getProductNumber

Description:	This function returns the product number from the user input.

Input Parameters:  None.

Return Type:  int
****************************************************************************/
int DuplicateProduct::getProductNumber()
{
	return productNumber;
}
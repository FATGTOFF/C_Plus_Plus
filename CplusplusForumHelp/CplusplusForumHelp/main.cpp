#include "NumDays.h"
#include <iostream>

int main()
{
	NumDays A(8);
	NumDays B(12);
	NumDays C;

	C = A + B;

	NumDays D;
	D.setHours(8);
	NumDays E;
	E.setHours(12);
	NumDays G;

	G = D + E;

	return 0;
}
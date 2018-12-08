#include <iostream>

int rounds(float);
void print_int(float[], int);

int main()
{
	float a[5]{3.45,7.89,3.32,1.11,4.56};
	print_int(a,5);
}
void print_int(float a[] , int sz)
{
	for (int count = 0; count < sz; count++)
			std::cout << rounds(a[count]) << std::endl;
}

int rounds(float x)
{
	return x + (x < 0 ? -0.5 : +0.5); //rounds float to nearest int and //returns int value
}
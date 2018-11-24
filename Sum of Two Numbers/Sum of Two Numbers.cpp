//1. Sum of Two Numbers
//Write a program that stores the integers 50 and 100 in variables, and stores the sum of
//these two in a variable named total .
#include <iostream>

int main()
{
    int var1{ 50 };
    int var2{ 100 };
    int total{ 0 };

    total = var1 + var2;
    std::cout << "The sum of " << var1 << " and " << var2 << " is " << total << std::endl;
    return 0;
}

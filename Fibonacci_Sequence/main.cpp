#include <iostream>

int main()
{
	unsigned long long termSequence = 100; // n.
	unsigned long long termNumber = 0; // Xn
	unsigned long long previousTerm = 0; // Xn-1. It is the starting point for the Fibonacci Sequence
	unsigned long long termBeforePreviousTerm = 0; //Xn-2.

	unsigned long long count = 0;
	while (count <= termSequence)
	{
		// To create the sequence, 
		// 0 comes before 1 (the first term), so 1 + 0 = 1.
		// The rule is Xn = (Xn-1) + (Xn-2)
		if (1 == count)
		{
			termNumber = 1;
		}
		else // Any integer number higher than 1.
		{
			termBeforePreviousTerm = previousTerm;
			previousTerm = termNumber;
			termNumber = previousTerm + termBeforePreviousTerm;
		}

		//std::cout << termNumber << " ";
		std::cout << termNumber << std::endl;

		count++;
	}

	//std::cout << "Enter the term sequence: ";
	//std::cin >> termSequence;
	//for (unsigned int count = 0; count < termSequence; count++)
	//{
	//	// To create the sequence, 
	//	// 0 comes before 1 (the first term), so 1 + 0 = 1.
	//	// The rule is Xn = (Xn-1) + (Xn-2)
	//	if (1 == count)
	//	{
	//		termNumber = 1;
	//	}
	//	else // Any integer number higher than 1.
	//	{
	//		termBeforePreviousTerm = previousTerm;
	//		previousTerm = termNumber;
	//		termNumber = previousTerm + termBeforePreviousTerm;
	//	}

	//}
	//std::cout << "n: " << termSequence
	//	<< "\tXn: " << termNumber << std::endl;
}
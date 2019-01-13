#include <iostream>
#include <string>
#include "bankAccount.h"

int main()
{
	const int numOfElements{5};
	BankAccount account[numOfElements]{};
	
	account[0].setAccountHolderName("John Smith");
	account[0].setAccountType("Savings");
	account[0].setBalance(12000);
	account[0].setInterestRate(2.5);

	account[1].setAccountHolderName("Sylvester Stallone");
	account[1].setAccountType("Checking");
	account[1].setBalance(1254400.36);
	account[1].setInterestRate(0.5);

	account[2].setAccountHolderName("Arnold LastName");
	account[2].setAccountType("Savings");
	account[2].setBalance(123650);
	account[2].setInterestRate(4.75);

	account[3].setAccountHolderName("Steven Spielberg");
	account[3].setAccountType("Checking");
	account[3].setBalance(564235.33);
	account[3].setInterestRate(6.5);

	account[4].setAccountHolderName("Bugs Bunny");
	account[4].setAccountType("Savings");
	account[4].setBalance(477415.11);
	account[4].setInterestRate(5.25);


	for (int count = 0; count < numOfElements; count++)
		account[count].print();

	//account[0].print();
	
	return 0;
}
#include <iostream>
#include "bankAccount.h"

// Definition of static member.
int BankAccount::assign = 4200;

BankAccount::BankAccount()
{
	holdersName = "";
	accountType = "";
	balance = 0.0;
	interestRate = 0.0;
	accountNumber = assign;
	assign++;

}

BankAccount::BankAccount(std::string n, std::string t, double b, double r)
{
	holdersName = n;
	accountType = t;
	balance = b;
	interestRate = r; // Decimal value.
	accountNumber = assign;
	assign++;

}

void BankAccount::deposit(double d)
{
	balance += d;
}

void BankAccount::withdraw(double w)
{
	balance -= w;
}

void BankAccount::updateBalance()
{
	balance += getInterest();
}

void BankAccount::print()
{
	char endline{'\n'};
	std::cout << "====================================" << endline;
	std::cout << "Account Number: " << getAccountNumber() << endline;
	std::cout << "Account Name: " << getAccountHolderName() << endline;
	std::cout << "Account Type: " << getAccountType() << endline;
	std::cout << "Balance: " << getBalance() << endline;
	std::cout << "Interest Rate: " << getInterestRate() << endline;
	std::cout << "====================================" << endline;
}

void BankAccount::setAccountHolderName(std::string n)
{
	holdersName = n;
}

void BankAccount::setAccountType(std::string a)
{
	accountType = a;
}

void BankAccount::setBalance(double b)
{
	balance = b;
}

void BankAccount::setInterestRate(double r)
{
	interestRate = r;
}

double BankAccount::getInterest() const
{
	return balance * interestRate;
}

int BankAccount::getAccountNumber() const
{
	return accountNumber;
}

std::string BankAccount::getAccountHolderName() const
{
	return holdersName;
}

std::string BankAccount::getAccountType() const
{
	return accountType;
}

double BankAccount::getBalance() const
{
	return balance;
}

double BankAccount::getInterestRate() const
{
	return interestRate;
}

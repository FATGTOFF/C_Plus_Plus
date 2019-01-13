#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount
{
	private:
		std::string holdersName;
		int accountNumber;
		std::string accountType;
		double balance;
		double interestRate; // Decimal value.
		static int assign;

	public:
		BankAccount();
		BankAccount(std::string, std::string, double, double);

		void deposit(double);
		void withdraw(double);
		void updateBalance();
		void print();
		void setAccountHolderName(std::string);
		void setAccountType(std::string);
		void setBalance(double);
		void setInterestRate(double);

		double getInterest() const;
		int getAccountNumber() const;
		std::string getAccountHolderName() const;
		std::string getAccountType() const;
		double getBalance() const;
		double getInterestRate() const;

};

#endif

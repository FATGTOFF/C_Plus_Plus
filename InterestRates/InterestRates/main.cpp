#include <iostream>
#include <iomanip>

int main()
{
	double initialDeposit{};
	double minRate{};
	double maxRate{};
	double subTotal{};
	double balance{};

	std::cout <<"Deposit: ";
	std::cin >> initialDeposit;

	std::cout << "Minimum rate(in decimal form): ";
	std::cin >> minRate;

	std::cout << "Maximum rate(in decimal form): ";
	std::cin >> maxRate;

	std::cout << std::fixed << std::setprecision(2);

	/*
		Set a nested for loop. The outer loop use the minimum rate and the maximum rate as the initial parameters
		of the outer foor loop. It uses the static cast from the double variable to the integer to count the loop
		as integers.
	*/
	for (int count = static_cast<int>(minRate * 100); count <= static_cast<int>(maxRate * 100); count++)
	{
		balance = initialDeposit;
		std::cout << "\nRate " << count << "%";

		/*
			The inner loop is to display the years and perform the calculations to obtain the balance each year.
		*/
		for (int countYr = 1; countYr < 4; countYr++)
		{
			std::cout << "\nYear " << countYr << ": $";
			subTotal = balance * (count * .01);
			balance += subTotal;

			std::cout << balance;
		}

	}

	return 0;
}
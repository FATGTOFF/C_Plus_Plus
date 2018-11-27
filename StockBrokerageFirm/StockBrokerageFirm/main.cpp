#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

void get_Data(std::string&, double&, char&, char&);
void validate_Transaction_Type(char&);
void validate_Transaction_Exchange(char&);
void validate_Amount_Input(double&);
double purchase_Transaction_Amount(char, double);
double sales_Transaction_Amount(char, double);


int main()
{
	char transaction_type{};
	char transaction_exchange{};
	std::string broker_name{};
	double amount_transaction{};
	bool keepLooping{ true };
	char tryAgain{};
	int counter_salesman{ 0 };
	int counter_transaction{ 0 };
	double running_total{ 0 };


	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	while (keepLooping)
	{
		get_Data(broker_name, amount_transaction, transaction_type, transaction_exchange);

		if (transaction_type == 'P')
		{
			std::cout << '\n' << broker_name << " has earned $"
			<< purchase_Transaction_Amount(transaction_exchange, amount_transaction)
			<< " in commisions on $" << amount_transaction << std::endl;
			running_total += purchase_Transaction_Amount(transaction_exchange, amount_transaction);
			counter_transaction++;

		}

		else
		{
			std::cout << '\n' << broker_name << " has earned $"
			<< sales_Transaction_Amount(transaction_exchange, amount_transaction)
			<< " in commisions on $" << amount_transaction << std::endl;
			running_total += sales_Transaction_Amount(transaction_exchange, amount_transaction);
			counter_transaction++;
		}

		counter_salesman++;
		std::cout << "\nWould you like to enter another salesman? >>>";
		std::cin >> tryAgain;

		if (std::toupper(tryAgain) == 'Y')
			keepLooping = true;
		else
			keepLooping = false;
		std::cin.ignore();
	}
	std::cout << "Total salesmen processed: " << counter_salesman << std::endl;
	std::cout << "Total transactions for all salesmen " << counter_transaction << std::endl;
	std::cout << "Total commission for all salesmen $" << running_total << std::endl;

}

void get_Data(std::string& broker_name, double& amount_transaction, 
	char& transaction_type, char& transaction_exchange)
{
	std::cout << "\nWhat is the name of the broker making the transaction?>>> ";
	std::getline(std::cin, broker_name);
	std::cout << "\nWhat is the amount of the transaction? >>>";
	std::cin >> amount_transaction;
	validate_Amount_Input(amount_transaction);
	std::cout << "\nIs the transaction a purchase (P) or sale (S) P/S? >>>";
	std::cin >> transaction_type;
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	validate_Transaction_Type(transaction_type);
	std::cout << "\nWhere the transaction took place?\n";
	std::cout << "N = New York Exchange, A = American Stock Exchange, O = Over the Counter:>>>";
	std::cin >> transaction_exchange;
	std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	validate_Transaction_Exchange(transaction_exchange);

}

void validate_Transaction_Type(char& transaction_type)
{
	while (transaction_type != 'P' && transaction_type != 'S')
	{
		std::cout << "\nYour input " << transaction_type << " is incorrect.\n";
		std::cout << "Is the transaction a purchase (P) or sale (S) P/S? >>>";
		std::cin >> transaction_type;
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	}
}

void validate_Transaction_Exchange(char& transaction_exchange)
{
	while (transaction_exchange != 'N' && transaction_exchange != 'A' && transaction_exchange != 'O')
	{
		std::cout << "\nYour input " << transaction_exchange << " is incorrect.\n";
		std::cout << "Where the transaction took place?\n";
		std::cout << "N = New York Exchange, A = American Stock Exchange, O = Over the Counter:>>>";
		std::cin >> transaction_exchange;
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	}
}

void validate_Amount_Input(double& amount_transaction)
{
	while (amount_transaction < 0)
	{
		std::cout << "\nYour input " << amount_transaction << " is incorrect.\n";
		std::cout << "\nWhat is the amount of the transaction? >>>";
		std::cin >> amount_transaction;
	}
}

double purchase_Transaction_Amount(char transaction_exchange, double amount_transaction)
{
	const double purchase_commission_NYSE{ .045 }; // 4.5 Percent.
	const double purchase_commission_AMSE{ .035 }; // 3.5 Percent.
	const double purchase_commission_Other{ .03 }; // 3 Percent.

	if (transaction_exchange == 'N')
		return amount_transaction * purchase_commission_NYSE;

	else if (transaction_exchange == 'A')
		return amount_transaction * purchase_commission_AMSE;

	return amount_transaction * purchase_commission_Other;
}

double sales_Transaction_Amount(char transaction_exchange, double amount_transaction)
{
	const double sale_commission_NYSE{ .025 }; // 2.5 Percent.
	const double sale_commission_Other{ .02 }; // 2 Percent.

	if (transaction_exchange == 'N')
		return amount_transaction * sale_commission_NYSE;

	return amount_transaction * sale_commission_Other;
}
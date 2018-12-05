#include <iostream>

struct User
{
	int userID;
	int password;
};

bool inputUserName(User&, int, int, const int);
void inputUserPassword(User&, int, int, const int, bool&);

int main()
{
	User user;
	int defaultUserID {12345};
	int defaultPassword {9876};
	int count{0};
	const int numOfTries{3};

	bool correctIDMatch{ inputUserName(user, defaultUserID, count, numOfTries) };

	bool correctPassMatch{ false };

	if (correctIDMatch)
	{
		inputUserPassword(user, defaultPassword, count, numOfTries, correctPassMatch);
	}
	else
	{
		std::cout << "Your account is locked\n";
		return 0;
	}

	if (correctIDMatch == correctPassMatch)
	{
		std::cout << "Login succesful for UserID: " << user.userID << std::endl;
		std::cout << "Please change your password.\n";
		std::cout << "Password: ";
		std::cin >> defaultPassword;
	}
	else
		std::cout << "Your account is locked\n";

	return 0;
}
bool inputUserName(User& user, int defaultUserID, int count, const int numOfTries)
{
	bool matched{false};

	std::cout << "UserID: ";
	std::cin >> user.userID;

	while (count < numOfTries)
	{
		if (user.userID != defaultUserID)
		{
			count++;
			std::cout << "Wrong UserID!!!\n";
			std::cout << "Number of tries left: " << numOfTries - count << std::endl;

			std::cout << "Username: ";
			std::cin >> user.userID;
		}
		else
		{
			matched = true;
			break;
		}

	}

	return matched;
}

void inputUserPassword(User& user, int defaultUserPassword, int count, const int numOfTries, bool& matched)
{

	std::cout << "Password: ";
	std::cin >> user.password;

	while (count < numOfTries)
	{
		if (user.password != defaultUserPassword)
		{
			count++;
			std::cout << "Wrong Password!!!\n";
			std::cout << "Number of tries left: " << numOfTries - count << std::endl;

			std::cout << "Password: ";
			std::cin >> user.password;

		}
		else
		{
			matched = true;
			break;
		}

	}

}
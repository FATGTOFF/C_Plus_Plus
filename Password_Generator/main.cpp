#include <iostream>
#include <cctype>
#include <cstdint>
#include <random>
#include <string>
#include <algorithm>
#include <limits>

constexpr bool PRINT_DEBUG{ false };
constexpr std::uint16_t minPasswordLength{ 8 };
constexpr std::uint16_t maxPasswordLength{ 16 };

// The symbols allow to be used in passwords.
constexpr char specialCharacters[]{
	'\'', '-', '!', '\"', '#', '$',
	'%', '&', '(', ')', '*', ',',
	'.', '/', ':', ';', '?', '@',
	'[', ']', '^', '_', '`', '{',
	'|', '}', '~', '+', '<', '=',
	'>'};

void printNewPassword(std::uint16_t, std::string&);
void randomizeUpperCaseLetters(std::uint16_t&, std::string&);
void randomizeLowerCaseLetters(std::uint16_t&, std::string&);
void randomizeSymbols(std::uint16_t&, std::string&);
void randomizeNumsForPasswords(std::uint16_t&, std::string&);
std::uint16_t randomNumber(std::uint16_t min, std::uint16_t max);
void inputNumberOnly(std::uint16_t&);

int main()
{

	bool keepLooping{ true };

	while (keepLooping)
	{
		std::cout << "Length of the Password to Generate" << " (Min: " << minPasswordLength
			<< " Max: " << maxPasswordLength << ") : ";
		std::uint16_t lengthOfPassword{};
		inputNumberOnly(lengthOfPassword);

		// Validate the user's input...
		while (lengthOfPassword < minPasswordLength || lengthOfPassword > maxPasswordLength)
		{
			std::cout << lengthOfPassword << " is not a valid input.\n";
			std::cout << "Length of the Password to Generate" << " (Min: " << minPasswordLength
				<< " Max: " << maxPasswordLength << ") : ";
			inputNumberOnly(lengthOfPassword);
		}

		std::string newPassword{};
		printNewPassword(lengthOfPassword, newPassword);

		if (PRINT_DEBUG)
		{
			std::cout << newPassword << "\tSize: " << newPassword.length() << std::endl;
		}
		else
		{
			std::cout << newPassword << std::endl;
		}


		std::cout << "Another Password?(Y/N): ";
		char tryAgain{};
		std::cin >> tryAgain;

		if ('Y' == std::toupper(tryAgain))
		{
			keepLooping = true;
		}
		else
		{
			keepLooping = false;
		}
	}
}

void printNewPassword(std::uint16_t lengthOfPassword, std::string& newPassword)
{

	while (lengthOfPassword > 0)
	{
		randomizeUpperCaseLetters(lengthOfPassword, newPassword);
		randomizeLowerCaseLetters(lengthOfPassword, newPassword);
		randomizeNumsForPasswords(lengthOfPassword, newPassword);
		randomizeSymbols(lengthOfPassword, newPassword);
	}

	// Let's shuffle the generated password before we print it.
	std::mt19937_64 rng(std::random_device{}());
	std::shuffle(newPassword.begin(), newPassword.end(), rng);

}

void randomizeUpperCaseLetters(std::uint16_t& lengthOfPassword, std::string& newPassword)
{
	// No reason to keep going if the length is 0.
	if (0 == lengthOfPassword)
	{
		return;
	}

	std::uint16_t numOfUpperCaseLetters{};

	if (lengthOfPassword > 1)
	{
		numOfUpperCaseLetters = randomNumber(1, 2);
	}
	else // If the length is 1
	{
		numOfUpperCaseLetters = 1;
	}

	lengthOfPassword -= numOfUpperCaseLetters;

	for (std::uint16_t count = 0; count < numOfUpperCaseLetters; ++count)
	{
		const char upperCaseLetter{ static_cast<char>(randomNumber(65, 90)) };
		newPassword.push_back(upperCaseLetter);
	}
}

void randomizeLowerCaseLetters(std::uint16_t& lengthOfPassword, std::string& newPassword)
{
	// No reason to keep going if the length is 0.
	if (0 == lengthOfPassword)
	{
		return;
	}

	std::uint16_t numOfLowerCaseLetters{};

	if (lengthOfPassword > 1)
	{
		numOfLowerCaseLetters = randomNumber(1, 2);
	}
	else // If the length is 1
	{
		numOfLowerCaseLetters = 1;
	}

	lengthOfPassword -= numOfLowerCaseLetters;

	for (std::uint16_t count = 0; count < numOfLowerCaseLetters; ++count)
	{
		const char lowerCaseLetter{ static_cast<char>(randomNumber(97, 122)) };
		newPassword.push_back(lowerCaseLetter);
	}
}

void randomizeSymbols(std::uint16_t& lengthOfPassword, std::string& newPassword)
{
	// No reason to keep going if the length is 0.
	if (0 == lengthOfPassword)
	{
		return;
	}

	std::uint16_t numOfSymbols{};

	if (lengthOfPassword > 1)
	{
		numOfSymbols = randomNumber(1, 2);
	}
	else // If the length is 1
	{
		numOfSymbols = 1;
	}

	lengthOfPassword -= numOfSymbols;

	for (std::uint16_t count = 0; count < numOfSymbols; ++count)
	{
		newPassword.push_back(specialCharacters[randomNumber(0, 30)]);
	}
}

void randomizeNumsForPasswords(std::uint16_t& lengthOfPassword, std::string& newPassword)
{
	// No reason to keep going if the length is 0.
	if (0 == lengthOfPassword)
	{
		return;
	}

	std::uint16_t numOfNumbers{};

	if (lengthOfPassword > 1)
	{
		numOfNumbers = randomNumber(1, 2);
	}
	else  // If the length is 1
	{
		numOfNumbers = 1;
	}

	lengthOfPassword -= numOfNumbers;

	for (std::uint16_t count = 0; count < numOfNumbers; ++count)
	{
		const char number{ static_cast<char>(randomNumber(48, 57)) };
		newPassword.push_back(number);
	}
}

std::uint16_t randomNumber(std::uint16_t min, std::uint16_t max)
{
	std::mt19937_64 rng(std::random_device{}());
	std::uniform_int_distribution<std::uint16_t> distrib(min, max);

	const std::uint16_t random = distrib(rng);

	return random;
}

void inputNumberOnly(std::uint16_t& num)
{
	while ((std::cin >> num).fail() || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Your choice is incorrect. Try again: ";
	}
}
#include <iostream>
#include <cctype>
#include <cstdint>
#include <bitset>

enum class PasswordRequirements : std::uint8_t
{
	BIT0_ALWAYS_SET   = 0x01,
	UPPERCASE_LETTERS = 0x02,
	LOWERCASE_LETTERS = 0x04,
	NUMBERS           = 0x08,
	SYMBOLS           = 0x10,
	ALL_OPTIONS_SET   = 0x1F
};


void set_bit(std::uint8_t&, std::uint8_t);
void clear_bit(std::uint8_t&, std::uint8_t);

int main()
{

	std::cout << "Size: " << sizeof(PasswordRequirements) << std::endl;

	char choice{};

	/* Bit 0 is always set to 1. */
	std::uint8_t passwordSetFlags{ static_cast<std::uint8_t>(PasswordRequirements::BIT0_ALWAYS_SET) };

	std::cout << "All options? (Y/N): ";
	std::cin >> choice;

	if ('Y' == std::toupper(choice))
	{
		set_bit(passwordSetFlags, static_cast<std::uint8_t>(PasswordRequirements::ALL_OPTIONS_SET));
		std::cout << "ALL_OPTIONS_SET flag is set\n";
	}
	else
	{

		std::cout << "Uppercase letter? (Y/N): ";
		std::cin >> choice;

		if ('Y' == std::toupper(choice))
		{
			set_bit(passwordSetFlags, static_cast<std::uint8_t>(PasswordRequirements::UPPERCASE_LETTERS));
		}

		std::cout << "Lowercase letter? (Y/N): ";
		std::cin >> choice;

		if ('Y' == std::toupper(choice))
		{
			set_bit(passwordSetFlags, static_cast<std::uint8_t>(PasswordRequirements::LOWERCASE_LETTERS));
		}

		std::cout << "Numbers? (Y/N): ";
		std::cin >> choice;

		if ('Y' == std::toupper(choice))
		{
			set_bit(passwordSetFlags, static_cast<std::uint8_t>(PasswordRequirements::NUMBERS));
		}

		std::cout << "Symbols? (Y/N): ";
		std::cin >> choice;

		if ('Y' == std::toupper(choice))
		{
			set_bit(passwordSetFlags, static_cast<std::uint8_t>(PasswordRequirements::SYMBOLS));
		}

		if (passwordSetFlags & static_cast<std::uint8_t>(PasswordRequirements::BIT0_ALWAYS_SET))
		{
			std::cout << "BIT0_ALWAYS_SET flag is set\n";
		}

		if (passwordSetFlags & static_cast<std::uint8_t>(PasswordRequirements::UPPERCASE_LETTERS))
		{
			std::cout << "UPPERCASE_LETTERS flag is set\n";
		}

		if (passwordSetFlags & static_cast<std::uint8_t>(PasswordRequirements::LOWERCASE_LETTERS))
		{
			std::cout << "LOWERCASE_LETTERS flag is set\n";
		}

		if (passwordSetFlags & static_cast<std::uint8_t>(PasswordRequirements::NUMBERS))
		{
			std::cout << "NUMBERS flag is set\n";
		}

		if (passwordSetFlags & static_cast<std::uint8_t>(PasswordRequirements::SYMBOLS))
		{
			std::cout << "SYMBOLS flag is set\n";
		}
	}
	std::cout << "Flags: " << std::bitset<5>(passwordSetFlags) << std::endl;

	/* Clear all the bits */
	clear_bit(passwordSetFlags, static_cast<std::uint8_t>(PasswordRequirements::ALL_OPTIONS_SET));

}

void set_bit(std::uint8_t& flag, std::uint8_t mask)
{
	flag |= mask;
}

void clear_bit(std::uint8_t& flag, std::uint8_t mask)
{
	flag &= ~mask;
}
#include <iostream>
#include <array>
#include <cstdint>
#include <bitset>

constexpr std::size_t SIZEOFARRAY{ 5 };
using dieArray = std::array<uint16_t, SIZEOFARRAY>;

uint16_t diffBetweenNum(uint16_t first, uint16_t second);
void set_bit(uint8_t&, uint8_t);

int main()
{
	dieArray die{ 1,2,2,3,4 };
	int smallStraightScore{ 0 };
	uint8_t flags{ 0x0 };
	int countDiffAreZeroes{ 0 };

	for (uint8_t i = 0; i < die.size() - 1; i++)
	{
		if (1 == diffBetweenNum(die[i], die[i + 1]))
		{
			set_bit(flags, (static_cast<uint8_t>(1 << i)));
		}
		else if (0 == diffBetweenNum(die[i], die[i + 1]))
		{
			++countDiffAreZeroes;
			if (4 == countDiffAreZeroes)
			{
				flags = 0xF; /* All the dies are the same so the points will be 30 per Yahtzee rules. */
			}
		}
	}

	std::cout << "Flags: " << std::bitset<4>(flags) << std::endl;
	/*
				 Bit
				3210
		0x7 = 0111b (Example: Dies 1,2,3,4,6)
		0xB = 1011b (Example: Dies 1,2,3,3,4) *See Note below.
		0xD = 1101b (Example: Dies 1,2,2,3,4) *See Note below.
		0xE = 1110b (Example: Dies 2,2,3,4,5)
		0xF = 1111b (Example: Dies 1,1,1,1,1)

		Note 1: For 0xB and 0xD, I need to put a counter of the diff that are zeroes
		to prevent a false set flag when there is none. There can not be more than 2 of
		the same number of the die. Example: (1,1,1,2,3) shall not count as a small straight
		because the numbers would be 1,2,3.
	*/
	if (flags == 0x7 || flags == 0xE || flags == 0xF ||
		(flags == 0xB && 1 == countDiffAreZeroes) || 
		(flags == 0xD && 1 == countDiffAreZeroes))
	{
		smallStraightScore = 30;
	}
	else
	{
		smallStraightScore = 0;
	}

	std::cout << "Small Straight Score: " << smallStraightScore << std::endl;
}

uint16_t diffBetweenNum(uint16_t first, uint16_t second)
{

	if (first < second)
	{
		return second - first;
	}
	else if (first > second)
	{
		return first - second;
	}

	return 0;
}

void set_bit(uint8_t& flag, uint8_t mask)
{
	flag |= mask;
}

void clear_bit(uint8_t& flag, uint8_t mask)
{
	flag &= ~mask;
}
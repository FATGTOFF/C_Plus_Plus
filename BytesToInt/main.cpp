/*
	Author: Carlos Vazquez
	Date: 18 Apr 21

	Purpose:
	This is a short program on hot to convert the
	hex bytes into the decimal value. I made it to
	work towards 64 bits just in case I would need
	it in the future. At first, I set all the bytes
	to 0 and then will ask the user how many bytes
	would be need it to determine the decimal value.
	To avoid having the user input all the bytes, the
	user just need to input it as big endian format.
	The unuesed bytes will be 0.
	
	For example, if I want to determine the decimal 
	value of only 2 bytes (i.e. 0A 7B), then I would 
	just ask the user to input byte 8 (7B) and 
	byte 7 (0A), then with the others bytes being 0, 
	I will print out 00 00 00 00 00 00 0A 7B and the
	decimal value of 2683.

	Sources: https://www.daniweb.com/programming/software-development/threads/422265/converting-4byte-hex-to-decimal
*/

#include <iostream>

using uint_64 = unsigned long long; //typedef unsigned long long uint_64
using uint_16 = unsigned short; // typedef unsigned short uint_16
using u_char = unsigned char; // typedef unsigned short u_char

void InputNumberOnly(uint_16&);

int main()
{
	const uint_16 MAXNUMBYTES = 8;
	uint_64 bytes[MAXNUMBYTES]{};
	uint_16 numOfBytesToInput{};
	uint_64 num = 0;

	std::cout << "Input Num of Bytes (0 to 8): ";
	InputNumberOnly(numOfBytesToInput);

	while (0 < numOfBytesToInput && numOfBytesToInput > 8)
	{
		std::cout << "Input Num of Bytes (0 to 8): ";
		InputNumberOnly(numOfBytesToInput);
	}

	std::cout << "Big Endian\n";
	// Just process the number of bytes the user requested. The rest of the bytes are 
	// defaulted to 0 so there is no point of retyping 0 for the unused bytes.
	for (uint_16 count = MAXNUMBYTES; count > (MAXNUMBYTES - numOfBytesToInput); count--)
	{
		std::cout << "Byte " << count << " : ";
		std::cin >> std::hex >> bytes[count - 1];
	}

	num = bytes[7];
	num |= bytes[6] << 8;
	num |= bytes[5] << 16;
	num |= bytes[4] << 24;
	num |= bytes[3] << 32;
	num |= bytes[2] << 40;
	num |= bytes[1] << 48;
	num |= bytes[0] << 56;

	for (uint_16 count = 0; count < MAXNUMBYTES; count++)
	{
		printf("%02X ", (unsigned)bytes[count]);
	}

	std::cout << std::dec << "\nDecimal Value: " << num << std::endl;

}

void InputNumberOnly(uint_16 &num)
{
	while ((std::cin >> num).fail() || std::cin.peek() != '\n')
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
		{
			continue;
		}
		std::cout << "Your choice is incorrect. Try again: ";
	}
}
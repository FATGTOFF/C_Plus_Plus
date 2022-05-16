/*
	This is a short program on how to convert
	the decimal into hex bytes. It helps me
	to determine the expected values when I 
	read the values from the microprocessor.
	More about the endianess after the code.

	Note: I tried to make it pure C++, but I
	will be honest. The printf makes it easier
	to print the values in hex format.
*/

#include <iostream>
#include <chrono>

using uint_64 = unsigned long long; //typedef unsigned long long uint_64
using u_char = unsigned char; // typedef unsigned short u_char

void InputNumberOnly(uint_64&);

struct bytes_s
{
	u_char byte_1;
	u_char byte_2;
	u_char byte_3;
	u_char byte_4;
	u_char byte_5;
	u_char byte_6;
	u_char byte_7;
	u_char byte_8;
};

int main()
{
	bytes_s bytes;

	/*Init the structure*/
	memset(&bytes, 0, sizeof(bytes));
	uint_64 num = 0;

	std::cout << "Num: ";
	//std::cin >> num;
	InputNumberOnly(num);
	auto startTime = std::chrono::high_resolution_clock::now();

	// Big Endian
	bytes.byte_1 = (num >> 56) & 0xFF;
	bytes.byte_2 = (num >> 48) & 0xFF;
	bytes.byte_3 = (num >> 40) & 0xFF;
	bytes.byte_4 = (num >> 32) & 0xFF;
	bytes.byte_5 = (num >> 24) & 0xFF;
	bytes.byte_6 = (num >> 16) & 0xFF;
	bytes.byte_7 = (num >> 8) & 0xFF;
	bytes.byte_8 = num & 0xFF;

	printf("Big Endian: %02X %02X %02X %02X %02X %02X %02X %02X\n",
		bytes.byte_1, bytes.byte_2, bytes.byte_3, bytes.byte_4,
		bytes.byte_5, bytes.byte_6, bytes.byte_7, bytes.byte_8);

	// Little Endian
	bytes.byte_8 = (num >> 56) & 0xFF;
	bytes.byte_7 = (num >> 48) & 0xFF;
	bytes.byte_6 = (num >> 40) & 0xFF;
	bytes.byte_5 = (num >> 32) & 0xFF;
	bytes.byte_4 = (num >> 24) & 0xFF;
	bytes.byte_3 = (num >> 16) & 0xFF;
	bytes.byte_2 = (num >> 8) & 0xFF;
	bytes.byte_1 = num & 0xFF;

	printf("Little Endian: %02X %02X %02X %02X %02X %02X %02X %02X\n",
		bytes.byte_1, bytes.byte_2, bytes.byte_3, bytes.byte_4,
		bytes.byte_5, bytes.byte_6, bytes.byte_7, bytes.byte_8);

	auto stopTime = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);
	std::cout << duration.count() << " microseconds" << std::endl;
}
void InputNumberOnly(uint_64& num)
{
	//std::cin >> num;
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
/*
Below is a quick note about the endianess...
Source: https://chortle.ccsu.edu/assemblytutorial/Chapter-15/ass15_3.html
I put the info below in case the website is moved in the future...

Big Endian and Little Endian

A load word or store word instruction uses only one memory address. 
The lowest address of the four bytes is used for the address of a 
block of four contiguous bytes.

How is a 32-bit pattern held in the four bytes of memory? 
There are 32 bits in the four bytes and 32 bits in the pattern, 
but a choice has to be made about which byte of memory gets what 
part of the pattern. 

There are two ways that computers commonly do this:
Big Endian Byte Order: The most significant byte (the "big end") 
of the data is placed at the byte with the lowest address. The rest 
of the data is placed in order in the next three bytes in memory.

Little Endian Byte Order: The least significant byte (the "little end") 
of the data is placed at the byte with the lowest address. The rest of 
the data is placed in order in the next three bytes in memory.

In these definitions, the data, a 32-bit pattern, is regarded as a 32-bit 
unsigned integer. The "most significant" byte is the one for the largest 
powers of two: 231, ..., 224. The "least significant" byte is the one for 
the smallest powers of two: 27, ..., 20.

For example, say that the 32-bit pattern 0x12345678 is stored at address 
0x00400000. The most significant byte is 0x12; the least significant is 0x78.

Within a byte the order of the bits is the same for all computers 
(no matter how the bytes themselves are arranged).
*/
#include <iostream>
#include <cstdint>
#include <bitset>

constexpr std::uint8_t mask0{ 1 << 0 }; // 0000 0001
constexpr std::uint8_t mask1{ 1 << 1 }; // 0000 0010
constexpr std::uint8_t mask2{ 1 << 2 }; // 0000 0100
constexpr std::uint8_t mask3{ 1 << 3 }; // 0000 1000
constexpr std::uint8_t mask4{ 1 << 4 }; // 0001 0000
constexpr std::uint8_t mask5{ 1 << 5 }; // 0010 0000
constexpr std::uint8_t mask6{ 1 << 6 }; // 0100 0000
constexpr std::uint8_t mask7{ 1 << 7 }; // 1000 0000

void set_bit(std::uint8_t &, std::uint8_t);
void clear_bit(std::uint8_t &, std::uint8_t);

int main()
{

	std::uint8_t flags = 0;

	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
	std::cout << "Flags: " << std::bitset<8>(flags) << std::endl;

	set_bit(flags, mask1); // turn on bit 1

	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
	std::cout << "Flags: " << std::bitset<8>(flags) << std::endl;

	clear_bit(flags, mask1); // turn off bit 1

	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
	std::cout << "Flags: " << std::bitset<8>(flags) << std::endl;

}

void set_bit(std::uint8_t &flag, std::uint8_t mask)
{
	flag |= mask;
}

void clear_bit(std::uint8_t &flag, std::uint8_t mask)
{
	flag &= ~mask;
}
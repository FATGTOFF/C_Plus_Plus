#include <iostream>

void hailstoneSequence(long long);

int main()
{
	long long n{};
	std::cout << "Starting Number: ";
	std::cin >> n;

	hailstoneSequence(n);
}

void hailstoneSequence(long long n)
{
	while (n != 1) // As long as the n value is not 1, keep looping. Stop when n is 1.
	{
		if (0 == n % 2)
		{
			n = n / 2;
		}
		else
		{
			n = (3 * n) + 1;
		}

		std::cout << n << std::endl;
	}
}

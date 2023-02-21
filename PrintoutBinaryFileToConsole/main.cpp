#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string gameSavedFileName = "gameSaved.dat";
	unsigned char bytes{};
	std::fstream savedFile(gameSavedFileName, std::ios::in | std::ios::binary);
	int count{ 0 };

	while (savedFile >> bytes)
	{
		++count;
		printf("%02X  ", bytes);
		if (0 == (count % 10))
		{
			std::cout << std::endl << std::endl;
		}
	}

	savedFile.close();
}
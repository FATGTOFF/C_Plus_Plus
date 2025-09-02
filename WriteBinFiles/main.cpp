#include <iostream>
#include <fstream>


int main()
{

	const char name[] = "This is a test";
	std::fstream binFile{};
	binFile.open("BinaryFile.bin", std::ios::out | std::ios::binary);
	binFile.write(reinterpret_cast<const char*>(&name), sizeof(name));

	binFile.close();

}

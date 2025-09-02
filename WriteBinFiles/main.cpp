#include <iostream>
#include <string>
#include <fstream>


int main()
{

	std::string name = "This is a test";
	std::fstream binFile{};
	binFile.open("BinaryFile.bin", std::ios::out | std::ios::binary);
	binFile.write(reinterpret_cast<const char*>(&name), sizeof(name));

	binFile.close();

}

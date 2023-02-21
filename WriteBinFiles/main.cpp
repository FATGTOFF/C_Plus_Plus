#include <iostream>
#include <fstream>


int main()
{

    const char* name = "This is a test";
    std::fstream scoreFile{};
    scoreFile.open("BinaryFile.bin", std::ios::out | std::ios::binary);
    scoreFile.write(reinterpret_cast<char*>(&name), sizeof(name));

    scoreFile.close();

}
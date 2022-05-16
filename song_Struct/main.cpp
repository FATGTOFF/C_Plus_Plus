#include <iostream>
#include <string>
#include <ios> // for streamsize
#include <limits> // for include numeric_limits.
#include <fstream>


struct Song
{
	std::string Title;
	std::string Artist;
	std::string Album;
	int Min;
	int Sec;
};

struct Test
{
	std::string Title1;
	std::string Artist1;
	std::string Album1;
	int Min1;
	int Sec1;
};



int main()

{
	const int totalOfElemFile = 4;
	Song song[totalOfElemFile];
	Test test[totalOfElemFile];

	std::cout << "Size of Test: " << sizeof(test) << std::endl;
	std::ifstream in;
	in.open("roster.txt");
	if (!in) return(1);

	for (int count = 0; count < totalOfElemFile; count++)
	{
		std::getline(in, song[count].Title, ';');
		std::getline(in, song[count].Artist, ';');
		std::getline(in, song[count].Album, ';');
		in >> song[count].Min;
		in.ignore(std::numeric_limits<std::streamsize>::max(), ';');
		in >> song[count].Sec;

	}

	for (int count = 0; count < totalOfElemFile; count++)
	{
		std::cout << song[count].Title << std::endl;
		std::cout << song[count].Artist << std::endl;
		std::cout << song[count].Album << std::endl;
		std::cout << song[count].Min << std::endl;
		std::cout << song[count].Sec << std::endl;
	}

	in.close();

	return 0;
}
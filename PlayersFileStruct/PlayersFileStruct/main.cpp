#include <iostream>
#include <string>
#include <fstream>
#include <limits> // For std::numeric_limits

struct playerData
{
	std::string pName;
	std::string tName;
	double points;
	double rebounds;
	double assists;
};

int countRecords(std::ifstream&, std::string, bool&);
bool readFile(std::ifstream&, playerData*, std::string, int);
void sort(playerData*, int);
void writeFile(std::ofstream&, playerData*, std::string, int);

int main()
{
	std::ifstream inFile;
	std::string inFileName{ "players.txt" };
	bool goodRead{};
	int size = countRecords(inFile, inFileName, goodRead);

	std::ofstream outFile;
	std::string outFileName{ "sortedPlayers.txt" };
	
	if (goodRead)
	{
		std::cout << "There are " << size << " records in " << inFileName << std::endl;

		playerData *pList = nullptr;
		pList = new playerData[size];

		if (readFile(inFile, pList, inFileName, size))
		{
			sort(pList, size);
			writeFile(outFile, pList, outFileName, size);
		}

		delete [] pList;
		pList = nullptr;

	}

	else
	{
		std::cout << "Please, verify the validation data on " << inFileName << std::endl;
	}

}

int countRecords(std::ifstream& inFile, std::string inFileName, bool &goodRead)
{
	inFile.open(inFileName);
	playerData temp;
	goodRead = true;
	int counter = 0;

	if (!inFile)
	{
		std::cout << "Error opening " << inFileName << std::endl;
		goodRead = false;
	}

	else
	{

		while (std::getline(inFile, temp.pName) && goodRead)
		{
			std::getline(inFile, temp.tName);

			inFile >> temp.points;
			if (inFile.fail())
			{
				inFile.clear();
				inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error reading points from "
					<< temp.pName << std::endl;
				goodRead = false;
			}

			inFile >> temp.rebounds;
			if (inFile.fail())
			{
				inFile.clear();
				inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error reading rebounds from "
					<< temp.pName << std::endl;
				goodRead = false;
			}

			inFile >> temp.assists;
			if (inFile.fail())
			{
				inFile.clear();
				inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error reading assists from "
					<< temp.pName << std::endl;
				goodRead = false;
			}

			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			counter++;
		}
		inFile.close();
	}

	return counter;
}

bool readFile(std::ifstream& inFile, playerData* pList, std::string inFileName, int size)
{
	inFile.open(inFileName);
	bool goodRead{true};

	if (!inFile)
	{
		std::cout << "Error opening " << inFileName << std::endl;
		goodRead = false;
	}

	else
	{
		std::cout << "File " << inFileName << " open.\n";

		for (int count = 0; count < size && goodRead; count++)
		{
			std::getline(inFile, pList[count].pName);
			std::getline(inFile, pList[count].tName);
			inFile >> pList[count].points;
			inFile >> pList[count].rebounds;
			inFile >> pList[count].assists;

			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		inFile.close();
		std::cout << "File " << inFileName << " closed.\n";
	}

	return goodRead;
}

void sort(playerData *pList, int size)
{
	bool swap{};
	playerData temp;

	std::cout << "Sorting the records by players name...\n";

	do
	{
		swap = false;

		for (int count = 0; count < (size - 1); count++)
		{
			// Sorted by alphabetical name.
			// Then move the rest of the players
			// information with the sorted data.
			if (pList[count].pName > pList[count + 1].pName)
			{
				temp.pName = pList[count].pName;
				pList[count].pName = pList[count + 1].pName;
				pList[count + 1].pName = temp.pName;

				temp.tName = pList[count].tName;
				pList[count].tName = pList[count + 1].tName;
				pList[count + 1].tName = temp.tName;

				temp.points = pList[count].points;
				pList[count].points = pList[count + 1].points;
				pList[count + 1].points = temp.points;

				temp.rebounds = pList[count].rebounds;
				pList[count].rebounds = pList[count + 1].rebounds;
				pList[count + 1].rebounds = temp.rebounds;

				temp.assists = pList[count].assists;
				pList[count].assists = pList[count + 1].assists;
				pList[count + 1].assists = temp.assists;

				swap = true;
			}
		}

	} while (swap);

	std::cout << "Sorting completed.\n";

}

void writeFile(std::ofstream& outFile, playerData* pList, std::string outFileName, int size)
{
	outFile.open(outFileName);
	std::cout << "File " << outFileName << " open.\n";

	for (int count = 0; count < size; count++)
	{
		outFile << pList[count].pName << '\n'
			<< pList[count].tName << '\n'
			<< pList[count].points << '\n'
			<< pList[count].rebounds << '\n'
			<< pList[count].assists << '\n';
	}

	outFile.close();
	std::cout << "File " << outFileName << " closed.\n";
}
/*
	From this point below is the draft that I used to 
	work on the program, which I may use later for reference.
*/
//if (inFile.fail())
//{
//	inFile.clear();
//	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	std::cout << "Error reading points from "
//		<< pList[count].pName << std::endl;
//	goodRead = false;
//}

//if (inFile.fail())
//{
//	inFile.clear();
//	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	std::cout << "Error reading rebounds from "
//		<< pList[count].pName << std::endl;
//	goodRead = false;
//}

//if (inFile.fail())
//{
//	inFile.clear();
//	inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	std::cout << "Error reading assists from "
//		<< pList[count].pName << std::endl;
//	goodRead = false;
//}

//#include <iostream>
//#include <string>
//#include <fstream>
//#include <limits> // For std::numeric_limits
//
//struct playerData
//{
//	std::string pName;
//	std::string tName;
//	double points;
//	double rebounds;
//	double assists;
//};
//
//void readFile(std::ifstream&, playerData*, std::string, int);
//int countLines(std::ifstream&, std::string);
//void sort(playerData*, int);
//void writeFile(std::ofstream&, playerData*, std::string, int);
//
//int main()
//{
//	std::ifstream inFile;
//	std::string inFileName{"players.txt"};
//	int size = 2/*countLines(inFile, inFileName)*/; // count the number of records in the file.
//
//	std::ofstream outFile;
//	std::string outFileName{"sortedPlayers.txt"};
//
//	// Dynamically allocate memory based on the number
//	// of records in the file.
//	playerData *pList = nullptr;
//	pList = new playerData [size];
//
//	readFile(inFile, pList, inFileName, size);
//	sort(pList, size);
//	writeFile(outFile, pList, outFileName, size);
//
//	delete [] pList;
//	pList = nullptr;
//}
//
//void readFile(std::ifstream& inFile, playerData* pList, std::string inFileName, int size)
//{
//	inFile.open(inFileName);
//
//	if (!inFile)
//	{
//		std::cerr << "Error opening " << inFileName << std::endl;
//		return;
//	}
//	else
//	{
//		std::cout << "File " << inFileName << " open.\n";
//
//		for (int count = 0; count < size; count++)
//		{
//			std::getline(inFile, pList[count].pName/*, '\t'*/); //The file is delimited as a tab; hence, the '\t'
//			std::getline(inFile, pList[count].tName/*, '\t'*/);
//			inFile >> pList[count].points;
//			inFile >> pList[count].rebounds;
//			inFile >> pList[count].assists;
//
//			inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		}
//		inFile.close();
//		std::cout << "File " << inFileName << " closed.\n";
//	}
//}
//
//int countLines(std::ifstream& inFile, std::string inFileName)
//{
//	int counter{0};
//	std::string line{};
//
//	inFile.open(inFileName);
//
//	if (!inFile)
//	{
//		std::cerr << "Error opening " << inFileName << std::endl;
//		return 0;
//	}
//
//	else
//	{ 
//		
//		std::cout << "Counting number of records in " << inFileName << std::endl;
//		while (std::getline(inFile, line))
//		{
//			counter++;
//		}
//
//		inFile.close();
//		std::cout << "Found " << counter << " records in " << inFileName << std::endl;
//	}
//
//	return counter;
//}
//
//void sort(playerData *pList, int size)
//{
//	bool swap{};
//	playerData temp;
//
//	std::cout << "Sorting the records by players name...\n";
//
//	do
//	{
//		swap = false;
//
//		for (int count = 0; count < (size - 1); count++)
//		{
//			// Sorted by alphabetical name.
//			// Then move the rest of the players
//			// information with the sorted data.
//			if (pList[count].pName > pList[count + 1].pName)
//			{
//				temp.pName = pList[count].pName;
//				pList[count].pName = pList[count + 1].pName;
//				pList[count + 1].pName = temp.pName;
//
//				temp.tName = pList[count].tName;
//				pList[count].tName = pList[count + 1].tName;
//				pList[count + 1].tName = temp.tName;
//
//				temp.points = pList[count].points;
//				pList[count].points = pList[count + 1].points;
//				pList[count + 1].points = temp.points;
//
//				temp.rebounds = pList[count].rebounds;
//				pList[count].rebounds = pList[count + 1].rebounds;
//				pList[count + 1].rebounds = temp.rebounds;
//
//				temp.assists = pList[count].assists;
//				pList[count].assists = pList[count + 1].assists;
//				pList[count + 1].assists = temp.assists;
//
//				swap = true;
//			}
//		}
//
//	} while (swap);
//
//	std::cout << "Sorting completed.\n";
//
//}
//
//void writeFile(std::ofstream& outFile, playerData* pList, std::string outFileName, int size)
//{
//	outFile.open(outFileName);
//	std::cout << "File " << outFileName << " open.\n";
//
//	//outFile << "Players Name\tTeam\tPts\tReb\tAst\n";
//
//	for (int count = 0; count < size; count++)
//	{
//		outFile << pList[count].pName << '\n'
//			<< pList[count].tName << '\n'
//			<< pList[count].points << '\n'
//			<< pList[count].rebounds << '\n'
//			<< pList[count].assists << '\n';
//	}
//
//	outFile.close();
//	std::cout << "File " << outFileName << " closed.\n";
//}

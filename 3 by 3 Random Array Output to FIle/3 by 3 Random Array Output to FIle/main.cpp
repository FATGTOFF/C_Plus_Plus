#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>


const int MAXROWS{ 500 };
const int MAXCOLS{ 500 };

void InitializeArrayRandomly(int num[][MAXCOLS], std::ostream&);
void DisplayArrayRandomly(int num[][MAXCOLS], std::ostream&);
void modify(int num[][MAXCOLS], std::ostream&);
int randomChoice(int min, int max);
void row_sum(const int num[][MAXCOLS], int sum[], std::ostream&);

int main()
{
    int numbers[MAXROWS][MAXCOLS] = { 0, 0 };
    int sum[MAXROWS] = { 0 };
    int arrayElement{ 0 };

    std::ofstream outPutFile;
    outPutFile.open("outFile.csv", std::ios::out);

    InitializeArrayRandomly(numbers, outPutFile);
    DisplayArrayRandomly(numbers, outPutFile);
    modify(numbers, outPutFile);
    row_sum(numbers, sum, outPutFile);

    outPutFile.close();

    return 0;
}

void InitializeArrayRandomly(int num[][MAXCOLS], std::ostream& outFile)
{
    outFile << "Entering the following integer numbers(randomly)...\n";
    for (int rows = 0; rows < MAXROWS; rows++)
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  outFile << "Row # " << rows + 1 << "," << "Col #" <<
			 cols + 1  << " : " << ",";
		  num[rows][cols] = randomChoice(0, 9);
		  outFile << num[rows][cols] << std::endl;
	   }
}

void DisplayArrayRandomly(int num[][MAXCOLS], std::ostream& outFile)
{
    outFile << "Displaying the numbers:\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  outFile << std::right << std::setw(5) <<
			 num[rows][cols] << ",";
	   }

	   outFile  << std::endl;
    }
}
void modify(int num[][MAXCOLS], std::ostream& outFile)
{
    outFile << "Displaying the numbers after multiplying\n";
    outFile  << "each value that is odd by -1 and each value\n";
    outFile << "that is even by 2...\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  if (num[rows][cols] % 2 != 0)
			 num[rows][cols] *= -1;

		  else if (num[rows][cols] % 2 == 0)
			 num[rows][cols] *= 2;

		  outFile << std::right << std::setw(5) << num[rows][cols] << ",";
	   }

	   outFile << std::endl;
    }
}

void row_sum(const int num[][MAXCOLS], int sum[], std::ostream& outFile)
{
    outFile << "Displaying the totals in each Row...\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   int rowTotal{ 0 };
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  rowTotal += num[rows][cols];
		  sum[rows] = rowTotal;
	   }

    }
    for (int count = 0; count < MAXROWS; count++)
	   outFile << "Row #" << count + 1 <<  std::right << std::setw(2) << ":" <<
	   "," <<std::setw(3) << sum[count] << "\n";
}


int randomChoice(int min, int max)
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.
    const int randNumber = distributionToss(generator);

    return randNumber;

}


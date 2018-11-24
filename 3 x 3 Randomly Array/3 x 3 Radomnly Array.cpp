#include <iostream>
#include <random>
#include <iomanip>



const int MAXROWS{ 3 };
const int MAXCOLS{ 3 };

void InitializeArrayRandomly(int num[][MAXCOLS]);
void DisplayArrayRandomly(int num[][MAXCOLS]);
void modify(int num[][MAXCOLS]);
int randomChoice(int min, int max);
void row_sum(int num[][MAXCOLS], int sum[]);

int main()
{
    int numbers[MAXROWS][MAXCOLS] = { 0, 0 };
    int sum[MAXROWS] = { 0 };
    int arrayElement{ 0 };

    InitializeArrayRandomly(numbers);
    DisplayArrayRandomly(numbers);
    modify(numbers);
    row_sum(numbers, sum);

    return 0;
}

void InitializeArrayRandomly(int num[][MAXCOLS])
{
    std::cout << "Entering the following integer numbers(randomly):\n";
    for (int rows = 0; rows < MAXROWS; rows++)
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  std::cout << "Row # " << rows + 1 << " Col #" << 
			 cols + 1 << " :";
		  num[rows][cols] = randomChoice(0, 9);
		  std::cout << num[rows][cols] << std::endl;
	   }
}

void DisplayArrayRandomly(int num[][MAXCOLS])
{
    std::cout << "Displaying the numbers:\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  std::cout << std::right << std::setw(5) << 
			 num[rows][cols] << "\t";
	   }

	   std::cout << std::endl;
    }
}
void modify(int num[][MAXCOLS])
{
    std::cout << "Displaying the numbers after multiplying\n";
    std::cout << "each value that is odd by -1 and each value\n";
    std::cout << "that is even by 2...\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  if (num[rows][cols] % 2 != 0)
			 num[rows][cols] *= -1;

		  else if (num[rows][cols] % 2 == 0)
			 num[rows][cols] *= 2;

		  std::cout <<std::right << std::setw(5) << num[rows][cols] << "\t";
	   }

	   std::cout << std::endl;
    }
}

void row_sum(int num[][MAXCOLS], int sum[])
{
    std::cout << "Displaying the totals in each Row...\n";
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
	   std::cout << "Row " << count + 1 << std::right <<
	   std::setw(5) << sum[count] << "\n";
}


int randomChoice(int min, int max)
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.
    const int randNumber = distributionToss(generator);

    return randNumber;

}


#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

const int MAXROWS{ 3 };
const int MAXCOLS{ 3 };

void InputValues(int num[][MAXCOLS]);
void DisplayValues(int num[][MAXCOLS]);
void FindNumbers(int num[][MAXCOLS], int element);
bool isPrime(int num);
void checkNumber(int num);
int randomChoice(int min, int max);
void displayPairs(int num);

int main()
{
    int numbers[MAXROWS][MAXCOLS] = { 0, 0 };
    int arrayElement{ 0 };

    InputValues(numbers);
    DisplayValues(numbers);
    arrayElement = numbers[randomChoice(0, 2)][randomChoice(0, 2)];
    std::cout << "The random number from the array element is: " << arrayElement << std::endl;
    FindNumbers(numbers, arrayElement);
    checkNumber(arrayElement);
    displayPairs(arrayElement);



    return 0;
}

void InputValues(int num[][MAXCOLS])
{
    std::cout << "Enter the following integer numbers:\n";
    for (int rows = 0; rows < MAXROWS; rows++)
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  std::cout << "Row # " << rows + 1 << " Col #" << cols + 1 << " :";
		  std::cin >> num[rows][cols];
	   }
}

void DisplayValues(int num[][MAXCOLS])
{
    std::cout << "Displaying the numbers:\n";
    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  std::cout << num[rows][cols] << "\t";
	   }

	   std::cout << std::endl;
    }
}

void FindNumbers(int num[][MAXCOLS], int findNum)
{
    bool found{ false };


    for (int rows = 0; rows < MAXROWS; rows++)
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  if (num[rows][cols] == findNum)
		  {
			 std::cout << "Found it on Row #" << rows + 1 << " and Col #" << cols + 1 << std::endl;
			 found = true;
		  }

	   }

    if (found == false)
	   std::cout << "The number " << findNum << " was not found.\n";

}

bool isPrime(int num)
{
    bool prime{ true };

    if (num < 2)
	   prime = false;

    else
    {
	   for (int count = 2; count <= std::sqrt(num); count++)
	   {
		  if (num % count == 0)
			 prime = false;
		  break;
	   }

    }

    return prime;
}

int randomChoice(int min, int max)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.

    return distributionToss(generator);

}

void displayPairs(int num)
{
    bool factor1{ true }, factor2{ true };

    for (int countA = 2, countB = num - 2; countA <= num / 2; countA++, countB--)
    {
	   factor1 = isPrime(countA);
	   if (factor1)
	   {
		  factor2 = isPrime(countB);

		  if (factor2)
			 std::cout << "Pair: " << countA << " + " << countB << std::endl;
	   }

    }
}

void checkNumber(int num)
{
    bool prime{ true };

    if (num < 2)
	   std::cout << "The number " << num << " is not a prime.\n";

    else
    {
	   for (int count = 2; count <= std::sqrt(num); count++)
	   {
		  if (num % count == 0)
			 prime = false;
		  break;
	   }

	   if (prime == true)
		  std::cout << "The number " << num << " is prime.\n";

	   else
		  std::cout << "The number " << num << " is not a prime.\n";

    }

}

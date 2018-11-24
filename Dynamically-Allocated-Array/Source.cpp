#include <iostream>
#include <iomanip>
#include <random>

//Function Prototype.
void initialArray(int num[], const int size);
void selectionSort(int num[], const int size);
void showArray(const int num[], const int size);
void findMinimum(const int num[], const int size);
void findMaximum(const int num[], const int size);
void findAverage(const int num[], const int size);
bool searchAgrade(const int num[], const int size);
void validateInput(int& userInput, int minSize);
int randomGenerator(int min, int max);


int main()
{

    int arrElements{ 0 };
    int *scores{ nullptr };

    std::cout << "How many scores? ";
    arrElements = randomGenerator(-25, 25);
    std::cout << arrElements << '\n';
    //std::cin >> arrElements;

    validateInput(arrElements, 1);

    scores = new int[arrElements];

    initialArray(scores, arrElements);
    selectionSort(scores, arrElements);
    showArray(scores, arrElements);
    findMinimum(scores, arrElements);
    findMaximum(scores, arrElements);
    findAverage(scores, arrElements);

    if (searchAgrade(scores, arrElements))
	   std::cout << "At least one 'A' grade entered.\n";

    delete[] scores;
    scores = nullptr;

    return 0;
}

void initialArray(int num[], const int size)
{
    for (int count = 0; count < size; count++)
    {
	   std::cout << "Enter a number: ";
	  // std::cin >> num[count];
	   num[count] = randomGenerator(-1, 101);
	   std::cout << num[count] << '\n';
	   while (num[count] < 0 || num[count] > 100)
	   {
		  std::cout << "Your input " << num[count] << " is incorrect.\n";
		  std::cout << "It must be between 0 and 100.\n";
		  std::cout << "Enter a number: ";
		  //std::cin >> num[count];
		  num[count] = randomGenerator(-1, 101);
		  std::cout << num[count] << '\n';
	   }
    }
}

void selectionSort(int num[], const int size)
{
    int minIndex{ 0 };
    int minValue{ 0 };

    for (int startScan = 0; startScan < (size - 1); startScan++)
    {
	   minIndex = startScan;
	   minValue = num[startScan];

	   for (int count = startScan + 1; count < size; count++)
	   {
		  if (num[count] < minValue)
		  {
			 minValue = num[count];
			 minIndex = count;
		  }

	   }
	   num[minIndex] = num[startScan];
	   num[startScan] = minValue;

    }

}

void showArray(const int num[], const int size)
{
    std::cout << "Sorted: ";
    for (int count = 0; count < size; count++)
	   std::cout << num[count] << " ";

    std::cout << "\n";
}

void findMinimum(const int num[], const int size)
{
    int minNum{ num[0] };
    for (int count = 0; count < size; count++)
    {
	   if (minNum > num[count])
		  minNum = num[count];
     }

    std::cout << "Minimum: " << minNum << "\n";
}

void findMaximum(const int num[], const int size)
{
    int maxNum{ num[0] };
    for (int count = 0; count < size; count++)
    {
	   if (maxNum < num[count])
		  maxNum = num[count];
    }

    std::cout << "Maximum: " << maxNum << "\n";
}

void findAverage(const int num[], const int size)
{
    double sum{ 0.0 };
    double avg{ 0.0 };
    for (int count = 0; count < size; count++)
	   sum += num[count];

    avg = sum / size;
    std::cout << "Average: " << std::fixed << std::setprecision(1) << avg << '\n';
}

bool searchAgrade(const int num[], const int size)
{
    bool A_Grade{ false };
    for (int count = 0; count < size; count++)
    {
	   if (num[count] > 89)
		  A_Grade = true;

	   else
		  A_Grade = false;
    }

    return A_Grade;
}

void validateInput(int& userInput, int minSize)
{
    while (userInput < minSize)
    {
	   std::cout << "Your input " << userInput << " is incorrect.\n";
	   std::cout << "It must be a positive integer number.\n";
	   std::cout << "How many scores? ";
	   userInput = randomGenerator(-25, 25);
	   std::cout << userInput << "\n\n";
	   //std::cin >> userInput;
    }
}

int randomGenerator(int min, int max)
{
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> distributionToss(min, max); // Set the numbers for int.
    const int randNumber = distributionToss(generator);

    return randNumber;

}
#include <iostream>
#include <random>
#include <fstream>
#include <limits>


int randomNumber(int, int);

int main()
{
    std::ofstream printOut;
    printOut.open("printOut.txt",  std::ios::out);

    for (int i = 0; i < 1000/*std::numeric_limits<int>::max()*/; ++i)
    {
	   const int rand = randomNumber(0, 1000);
	   printOut << i + 1 << '\t';
	   printOut << rand << "\t";

	   for (int count = 0; count < rand; count++)
		  printOut << "*";
	   printOut << std::endl;
    }

    std::cout << "COMPLETE.\n";

    printOut.close();


    std::ifstream inputFile;
    int number{ 0 };
    int sum{ 0 };
    int count{ 0 };
    double avg{ 0.0 };
    int lowest{ std::numeric_limits<int>::max() };
    int highest{ std::numeric_limits<int>::min() };
    int a{ 0 };

    //Open the file.
    inputFile.open("printOut.txt");
    if (inputFile.fail())
    {
	   std::cout << "Error opening the file.\n";
    }

    else
    {
	   while (inputFile >> number)
	   {
		  sum += number;
		  count++;

		  if (number > highest)
			 highest = number;

		  if (number < lowest)
			 lowest = number;
	   }
    }
    
    avg = sum / count;
    std::cout << "There are " << count << " numbers in the file.\n";
    std::cout << "The sum of all the numbers in the file is: " << sum << std::endl;
    std::cout << "The average of all the numbers in the file is: " << avg << std::endl;
    std::cout << "The lowest value in the file is: " << lowest << std::endl;
    std::cout << "The highest value in the file is: " << highest << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;

    inputFile.close();


    return 0;
}

int randomNumber(int min, int max)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distrib(min, max);

    const int random = distrib(rng);

    return random;

}
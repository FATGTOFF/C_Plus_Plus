#include <iostream>
#include <iomanip> 
#include <fstream>
#include <chrono>
#include <cctype> // For toupper function.

void setMultiplicationTable(int[][501]);
void findProduct(int&, int&);
void validateArrayBounds(int&);

int main()
{
    int table[501][501];
    int firstNum{ 0 }, secondNum{ 0 };
    char tryAgain{ ' ' };

    setMultiplicationTable(table);

    do
    {

	   findProduct(firstNum, secondNum);

	   std::cout << "The product is: " << table[firstNum][secondNum] << std::endl;

	   std::cout << "Would you like to try again?(Y/N)?";
	   std::cin >> tryAgain;

    } while (toupper(tryAgain) == 'Y');

    return 0;
}

void setMultiplicationTable(int multTbl[][501])
{
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now(); // Start the timer

    std::fstream outPutFile;
    outPutFile.open("Multiplication Table.csv", std::ios::out);

    for (int countRows = 0; countRows < 501; countRows++)
    {
	   for (int countCols = 0; countCols < 501; countCols++)
	   {
		  multTbl[countRows][countCols] = countRows * countCols;
		  outPutFile << std::setw(6) << multTbl[countRows][countCols] << ",";
	   }

	   outPutFile << std::endl;
    }

    outPutFile.close();

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now(); // Determine the timer after execution.

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1); // Substract the timer after execution - timer started.

    std::cout << "Completed Multiplication Table in " << time_span.count() << " seconds." << std::endl; // Notify the user.
}

void findProduct(int& num1, int& num2)
{
    std::cout << "Enter the first Number: ";
    validateArrayBounds(num1);

    std::cout << "Enter the second Number: ";
    validateArrayBounds(num2);
}

void validateArrayBounds(int& input)
{
    std::cin >> input;
    while (input < 0 || input > 500)
    {
	   std::cout << "The min/max input for the "
		  << "multiplication table is 0 - 500\n";
	   std::cout << "Please, try again.\n";
	   std::cout << ">>>";
	   std::cin >> input;
    }
}

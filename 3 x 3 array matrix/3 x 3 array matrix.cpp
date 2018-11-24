#include <iostream>

const int MAXROWS{ 3 };
const int MAXCOLS{ 3 };

void InputValues(int num[][MAXCOLS]);
void DisplayValues(int num[][MAXCOLS]);
void FindNumbers(int num[][MAXCOLS]);

int main()
{
    int numbers[MAXROWS][MAXCOLS] = { 0, 0 };

    InputValues(numbers);
    DisplayValues(numbers);
    FindNumbers(numbers);


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

void FindNumbers(int num[][MAXCOLS])
{
    int findNum{ 0 };
    bool found{ false };

    std::cout << "Find a number in the " << MAXROWS << " x " << MAXCOLS << std::endl;
    std::cout << "Input an integer number: ";
    std::cin >> findNum;

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

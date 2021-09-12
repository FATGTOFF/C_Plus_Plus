#include <iostream>

// I am using only what I need
// from namespace std;
using std::cin;
using std::cout;
using std::endl;

// Size of the matrix at compile-time.
constexpr int ROWS = 4;
constexpr int COLS = 4;

// display the contents of the matrix.
void displayMatrixContents(int matrix[][COLS])
{
   cout << "Col\t1\t2\t3\t4\n";
   cout << "------------------------------------\n";
   for (int rows = 0; rows < ROWS; rows++)
   {
      cout << "Row: " << rows + 1;
      for (int cols = 0; cols < COLS; cols++)
      {
         cout << "\t" << matrix[rows][cols];
      }
      cout << endl;
   }
}

bool searchNumberInMatrix(int matrix[][COLS], int &row, int &col, int number)
{
   bool Found = false;

   for (int rows = 0; rows < ROWS && !Found; rows++)
   {
      for (int cols = 0; cols < COLS && !Found; cols++)
      {
         if (matrix[rows][cols] == number)
         {
            // Once it is found, set the flag to true
            // so the for loop will stop. No reason to
            // keep looping.
            Found = true;
            row = rows + 1;
            col = cols + 1;
         }
      }
   }

   return Found;
}

int main()
{
   static int matrix[ROWS][COLS] = { { 18, 39, 91, 91 },
                                     { 67,  3,  9,  95},
                                     { 69,  3, 68, 93},
                                     { 69, 21, 92, 92} };

   displayMatrixContents(matrix);

   cout << "\nEnter an integer: ";
   int number{};
   cin >> number;

   // Declare this 2 variables to be used if the number is found
   int row{};
   int col{};
   if (searchNumberInMatrix(matrix, row, col, number))
   {
      cout << "\nFound " << number << " at "
         << "Row # " << row << " Col # "
         << col << endl;
   }
   else
   {
      cout << "\nNumber " << number << " was not found" << endl;
   }

   return 0;
}
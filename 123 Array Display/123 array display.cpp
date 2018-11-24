/*
Declare a two-dimensional array of integers named 'a', 
with 3 rows and 5 columns. Set the first row to all 1s, 
set the second row to all 2s, and the third row to all 3s. 
Lastly, display the two-dimensional array (in typical 
matrix fashion, rows/columns).
*/

#include <iostream>


int main()
{
    int a[3][5] {{1, 1, 1, 1, 1}, { 2, 2, 2, 2, 2 }, 
    { 3, 3, 3, 3, 3 } };

    for (int cols = 0; cols < 5; cols++)
    {
	   for (int rows = 0; rows < 3; rows++)
	   {
		  std::cout << " " << a[rows][cols];
	   }

	   std::cout << std::endl;;
    }

    return 0;
}

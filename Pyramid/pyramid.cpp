//How to make this shape in c++ using for loop ?
//
//#####*#####
//####*#*####
//###*###*###
//##*#####*##
//#*#######*#
//*#########*

#include <iostream>

int main()
{
    const int MAXROWS{ 6 }, MAXCOLS{ 11 };
    char pyramid[MAXROWS][MAXCOLS];

    for (int rows = 0; rows < MAXROWS; rows++)
    {
	   for (int cols = 0; cols < MAXCOLS; cols++)
	   {
		  pyramid[rows][cols] = '#';

		  pyramid[0][5] = '*';
		  pyramid[1][4] = '*';
		  pyramid[1][6] = '*';
		  pyramid[2][3] = '*';
		  pyramid[2][7] = '*';
		  pyramid[3][2] = '*';
		  pyramid[3][8] = '*';
		  pyramid[4][1] = '*';
		  pyramid[4][9] = '*';
		  pyramid[5][0] = '*';
		  pyramid[5][10] = '*';


		  std::cout << pyramid[rows][cols];
	   }

	   std::cout << std::endl;
    }

    return 0;
}

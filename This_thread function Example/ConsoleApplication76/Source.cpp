#include<iostream>
#include<cmath>
#include<thread>
#include<chrono>

using namespace std;
int main()
{
    double C[3], er, Cold, i;
    double a[3][4] = { { 15, -3, -1, 3800 },
    { -3, 18, -6, 1200 },
    { -4, -3, 12, 2350 } };

    er = .1;
    C[0] = a[0][3] / a[0][0];
    C[1] = a[1][3] / a[1][1];
    C[2] = a[2][3] / a[2][2];
    Cold = 326.2458;
    i = 1;
    while (true)
    {
	   if (((Cold - C[0]) / Cold) >= er)
	   {
		  C[0] = ((a[0][3] - (C[1] * a[0][1] - C[2] * a[0][2])) / a[0][0]);
		  C[1] = ((a[1][3] - (C[0] * a[1][0] - C[2] * a[1][2])) / a[1][1]);
		  C[2] = ((a[2][3] - (C[0] * a[2][0] - C[1] * a[2][1])) / a[2][2]);
		  cout << i;
		  i = i + 1;
		  //this_thread::sleep_for(1s);
		  std::this_thread::sleep_for(std::chrono::seconds(1));
	   }
	   else {

		  cout << C[0];
		  break;

	   }
    }

}
// this_thread::sleep_for example
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>		 // std::chrono::seconds
#include <iomanip>
using namespace std;

int main()
{
    cout << left << setw(12) << "countdown:";
    for (int i = 10; i > 0; --i) 
    {
	   cout << "\b\b " << i;
	   this_thread::sleep_for(std::chrono::seconds(1));
    }
    cout << "\b";
    cout << "Lift off!\n";

    return 0;
}
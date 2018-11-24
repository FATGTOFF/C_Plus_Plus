#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

    //INPUT VARIABLES
    float budget = 0.0;
    float expenses = 0.0;
    float total = 0.0;
    float runningExpenses = 0.0; //Add a variable to maintain a running total


    //Input budget money
    cout << "Enter the amount of money you budgeted: " << endl;
    cin >> budget;

    //Input expenses
    for (int count = 1; count <= 6; count++)
    {
	   cout << "Enter all of your expenses for the month: " << endl;
	   cin >> expenses;
	   runningExpenses += expenses;
    }

    //Processing the total money after expenses
    total = budget - runningExpenses;

    //Output the total money after expenses
    cout << setprecision(2) << fixed;
    cout << "Your total budget after expenses: $" << total << endl;
    if (budget > runningExpenses)
	   cout << "Your expenses are under the budget!";
    else if (budget < runningExpenses)
	   cout << "Your expenses are over the budget!";
    else 
	   cout << "You're breaking even between your expenses and budget!\n";

    return 0;
}

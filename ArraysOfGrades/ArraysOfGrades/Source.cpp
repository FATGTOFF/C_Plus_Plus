/*Write a program that uses an array of string objects to 
hold the five student names, an array of five characters to 
hold the five students’ letter grades, and five arrays of 
four double s to hold each student’s set of test scores.
The program should allow the user to enter each student’s 
name and his or her four test scores.It should then calculate 
and display each student’s average test score and a letter 
grade based on the average.Input Validation : Do not accept 
test scores less than 0 or greater than 100.*/
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const int sizeOfArrayNames{ 5 };
    const int sizeOfArrayScores{ 4 };
    string name[sizeOfArrayNames]{" "};
    char letterGrades[sizeOfArrayNames]{'A', 'B', 'C', 'D', 'F'};
    double testScores[sizeOfArrayScores]{ 0.0 };
    double runningTotal[sizeOfArrayNames]{ 0.0 };
    double average[sizeOfArrayNames]{ 0.0 };

    cout << "Enter the name for the following students\n";
    for (int count = 0; count < sizeOfArrayNames; count++)
    {
	   cout << "Student # " << count + 1 << ": ";
	   cin >> name[count];
    }

    for (int countA = 0; countA < sizeOfArrayNames; countA++)
    {
	   cout << "Enter the test scores for " << name[countA] << endl;

	   for (int countB = 0; countB < sizeOfArrayScores; countB++)
	   {
		  cout << "Score Number " << countB + 1 << ": ";
		  cin >> testScores[countB];

		  while (testScores[countB] < 0 || testScores[countB] > 100)
		  {
			 cout << "The input " << testScores[countB] << " is incorrect\n";
			 cout << "Score Number " << countB + 1 << ": ";
			 cin >> testScores[countB];
		  }

		  runningTotal[countA] += testScores[countB];
	   }

	   average[countA] = runningTotal[countA] / sizeOfArrayScores;
    }

    for (int countA = 0; countA < sizeOfArrayNames; countA++)
    {
	   cout << "The average scores for " << name[countA] << " is ";
	   cout << average[countA] << endl;

	   if (average[countA] <= 100 && average[countA] >= 90)
		  cout << "The Grade for " << name[countA] << " is " << letterGrades[0] << endl;
	   else if (average[countA] <= 89 && average[countA] >= 80)
		  cout << "The Grade for " << name[countA] << " is " << letterGrades[1] << endl;
	   else if (average[countA] <= 79 && average[countA] >= 70)
		  cout << "The Grade for " << name[countA] << " is " << letterGrades[2] << endl;
	   else if (average[countA] <= 69 && average[countA] >= 60)
		  cout << "The Grade for " << name[countA] << " is " << letterGrades[3] << endl;
	   else
		  cout << "The Grade for " << name[countA] << " is " << letterGrades[4] << endl;
    }

    return 0;
	   
}
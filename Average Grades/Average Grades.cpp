//My assumption is you will write the student ID
//with their four grades to a file.Then, you will
//read the student ID and their four grades and 
//determine the average.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

void writeFile(std::ofstream&, std::string, double, double[]);
void readFile(std::ifstream&, std::string, double, double[]);


int main()
{
    
    std::ofstream outFile;
    std::string studentID{ " " };
    const int totalNumOfGrades{ 4 };
    double grades[totalNumOfGrades] {0.0};

    writeFile(outFile, studentID, totalNumOfGrades, grades);

    std::ifstream inFile;

    readFile(inFile, studentID, totalNumOfGrades, grades);


    return 0;
}

void writeFile(std::ofstream &outputFile, std::string stuIdentification, double sizeofGrades, double arrayGrades[])
{
    outputFile.open("grade.txt", std::ios::out);

    bool addRecord{ true };
    while (addRecord)
    {
	   std::cout << "Enter the Student ID: ";
	   std::getline(std::cin, stuIdentification);
	   while (stuIdentification.length() > 8)
	   {
		  std::cout << "Sorry, but the student ID cannot be more than 8 characters.\n";
		  std::cout << "Enter the Student ID: ";
		  std::getline(std::cin, stuIdentification);
	   }
	   for (unsigned int count = 0; count < stuIdentification.length(); count++)
	   {
		  if (stuIdentification[count] == ' ')
		  {
			 stuIdentification[count] = '_';
		  }
	   }
	   outputFile << stuIdentification << "\t\t";

	   std::cout << "Enter " << stuIdentification << "'s " << sizeofGrades << " grades\n";
	   for (int count = 0; count < sizeofGrades; count++)
	   {
		  std::cout << stuIdentification << "'s grade #" << count + 1 << " :";
		  std::cin >> arrayGrades[count];
		  outputFile << arrayGrades[count] << "\t";
	   }

	   outputFile << std::endl;

	   char addOneMore{ ' ' };
	   int countWrongInput{ 3 };
	   std::cout << "Would you like to add another student?: ";
	   std::cin >> addOneMore;
	   while (toupper(addOneMore) != 'Y' && (toupper(addOneMore) != 'N'))
	   {
		  std::cout << "Sorry, but your answer is not valid\n";
		  std::cout << "You have " << countWrongInput << " tries.\n";
		  std::cout << "Would you like to add another student?: ";
		  std::cin >> addOneMore;

		  countWrongInput--;
		  if (countWrongInput == 0)
			 addOneMore = 'N';
	   }

	   if (toupper(addOneMore) == 'Y')
	   {
		  addRecord = true;
		  std::cin.ignore();
	   }

	   else if (toupper(addOneMore) == 'N')
	   {
		  addRecord = false;
		  outputFile.close();
	   }

    }

}

void readFile(std::ifstream& inputFile, std::string stuIdentification, double sizeofGrades, double arrayGrades[])
{
    inputFile.open("grade.txt", std::ios::in);

    if (inputFile)
    {

	   while (inputFile >> stuIdentification >> arrayGrades[0] >> arrayGrades[1]
		  >> arrayGrades[2] >> arrayGrades[3])
	   {
		  double total = 0.0;
		  for (int count = 0; count < sizeofGrades; count++)
			 total += arrayGrades[count];

		  std::cout << "The average for " << stuIdentification << " is " <<
			 std::fixed << std::setprecision(2) << total / sizeofGrades << std::endl;
	   }

    }
    else
    {
	   std::cerr << "The file could not be open.\n";
	   std::cerr << "The program will close...\n";
    }


    inputFile.close();
}

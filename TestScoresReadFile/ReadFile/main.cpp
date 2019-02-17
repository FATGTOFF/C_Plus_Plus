#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Struct to hold the information of the student.
struct Student
{
	std::string name;
	std::string SSN;
	std::string address;
	std::string telephone;
	unsigned int age;
	unsigned int numOfYears;
};

// Struct to hold the grades of the student.
struct FinalGrades
{
	double percentage;
	char letterGrade;
};

void readFile(std::ifstream&, Student&, std::string, double[], FinalGrades&);
void determineGrade(FinalGrades&);
void writeFile(std::ofstream&, Student, std::string, double[], FinalGrades);

int main()
{
	Student student{};
	FinalGrades grades{};
	double testScores[5]{};

	std::string inFileName{ "project2_input.txt" };
	std::ifstream inFile;
	readFile(inFile, student, inFileName, testScores, grades);

	determineGrade(grades);

	std::string outFileName{ "project2_output.txt" };
	std::ofstream outFile;
	writeFile(outFile, student, outFileName, testScores, grades);

	return 0;

}
void readFile(std::ifstream& info, Student& student, std::string fileName, double testScores[], FinalGrades& grades)
{
	// An array to hold the weighted score, based on the type of exam.
	double weightedScore[]{ .10, .15, .15, .20, .40 };

	// A counter to be used to determine the weighted score
	// in the while loop.
	int countTestScores{ 0 };

	info.open(fileName);

	if (!info)
	{
		std::cout << "File [" << fileName << "] could not open.\n";
		return;
	}
	else
	{
		std::cout << "File [" << fileName << "] open.\n";
		std::getline(info, student.name);
		info >> student.age;
		info.ignore();
		std::getline(info, student.address);
		info >> student.numOfYears;
		info.ignore();
		std::getline(info, student.telephone);
		std::getline(info, student.SSN);

		// While is reading the scores, compute the percentage
		// by multiplying the test score by the proper weighted score.
		// Example: Score 98.5 * .10[aray index 0] = percentage.
		// Example: Score 87.5 * .15[array index 1] = percentage.
		// The percentage is to be used as a running total to
		// determine later the letter grade.
		while (info >> testScores[countTestScores])
		{
			grades.percentage += (testScores[countTestScores] * weightedScore[countTestScores]);
			countTestScores++;
		}
	}
	info.close();
	std::cout << "File [" << fileName << "] closed.\n";
}

// This function obtains the percentage
// obtain by reading the file to obtain
// the letter grade, which would be 
// returned as a character data type.

void determineGrade(FinalGrades& grades)
{
	if (grades.percentage >= 90)
		grades.letterGrade = 'A';

	else if (grades.percentage >= 80)
		grades.letterGrade = 'B';

	else if (grades.percentage >= 70)
		grades.letterGrade = 'C';

	else if (grades.percentage >= 65)
		grades.letterGrade = 'D';

	else
		grades.letterGrade = 'F';

}

// This function writes a file with the name of the student
// and the final grade, based on the test scores from the input file.
void writeFile(std::ofstream& outFile, Student student, std::string fileName, double testScores[], FinalGrades grades)
{
	const unsigned int numOfTestScores{5};

	outFile.open(fileName);
	std::cout << "File [" <<fileName << "] open.\n";

	outFile << "Name: " << student.name << std::endl;
	outFile << "Age: " << student.age << std::endl;
	outFile << "Address: " << student.address << std::endl;
	outFile << "Number of Years: " << student.numOfYears << std::endl;
	outFile << "Phone Number: " << student.telephone << std::endl;
	outFile << "SSN: " << student.SSN << std::endl;

	for (std::size_t countTestScores = 0; countTestScores < numOfTestScores; countTestScores++)
	{
		outFile << "Test Score # " << countTestScores + 1 << " : "
			<< testScores[countTestScores] << std::endl;
	}

	outFile << std::fixed << std::setprecision(2);
	outFile << "Percentage: " << grades.percentage << std::endl;
	outFile << "Final Grade: " << grades.letterGrade << std::endl;
	outFile << std::fixed << std::setprecision(0);

	outFile.close();
	std::cout << "File [" << fileName << "] closed.\n";
}
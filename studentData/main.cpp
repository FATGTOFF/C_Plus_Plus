#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/* struct that holds the student data
it has an overloaded output operator
to be used with the vector container.*/
struct Student
{
	int itemNum;
	std::string ID;
	std::string name;
	float grade;

	/* Default constructor with values to be put into the file just in case
	the file is not available. Basically, when the file gets created, it will
	put the dummy values. */
	Student() : itemNum(0), ID("00000000"), name("Student Name"), grade(1.1f) {};

	/* This overload is to print out in case the student ID is found in the vector of Student struct. */
	friend std::ostream& operator << (std::ostream& output, const Student& studentStruct)
	{
		output << "Item Number: " << studentStruct.itemNum << '\n'
			<< "Student ID: " << studentStruct.ID << '\n'
			<< "Student Name: " << studentStruct.name << '\n'
			<< "Final Grade: " << studentStruct.grade << '\n';

		return output;
	}
};

bool openFileIn(std::fstream&, std::string);
bool openFileOut(std::fstream&, std::string);
void inputDefaultValues(std::fstream&, const Student&);
void findStudentGrades(const std::vector<Student>, const std::string);

int main()
{
	/*Variables to hold the structures*/
	Student studentData_s;
	std::vector<Student> listOfStudents{};
	
	/*Variables to be used for file operations*/
	std::fstream studentFile{};
	std::string studentFileName{ "studentFileName.txt" };

	/*Variables to be used to grab the file data*/
	char comma{ ',' };
	std::string itemNum{};
	std::string ID{};
	std::string name{};
	std::string grade{};

	/* The data from the file will be read and put it in 
	the vector of Student struct. One way to do it is 
	to save each data as a string, then pass it to the 
	structure after making the necessary conversions. */
	if (openFileIn(studentFile, studentFileName))
	{
		while (std::getline(studentFile, itemNum, comma))
		{
			studentData_s.itemNum = std::stoi(itemNum); /* Convert the string to integer */
			std::getline(studentFile, ID, comma);
			studentData_s.ID = ID;
			std::getline(studentFile, name, comma);
			studentData_s.name = name;
			std::getline(studentFile, grade);
			studentData_s.grade = std::stof(grade); /* Convert the string to a float */

			/* Put the data into the vector */
			listOfStudents.push_back(studentData_s);
		}
		studentFile.close();
	}
	else
	{
		std::cerr << "File " << studentFileName << " does not exist...\n";
		std::cerr << "Creating " << studentFileName << " with defaulted values...\n";
		if (openFileOut(studentFile, studentFileName))
		{
			inputDefaultValues(studentFile, studentData_s);
			std::cout << "File " << studentFileName << " created.\n";
			studentFile.close();
		}
		else
		{
			std::cerr << "ERROR: File " << studentFileName << " could not be created...\n";
			std::cerr << "Closing the program...\n";
			return -1; /* Any non-zero value. */
		}
	}

	std::cout << "Type the Student ID number to find their grade information: ";
	std::string studentIDUserInput{};
	std::getline(std::cin, studentIDUserInput);

	findStudentGrades(listOfStudents, studentIDUserInput); 

}

bool openFileIn(std::fstream &studentFile, std::string studentFileName)
{
	studentFile.open(studentFileName, std::ios::in);
	if (!studentFile)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool openFileOut(std::fstream& studentFile, std::string studentFileName)
{
	studentFile.open(studentFileName, std::ios::out);
	if (!studentFile)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void inputDefaultValues(std::fstream& studentFile, const Student &studentData_s)
{
	char comma{ ',' };
	studentFile << studentData_s.itemNum << comma << studentData_s.ID
		<< comma << studentData_s.name << comma << studentData_s.grade << '\n';
}

void findStudentGrades(const std::vector<Student> listOfStudents, const std::string studentIDUserInput)
{
	for (unsigned int count = 0; count < listOfStudents.size(); count++)
	{
		if (listOfStudents[count].ID == studentIDUserInput)
		{
			std::cout << listOfStudents.at(count) << std::endl;
			count = listOfStudents.size();
		}
	}
}
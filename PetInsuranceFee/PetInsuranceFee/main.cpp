/*
Write a program that prints the insurance fee to pay for a pet according to the 
following rules: (Note: must use a switch statement to determine pet fee)
A dog that has been neutered costs $50.
A dog that has not been neutered costs $80.
A cat that has been neutered costs $40.
A cat that has not been neutered costs $60.
A bird or reptile costs nothing.
Any other animal generates an error message.

The program should prompt the user for the appropriate information: a 
character code for the pet type, and a yes/no response for the neutered status. 
Use a code letter to determine the kind of animal (i.e. D or d represents a dog, 
C or c represents a cat, B or b represents a bird, R or r represents a reptile, 
and anything else represents some other kind of animal). Use a code letter to 
determine the neutered status(i.e. Y or y represents yes, N or n represents no). 
The user should be allowed to enter the input in either upper or lower case.
It prints out the type of animal (full name of animal) and the insurance fee. Any 
error in input data should generate an error message “Invalid data – no fee calculated”

NOTE: You must use a switch statement to determine the pet fee.)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

int neuteredQuestion(char);

int main()
{
	std::string fullTypeAnimal{};
	char animal{};
	char neutered{};
	int fees{};

	std::cout << "Enter the appropiate information:\n"
		<< "D or d for dog\nC or c for cat\nB or b for bird\n"
		<< "R or r reptile\n>>>";
	std::cin >> animal;

	switch (std::toupper(animal))
	{
		case 'D':
			fullTypeAnimal = "Dog";
			fees = neuteredQuestion(animal);
			break;

		case 'C':
			fullTypeAnimal = "Cat";
			fees = neuteredQuestion(animal);
			break;

		case 'B':
			fullTypeAnimal = "Bird";
			fees = neuteredQuestion(animal);
			break;

		case 'R':
			fullTypeAnimal = "Reptile";
			fees = neuteredQuestion(animal);
			break;

		default:
			std::cout << "Invalid data - no fee calculated\n";
	}

	std::cout << "The fee for the " << fullTypeAnimal << " is $ "
		<< std::fixed << std::setprecision(2) << fees << std::endl;
}

int neuteredQuestion(char animal)
{
	const int dogNeuteredFee{ 50 };
	const int dogNotNeuteredFee{ 80 };
	const int catNeuteredFee{ 40 };
	const int catNotNeuteredFee{ 60 };
	int fees{};
	char neutered{};

	std::cout << "Is the animal neutered?>>> ";
	std::cin >> neutered;

	switch (std::toupper(neutered))
	{
		case 'Y':
		{
			switch (std::toupper(animal))
			{
				case 'D':
					fees = dogNeuteredFee;
					break;

				case 'C':
					fees = catNeuteredFee;
					break;
			}
		}
		break;

		case 'N':
		{
			switch (std::toupper(animal))
			{
				case 'D':
					fees = dogNotNeuteredFee;
					break;

				case 'C':
					fees = catNotNeuteredFee;
					break;
			}
		}
		break;

		default:
			std::cout << "You did not enter Y/y or N/n: ";
			std::cout << "Is the animal neutered?>>> ";
	}
	return fees;
}

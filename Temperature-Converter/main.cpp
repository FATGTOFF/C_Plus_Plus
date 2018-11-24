//write a program that creates and displays a table of temperature conversions.
//Get the starting temperature from the keyboard in degrees Celsius(do not allow 
//	input of a value below absolute zero).Also get an integer value to represent 
//	the number of degrees to increment for each of a 20 row table(do not allow 
//		the increment value to be less than one.The first column will be a row 
//		number starting with one, follow by the Celsius value and then the conversions 
//		into Fahrenheit, Kelvin, and Rankine.Be sure that all columns are neatly right 
//		aligned for a variety of inputs. Modularize the temperature conversion program 
//		in Lab 04. Use the breakdown of modules from item 4 (above)as the minimum level 
//		of modularity.Be sure that you comment each function correctly.

#include <iostream>
#include <iomanip>

//Function Prototypes.
double celcius_to_fahrenheit(double);
double celcius_to_kelvin(double);
double celcius_to_rankine(double);
void user_celcius(double &);
void user_increment(int&);
void displayTable(double, int);

int main()
{
	double celcius_value{};
	user_celcius(celcius_value);

	int increment_value{};
	user_increment(increment_value);

	displayTable(celcius_value, increment_value);

	return 0;
}

void user_celcius(double& celcius_value)
{
	std::cout << "What is temperature degree in Celcius: ";
	std::cin >> celcius_value;

	while (celcius_value < -273.15)
	{
		std::cout << "Your input " << celcius_value << " is incorrect.\n";
		std::cout << "Please, try again.\n";
		std::cout << "What is temperature degree in Celcius: ";
		std::cin >> celcius_value;
	}
}

void user_increment(int& increment_value)
{
	std::cout << "Input the number of degrees to increment up to 20 rows: ";
	std::cin >> increment_value;
	while (increment_value < 1)
	{
		std::cout << "Your input " << increment_value << " is incorrect.\n";
		std::cout << "Please, try again.\n";
		std::cout << "Input the number of degrees to increment up to 20 rows: ";
		std::cin >> increment_value;
	}
}

double celcius_to_fahrenheit(double C)
{
	return C * ( 9.0 / 5.0 ) + 32;
}

double celcius_to_kelvin(double C)
{
	return C + 273.15;
}

double celcius_to_rankine(double C)
{
	return (C + 273.15) * (9.0 / 5.0);
}

void displayTable(double celcius_value, int increment_value)
{
	std::cout << std::endl;
	std::cout << std::setw(2) << std::right << '#' << std::setw(13) << "Celcius" << std::setw(14)
		<< "Fahrenheit" << std::setw(11) << "Kelvin"
		<< std::setw(16) << "Rankine" << std::endl;
	std::cout << "----------------------------------------------------------------------------\n";
	for (int count = 0; count < 20; count++)
	{	
		std::cout << std::setw(2) << std::right << count + 1 << std::setw(10) << celcius_value << std::setw(13)
			<< celcius_to_fahrenheit(celcius_value) << std::setw(15) << celcius_to_kelvin(celcius_value)
			<< std::setw(15) << celcius_to_rankine(celcius_value) << std::endl;
		celcius_value += increment_value;
	}
}
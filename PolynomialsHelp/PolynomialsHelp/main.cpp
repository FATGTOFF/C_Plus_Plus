/*
	The program description is located under Resource Files folder
	on the Solution Explorer. The file name is Program Description.jpg
*/
#include <iostream>
#include <iomanip>
#include <cmath> // Needed for pow function.

/*
	Define a C structure that defines a polynomial
*/
struct Polynomial
{
	static const int Max_Elements{20};
	int polyOrder; // Integer that represents the polynomial order.
	double xValue; // Double that holds the x value.
	double coefficients[Max_Elements]; // Array of doubles that represents the polynomial coefficients.
};

//Function prototypes.
Polynomial readPoly();
double evalPoly(Polynomial);
void printPoly(Polynomial);

int main()
{
	Polynomial polyValues{readPoly()};
	printPoly(polyValues);

	return 0;
}

/*
	The readPoly function is to ask the user to input into the
	data members of the Polynomial data structure. This function
	creates a local variable of the structure data type to enable
	to obtain the data to return back to the calling function.
*/
Polynomial readPoly()
{
	Polynomial p; // Local variable of the structure data type.
	std::cout << "Enter polynomial order: ";
	std::cin >> p.polyOrder;
	while (p.polyOrder < 1 || p.polyOrder > p.Max_Elements)
	{
		std::cout << "Your input must be between 1 and " << p.Max_Elements << "\n";
		std::cout << "Enter polynomial order: ";
		std::cin >> p.polyOrder;
	}

	std::cout << "Enter the polynomial coefficients: ";
	for (int count = 0; count <= p.polyOrder; count++)
	{
		std::cin >> p.coefficients[count];
	}

	std::cout << "Enter the value of x: ";
	std::cin >> p.xValue;

	return p;
}

/*
	This evalPoly function takes the Polynomial data structure
	as a parameter to calculate the polynomial to enable to return
	the value as a double to the calling function. It initializes a
	for loop to iterate thru the coefficients based on the input of the 
	user of the number of coefficients the user wishes to input.
*/
double evalPoly(Polynomial p)
{
	double result{};
	int countExpOrder{p.polyOrder}; // This variable is to maintain the exponential count to decrement each coefficient. 
	for (int count = 0; count <= p.polyOrder; count++)
	{
		result += p.coefficients[count] * pow(p.xValue, countExpOrder);
		countExpOrder--; // Before it goes to the next iteration of coefficient, decrement the exponential count.
	}

	return result;
}

/*
	This printPoly function obtains the Polynomial structure as a parameter
	to enable to call the function evalPoly and used the values of the structure
	to print the values back to the console output. It uses if/else statements inside
	the for loop to discard any coefficients with the value 0.
*/
void printPoly(Polynomial p)
{
	//std::cout << std::noshowpos;
	double result{evalPoly(p)}; // Calls the function to obtain the final value of the polynomial calculation.
	int counterExpOrder{p.polyOrder}; // Initialize the highest exponent count to decrement as each coefficient iteration.

	std::cout << "f (x) = ";
	std::cout << *p.coefficients << " x^" << p.polyOrder; // Display the first coefficient prior to begin looping.
	counterExpOrder--;
	for (int count = 1; count <= p.polyOrder; count++)
	{
		//std::cout << std::noshowpos << " ";
		if (p.coefficients[count] /*>*/!= 0) // As long as the coefficient is higher than 0, continue to print to the output.
		{
			if (counterExpOrder > 1)
			{
				std::cout << "+ " << p.coefficients[count]; 
				std::cout << " x^" << counterExpOrder /*<<" + "*/; /*<<*//* std::setw(2) << std::showpos*/ /*<< " "std::showpos <<*/ /*" "*//*" + "*///;
				--counterExpOrder;
				//std::cout << std::noshowpoint;
			}

			else if (counterExpOrder == 1) // If the exponent is 1, then drop the ^ 1 due to is not required to display x ^ 1.
			{
				std::cout << "+ " << p.coefficients[count]; 
				std::cout << " x ";
				--counterExpOrder;
			}
			else if (counterExpOrder == 0) // If the exponent is 0, then drop the x since x ^ 0 = 1.
			{
				std::cout << "+ " /*<< std::showpos*/ << p.coefficients[count];
			}

		}
		//else if (p.coefficients[count] < 0)
		//{
		//	if (counterExpOrder > 1)
		//	{
		//		std::cout << " - " << p.coefficients[count];
		//		std::cout << " x^" << counterExpOrder /*<<*/ /*std::showpos <<*/ /*" "*//*" + "*/;
		//		--counterExpOrder;
		//	}

		//	else if (counterExpOrder == 1) // If the exponent is 1, then drop the ^ 1 due to is not required to display x ^ 1.
		//	{
		//		std::cout << " - " << p.coefficients[count];
		//		std::cout << " x ";
		//		--counterExpOrder;
		//	}
		//	else if (counterExpOrder == 0) // If the exponent is 0, then drop the x since x ^ 0 = 1.
		//	{
		//		std::cout << "- " /*<< std::showpos*/ << p.coefficients[count];
		//	}
		//}

		else // If the coefficient is 0, then decrement the exponent and iterate to the next coefficient.
		{
			--counterExpOrder;
			std::cout << " ";
			continue;
		}

	}

	std::cout << "\nf (x = " << p.xValue << ") = " << result;
}
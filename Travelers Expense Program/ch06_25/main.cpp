/*
Group Project
25. Travel Expenses
This program should be designed and written by a team of students. Here are some
suggestions:
    • One student should design function main , which will call the other functions in the program.
    The remainder of the functions will be designed by other members of the team.
    • The requirements of the program should be analyzed so each student is given about
    the same workload.
    • The parameters and return types of each function should be decided in advance.
    • Stubs and drivers should be used to test and debug the program.
    • The program can be implemented as a multifile program, or all the functions can be
    cut and pasted into the main file.
Here is the assignment: Write a program that calculates and displays the total travel
expenses of a businessperson on a trip. The program should have functions that ask
for and return the following:
    • The total number of days spent on the trip
    • The time of departure on the first day of the trip, and the time of arrival back home
    on the last day of the trip
    • The amount of any round-trip airfare
    • The amount of any car rentals
    • Miles driven, if a private vehicle was used. Calculate the vehicle expense as $0.27
    per mile driven
    • Parking fees (The company allows up to $6 per day. Anything in excess of this must
    be paid by the employee.)
    • Taxi fees, if a taxi was used anytime during the trip (The company allows up to $10
    per day, for each day a taxi was used. Anything in excess of this must be paid by the
    employee.)
    • Conference or seminar registration fees
    • Hotel expenses (The company allows up to $90 per night for lodging. Anything in
    excess of this must be paid by the employee.)
    • The amount of each meal eaten. On the first day of the trip, breakfast is allowed
    as an expense if the time of departure is before 7 a.m. Lunch is allowed if the time
    of departure is before 12 noon. Dinner is allowed on the first day if the time of
    departure is before 6 p.m. On the last day of the trip, breakfast is allowed if the
    time of arrival is after 8 a.m. Lunch is allowed if the time of arrival is after 1 p.m.
    Dinner is allowed on the last day if the time of arrival is after 7 p.m. The program
    should only ask for the amounts of allowable meals. (The company allows up to $9
    for breakfast, $12 for lunch, and $16 for dinner. Anything in excess of this must be
    paid by the employee.)
The program should calculate and display the total expenses incurred by the businessperson,
the total allowable expenses for the trip, the excess that must be reimbursed
by the businessperson, if any, and the amount saved by the businessperson if
the expenses were under the total allowed.
Input Validation: Do not accept negative numbers for any dollar amount or for miles
driven in a private vehicle. Do not accept numbers less than 1 for the number of days.
Only accept valid times for the time of departure and the time of arrival.
*/

#include <iostream>
#include <iomanip>

//Function Prototypes.
int totalNumDaysSpent();
double flightTimeDeparture();
double flightTimeArrival();
double roundTripAmount();
double carRentalsAmount();
double milesDriven(const double);
double parkingFees(const double, double& ,double&);
double taxiFees(const double, double&, double&);
double conferenceFees();
double hotelFees(const double, int, double&, double&);
void amountOfMeal(double,double, double&, double&, double&);
void displayCalculation(int, double, double, double, double);
void validateNonNegativeInput(double&);
void validateNumberOfDays(int&);
void validateChoiceAnswer(char&);
void displayTotalExpenses(double&, double, double, double, double, double, double, double, double);
void displayTotalAllowableExpense(double&, double, double, double, double, double, double, double, double);
void displayOutOfPocketExpenses(double&, double, double);
void displaySavingExpenses(double&, double, double);
void displayArrowInput();
void displayTitle();


int main()
{

    int numDays{ 0 };
    double timeDeparture{ 0.0 }, timeArrival{ 0.0 }, rentalAmount{ 0.0 }, tripAmount{ 0.0 }, mileageDriven{ 0.0 }, 
	   parkingAmount{ 0.0 }, totalParkingAmount{ 0.0 }, conferenceAmount{ 0.0 }, hotelAmount{ 0.0 }, mealAmount{ 0.0 }, 
	   taxiAmount{ 0.0 }, totalTaxiFees{ 0.0 }, totalHotelExpenses{ 0.0 }, totalMealAmount{ 0.0 }, totalExpenses{ 0.0 },
	   totalAllowableExpense{ 0.0 }, allowableParkingExpense{ 0.0 }, allowableTaxiExpense{ 0.0 }, allowableHotelExpense{ 0.0 },
	   allowableMealExpense{ 0.0 }, outOfPocketExpenses{ 0.0 };
    const double vehicleExpense{ 0.27 }, parkingExpense{ 6.00 }, taxiExpense{ 10 }, hotelExpenses{ 90 };
    char choice{ ' ' };

    displayTitle();
    numDays = totalNumDaysSpent();
    timeDeparture = flightTimeDeparture();
    timeArrival = flightTimeArrival();
    tripAmount = roundTripAmount();

    std::cout << "Did you rent any car?(Y/N)\n";
    validateChoiceAnswer(choice);
    if (choice == 'Y' || choice == 'y')
	   rentalAmount = carRentalsAmount();

    mileageDriven = milesDriven(vehicleExpense);

    std::cout << "Did you pay for parking tickets?(Y/N)\n";
    validateChoiceAnswer(choice);
    if (choice == 'Y' || choice == 'y')
	   parkingAmount = parkingFees(parkingExpense, allowableParkingExpense, totalParkingAmount); // Could be negative number.

    std::cout << "Did you use taxi?(Y/N)\n";
    validateChoiceAnswer(choice);
    if (choice == 'Y' || choice == 'y')
	   taxiAmount = taxiFees(taxiExpense, allowableTaxiExpense, totalTaxiFees); // Could be negative number.

    conferenceAmount = conferenceFees();
    hotelAmount = hotelFees(hotelExpenses, (numDays - 1), allowableHotelExpense, totalHotelExpenses); // Could be negative number.
    amountOfMeal(timeDeparture, timeArrival, allowableMealExpense, mealAmount, totalMealAmount); // Could be negative number.


    displayTotalExpenses(totalExpenses, tripAmount, rentalAmount, mileageDriven, totalParkingAmount,
	   totalTaxiFees, conferenceAmount, totalHotelExpenses, totalMealAmount);

    displayTotalAllowableExpense(totalAllowableExpense, tripAmount, rentalAmount, mileageDriven,
	   allowableParkingExpense, allowableTaxiExpense, conferenceAmount, allowableHotelExpense,
	   allowableMealExpense);

    outOfPocketExpenses = totalExpenses - totalAllowableExpense;

    if (outOfPocketExpenses >= 0)
	   displayOutOfPocketExpenses(outOfPocketExpenses, totalExpenses, totalAllowableExpense);

    else if (outOfPocketExpenses < 0)
	   displaySavingExpenses(outOfPocketExpenses, totalExpenses, totalAllowableExpense);

    return 0;
}

int totalNumDaysSpent()
{
    int numDays{ 0 };
    std::cout << "Input the total number of days spent on the trip\n";
    validateNumberOfDays(numDays);

    return numDays;
}

double flightTimeDeparture()
{
    double timeDeparture{ 0.0 };

    std::cout << "What was the time of departure on the first day of the trip\n";
    displayArrowInput();
    std::cin >> timeDeparture;
    while (timeDeparture < 0 || timeDeparture >= 24)
    {
	   std::cout << "Wrong input.\n";
	   std::cout << "What was the time (HH.MM) of departure on the first day of the trip\n";
	   displayArrowInput();
	   std::cin >> timeDeparture;
    }

    double minutes = (timeDeparture - static_cast<int>(timeDeparture)) * 100;
    while (minutes < 0 || minutes > 59)
    {
	   std::cout << "Wrong input.\n";
	   std::cout << "What was the time (HH.MM) of departure on the first day of the trip\n";
	   displayArrowInput();
	   std::cin >> timeDeparture;
	   
	   minutes = (timeDeparture - static_cast<int>(timeDeparture)) * 100;
    }

    return timeDeparture;

}

double flightTimeArrival()
{
    double timeArrival{ 0.0 };

    std::cout << "What was the time of arrival on the last day of the trip\n";
    displayArrowInput();
    std::cin >> timeArrival;
    while (timeArrival < 0 || timeArrival >= 24)
    {
	   std::cout << "Wrong input.\n";
	   std::cout << "What was the time of arrival on the last day of the trip\n";
	   displayArrowInput();
	   std::cin >> timeArrival;
    }

    double minutes = (timeArrival - static_cast<int>(timeArrival)) * 100;
    while (minutes < 0 || minutes > 59)
    {
	   std::cout << "Wrong input.\n";
	   std::cout << "What was the time of arrival on the last day of the trip\n";
	   displayArrowInput();
	   std::cin >> timeArrival;
	   minutes = (timeArrival - static_cast<int>(timeArrival)) * 100;
    }

    return timeArrival;

}

double roundTripAmount()
{
    double roundTripAmount{ 0.0 };
    std::cout << "Input the amount of the round-trip airfare\n";
    validateNonNegativeInput(roundTripAmount);

    return roundTripAmount;
}

double carRentalsAmount()
{
    double rentalAmount{ 0.0 };
    std::cout << "Input the amount of any car rentals\n";
    validateNonNegativeInput(rentalAmount);

    return rentalAmount;
}

double milesDriven(const double vehicleExpense)
{
    double mileageDriven{ 0.0 };
    double calculatedExpense{ 0.0 };

    std::cout << "How many miles did you drive in your private vehicle?\n";
    validateNonNegativeInput(mileageDriven);

    calculatedExpense = mileageDriven * vehicleExpense;

    return calculatedExpense;
}

double parkingFees(const double parkingExpense, double& allowableParkingExpense, double& totalParkingAmount)
{
    double reimbursementParking{ 0.0 };
    int numOfDays{ 0 };

    std::cout << "Input any parking fees during your trip\n";
    validateNonNegativeInput(totalParkingAmount);
   
    std::cout << "How many days did you use the parking?\n";
    validateNumberOfDays(numOfDays);

    allowableParkingExpense = parkingExpense * numOfDays;
    reimbursementParking = ((totalParkingAmount / numOfDays)  - parkingExpense) * numOfDays;

    if (reimbursementParking > 0)
    {
	   return reimbursementParking;
    }

    else if (reimbursementParking < 0)
    {
	   return reimbursementParking;
    }

    return reimbursementParking;
}

double taxiFees(const double taxiExpense, double& allowableTaxiExpense, double& totalTaxiFees)
{
    double reimbursementTaxi{ 0.0 };
    int numOfDays{ 0 };

    std::cout << "Input any taxi fees you incurred.\n";
    validateNonNegativeInput(totalTaxiFees);

    std::cout << "How many days did you use the taxi?\n";
    validateNumberOfDays(numOfDays);

    allowableTaxiExpense = taxiExpense * numOfDays;

    reimbursementTaxi = ((totalTaxiFees / numOfDays) - taxiExpense) * numOfDays;

    if (reimbursementTaxi > 0)
    {
	   return reimbursementTaxi;
    }

    else if (reimbursementTaxi < 0)
    {
	   return reimbursementTaxi;
    }

    return reimbursementTaxi;
}

double conferenceFees()
{
    double conferenceAmount{ 0.0 };
    std::cout << "Input any conference or seminar registration fees.\n";
    validateNonNegativeInput(conferenceAmount);

    return conferenceAmount;
}

double hotelFees(const double hotelExpenses, int numDays, double& allowableHotelExpense, double& totalHotelExpenses)
{
    double reimbursementHotel{ 0.0 };
    std::cout << "Input any hotel expenses.\n";
    validateNonNegativeInput(totalHotelExpenses);

    allowableHotelExpense = hotelExpenses * numDays;
    reimbursementHotel = ((totalHotelExpenses / numDays) - hotelExpenses) * numDays;

    if (reimbursementHotel > 0)
    {
	   return reimbursementHotel;
    }

    else if (reimbursementHotel < 0)
	   return reimbursementHotel;

    return reimbursementHotel;
}

void amountOfMeal(double timeDeparture, double timeArrival, double& allowableMealExpense, double& returnMealAmount, double& totalMealAmount)
{
    double mealAmount{ 0.0 }, breakfastAllowance{ 9.00 },
	   lunchAllowance{ 12.00 }, dinnerAllowance{ 16.00 },
	   amountSaved{ 0.0 };
    bool outOfPocketExpense{ true };

    std::cout << "Input the total amount of allowable meals.\n";
    std::cout << "The business person is allowed 1 meal for the\n";
    std::cout << "first day of the trip and one meal on the last\n";
    std::cout << "day of the trip\n";
    validateNonNegativeInput(mealAmount);

    totalMealAmount = mealAmount;

    if (timeDeparture > 00.00 && timeDeparture < 07.00)
    {
	   allowableMealExpense += breakfastAllowance;

	   if (breakfastAllowance < mealAmount)
	   {
		  mealAmount -= breakfastAllowance;
		  outOfPocketExpense = true;
	   }

	   else if (breakfastAllowance > mealAmount)
	   {
		  mealAmount -= breakfastAllowance;
		  amountSaved = -(mealAmount);
		  outOfPocketExpense = false;
	   }

	   else if (breakfastAllowance == mealAmount)
	   {
		  mealAmount -= breakfastAllowance;
		  outOfPocketExpense = false;
	   }

    }
    else if (timeDeparture > 06.59 && timeDeparture < 12.00)
    {
	   allowableMealExpense += lunchAllowance;

	   if (lunchAllowance < mealAmount)
	   {
		  mealAmount -= lunchAllowance;
		  outOfPocketExpense = true;
	   }

	   else if (lunchAllowance > mealAmount)
	   {
		  mealAmount -= lunchAllowance;
		  amountSaved = -(mealAmount);
		  outOfPocketExpense = false;
	   }

	   else if (lunchAllowance == mealAmount)
	   {
		  mealAmount -= lunchAllowance;
		  outOfPocketExpense = false;
	   }
    }
    else if (timeDeparture > 11.59 && timeDeparture < 18.00)
    {
	   allowableMealExpense += dinnerAllowance;

	   if (dinnerAllowance < mealAmount)
	   {
		  mealAmount -= dinnerAllowance;
		  outOfPocketExpense = true;
	   }

	   else if (dinnerAllowance > mealAmount)
	   {
		  mealAmount -= dinnerAllowance;
		  amountSaved = -(mealAmount);
		  outOfPocketExpense = false;
	   }

	   else if (dinnerAllowance == mealAmount)
	   {
		  mealAmount -= dinnerAllowance;
		  outOfPocketExpense = false;
	   }
    }

    if (timeArrival > 08.00 && timeArrival < 13.01)
    {
	   allowableMealExpense += breakfastAllowance;

	   if (breakfastAllowance < mealAmount)
	   {
		  mealAmount -= breakfastAllowance;
		  outOfPocketExpense = true;
	   }

	   else if (breakfastAllowance > mealAmount)
	   {
		  mealAmount -= breakfastAllowance;
		  amountSaved = -(mealAmount);
		  outOfPocketExpense = false;
	   }

	   else if (breakfastAllowance == mealAmount)
	   {
		  mealAmount -= breakfastAllowance;
		  outOfPocketExpense = false;
	   }
    }

    else if (timeArrival > 13.00 && timeArrival < 19.01)
    {
	   allowableMealExpense += lunchAllowance;

	   if (lunchAllowance < mealAmount)
	   {
		  mealAmount -= lunchAllowance;
		  outOfPocketExpense = true;
	   }

	   else if (lunchAllowance > mealAmount)
	   {
		  mealAmount -= lunchAllowance;
		  amountSaved = -(mealAmount);
		  outOfPocketExpense = false;
	   }

	   else if (lunchAllowance == mealAmount)
	   {
		  mealAmount -= lunchAllowance;
		  outOfPocketExpense = false;
	   }
    }
    else if (timeArrival > 19.00 && timeArrival < 23.59)
    {
	   allowableMealExpense += dinnerAllowance;

	   if (dinnerAllowance < mealAmount)
	   {
		  mealAmount -= dinnerAllowance;
		  outOfPocketExpense = true;
	   }

	   else if (dinnerAllowance > mealAmount)
	   {
		  mealAmount -= dinnerAllowance;
		  amountSaved = -(mealAmount);
		  outOfPocketExpense = false;
	   }

	   else if (dinnerAllowance == mealAmount)
	   {
		  mealAmount -= dinnerAllowance;
		  outOfPocketExpense = false;
	   }
    }

    if (mealAmount < 0)
	   returnMealAmount = mealAmount;

    else if (mealAmount > 0 && outOfPocketExpense == true)
	   returnMealAmount = mealAmount;


    else if (mealAmount == 0)
	   returnMealAmount = mealAmount;
}

void validateNonNegativeInput(double& number)
{
    displayArrowInput();
    std::cin >> number;
    while (number < 0)
    {
	   std::cout << "Your input " << number << " is incorrect.\n";
	   std::cout << "Ensure the number is positive value.\n";
	   std::cout << "Please try again.\n";
	   displayArrowInput();
	   std::cin >> number;
    }
}

void validateNumberOfDays(int& number)
{
    displayArrowInput();
    std::cin >> number;
    while (number < 1)
    {
	   std::cout << "Your input " << number << " is incorrect.\n";
	   std::cout << "Ensure the number is positive value\n"; 
	   std::cout << "Please try again.\n";
	   displayArrowInput();
	   std::cin >> number;
    }
}

void validateChoiceAnswer(char& choice)
{
    displayArrowInput();
    std::cin >> choice;
    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
	   std::cout << "Your input " << choice << " is incorrect.\n";
	   std::cout << "Ensure the choice is Y/y or N/n.\n";
	   std::cout << "Please try again.\n";
	   displayArrowInput();
	   std::cin >> choice;
    }

}

void displayTotalExpenses(double& totalExpenses, double tripAmount, double rentalAmount, double mileageDriven, 
    double totalParkingAmount, double totalTaxiFees, double conferenceAmount, double totalHotelExpenses, double totalMealAmount)
{

    totalExpenses = tripAmount + rentalAmount + mileageDriven + totalParkingAmount + totalTaxiFees + 
	   conferenceAmount + totalHotelExpenses + totalMealAmount;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "                          TOTAL EXPENSES BREAKDOWN                         \n";
    std::cout << "---------------------------------------------------------------------------\n";

    std::cout << "Trip:----------------------$" << tripAmount << std::endl;
    std::cout << "Rental:--------------------$" << rentalAmount << std::endl;
    std::cout << "Mileage:-------------------$" << mileageDriven << std::endl;
    std::cout << "Parking:-------------------$" << totalParkingAmount << std::endl;
    std::cout << "Taxi:----------------------$" << totalTaxiFees << std::endl;
    std::cout << "Conference:----------------$" << conferenceAmount << std::endl;
    std::cout << "Hotel:---------------------$" << totalHotelExpenses << std::endl;
    std::cout << "Meals:---------------------$" << totalMealAmount << std::endl;
    std::cout << "Total Expenses:------------$" << totalExpenses << std::endl;
    std::cout << "---------------------------------------------------------------------------\n";

}

void displayTotalAllowableExpense(double&totalAllowableExpense, double tripAmount, double rentalAmount, double mileageDriven, 
    double allowableParkingExpense, double allowableTaxiExpense, double conferenceAmount, double allowableHotelExpense,
    double allowableMealExpense)
{
    totalAllowableExpense = tripAmount + rentalAmount + mileageDriven + allowableParkingExpense + allowableTaxiExpense
	   + conferenceAmount + allowableHotelExpense + allowableMealExpense;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "                    TOTAL ALLOWABLE EXPENSES BREAKDOWN                     \n";
    std::cout << "---------------------------------------------------------------------------\n";
    std::cout << "Trip:----------------------$" << tripAmount << std::endl;
    std::cout << "Rental:--------------------$" << rentalAmount << std::endl;
    std::cout << "Mileage:-------------------$" << mileageDriven << std::endl;
    std::cout << "Parking:-------------------$" << allowableParkingExpense << std::endl;
    std::cout << "Taxi:----------------------$" << allowableTaxiExpense << std::endl;
    std::cout << "Conference:----------------$" << conferenceAmount << std::endl;
    std::cout << "Hotel:---------------------$" << allowableHotelExpense << std::endl;
    std::cout << "Meals:---------------------$" << allowableMealExpense << std::endl;
    std::cout << "Total Allowable Expenses:--$" << totalAllowableExpense << std::endl;
    std::cout << "---------------------------------------------------------------------------\n";

}

void displayOutOfPocketExpenses(double& outOfPocketExpenses, double totalExpenses, double totalAllowableExpense)
{
    std::cout << std::fixed << std::setprecision(2);
    outOfPocketExpenses = totalExpenses - totalAllowableExpense;
    std::cout << "                       TOTAL OUT OF POCKET EXPENSES                        \n";
    std::cout << "---------------------------------------------------------------------------\n";
    std::cout << "Out of Pocket Expenses:----$" << outOfPocketExpenses << std::endl;
    std::cout << "---------------------------------------------------------------------------\n";
}

void displaySavingExpenses(double& outOfPocketExpenses, double totalExpenses, double totalAllowableExpense)
{
    std::cout << std::fixed << std::setprecision(2);
    outOfPocketExpenses = totalExpenses - totalAllowableExpense;
    std::cout << "                          TOTAL SAVINGS EXPENSES                           \n";
    std::cout << "---------------------------------------------------------------------------\n";
    std::cout << "Savings:-------------------$" << -(outOfPocketExpenses) << std::endl;
    std::cout << "---------------------------------------------------------------------------\n";
}

void displayArrowInput()
{
    std::cout << ">>> ";
}

void displayTitle()
{
    std::cout << "                             TRAVEL EXPENSES                               \n";
}

#include <iostream>
#include <string>
#include <cctype> // For toupper function.
#include <ios> //used to get stream size
#include <limits> //used to get numeric limits

float wardedPatientCharge(const std::string, const int);
void typeOfDiscountToApply(unsigned char, float&);
void displayPatientDetails(const std::string, const int, const unsigned char, const int, const float);

int main()
{
	std::string patientName{};
	int ICNumber{};
	std::string wptc{}; // Warded Patient Type Code.
	unsigned char patientCategory{}; // 'C' for child or 'A' for adult.
	int numDaysWarded{};
	float amountPriorDiscount{};
	float amountAfterDiscount{};
	float percentDiscount{};
	unsigned char tryAgain{'Y'};

	while (std::toupper(tryAgain) != 'N')
	{
		std::cout << "Enter the patient's name: ";
		std::getline(std::cin, patientName);

		std::cout << "Enter the IC number for " << patientName << ": ";
		std::cin >> ICNumber;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new

		std::cout << "Enter the Warded Patient Code for " << patientName << ": ";
		std::getline(std::cin, wptc);
		while (wptc != "001" && wptc != "002" && wptc != "003")
		{
			std::cout << "Enter the Warded Patient Code for " << patientName << ": ";
			std::getline(std::cin, wptc);
		}

		std::cout << "Enter the Patient Category ([C]hild or [A]dult) for " << patientName << ": ";
		std::cin >> patientCategory;
		// Validate the input to ensure the options are A(a) or C(c).
		while(std::toupper(patientCategory) != 'A' && std::toupper(patientCategory) != 'C')
		{
			std::cout << "C or c for child - A or a for Adult\n";
			std::cout << "Enter the Patient Category (Child or Adult) for " << patientName << ": ";
			std::cin >> patientCategory;
		}

		std::cout << "Enter the number of days warded for " << patientName << ": ";
		std::cin >> numDaysWarded;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new line.

		amountPriorDiscount = wardedPatientCharge(wptc, numDaysWarded);

		typeOfDiscountToApply(patientCategory, percentDiscount);
		amountAfterDiscount = amountPriorDiscount * percentDiscount;

		displayPatientDetails(patientName, ICNumber, patientCategory, numDaysWarded, amountAfterDiscount);

		std::cout << "Input information of another patient?: ";
		std::cin >> tryAgain;
		while (std::toupper(tryAgain) != 'Y' && std::toupper(tryAgain) != 'N')
		{
			std::cout << "Input information of another patient?: ";
			std::cin >> tryAgain;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new line.
	}
}

float wardedPatientCharge(const std::string wptc, const int numDaysWarded)
{
	const float chargePerDaySurgery = 300.00f;
	const float chargePerDayOrthopedic = 250.00f;
	const float chargePerDayMedical = 200.00f;

	if ("001" == wptc)
	{
		return chargePerDaySurgery * numDaysWarded;
	}
	else if ("002" == wptc)
	{
		return chargePerDayOrthopedic * numDaysWarded;
	}
	else if ("003" == wptc)
	{
		return chargePerDayMedical * numDaysWarded;
	}
	else
	{
		return 0.0f;
	}
}

void typeOfDiscountToApply(unsigned char patientCategory, float& percentDiscount)
{
	if (std::toupper(patientCategory) == 'A')
	{
		percentDiscount = 0.95f;
	}
	else // If is a child.
	{
		percentDiscount = 0.80f;
	}
}

void displayPatientDetails(const std::string patientName, const int ICNumber, const unsigned char patientCategory, const int numDaysWarded, const float amountAfterDiscount)
{
	std::cout << "Patient Name: " << patientName << "\n";
	std::cout << "IC Number: " << ICNumber << "\n";
	std::cout << "Patient Category: " << patientName << "\n";
	std::cout << "Number of Days Warded: " << numDaysWarded << "\n";
	std::cout << "Total Charge After Discount: " << amountAfterDiscount << "\n";
}

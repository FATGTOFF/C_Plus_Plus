#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <iomanip>
#include <cstdlib>


constexpr bool DEBUG{ false };

enum class FilerStatus : unsigned int
{
   MARRIED_JOINT_SURVIVING_SPOUSE = 1,
   HEAD_OF_HOUSEHOLDS,
   UNMARRIED_INDIVIDUALS,
   MARRIED_SEPARATE,
   LAST_ENTRY
};

struct TaxRates_ST
{
   float taxRatePercentage;
   float minTaxIncome;
   float maxTaxIncome;
};

void readFile(std::vector<TaxRates_ST> &taxRates_st, const char* fileName);
void inputNumberOnly(unsigned int &num);
void displayMenu(unsigned int &choice);
float calculateTaxRate(const char* fileName);

int main()
{
   // This is a list of the files and should match with the enumerator FilerStatus.
   // The first element is None and should not change since the enumerators start at 1.
   std::vector<const char*> listOfFilesOfTaxRates
     {"None",
      "./Tax Rates/Married Joint Tax Rates.txt",
      "./Tax Rates/Head of Households Tax Rates.txt",
      "./Tax Rates/Unmarried Tax Rates.txt", "./Tax Rates/Married Separate Tax Rates.txt"};

   unsigned int choice{};
   float totalTax{};
   bool keepLooping{ true };

   while (keepLooping)
   {
      displayMenu(choice);
      switch (choice)
      {
         case static_cast<unsigned int>(FilerStatus::MARRIED_JOINT_SURVIVING_SPOUSE) :
            totalTax = calculateTaxRate(listOfFilesOfTaxRates.at(static_cast<unsigned int>(FilerStatus::MARRIED_JOINT_SURVIVING_SPOUSE)));
            break;

         case static_cast<unsigned int>(FilerStatus::HEAD_OF_HOUSEHOLDS) :
            totalTax = calculateTaxRate(listOfFilesOfTaxRates.at(static_cast<unsigned int>(FilerStatus::HEAD_OF_HOUSEHOLDS)));
            break;

         case static_cast<unsigned int>(FilerStatus::UNMARRIED_INDIVIDUALS) :
            totalTax = calculateTaxRate(listOfFilesOfTaxRates.at(static_cast<unsigned int>(FilerStatus::UNMARRIED_INDIVIDUALS)));
            break;

         case static_cast<unsigned int>(FilerStatus::MARRIED_SEPARATE) :
            totalTax = calculateTaxRate(listOfFilesOfTaxRates.at(static_cast<unsigned int>(FilerStatus::MARRIED_SEPARATE)));
            break;

         case static_cast<unsigned int>(FilerStatus::LAST_ENTRY) :
            std::cout << "\t\t\tClosing the program...\r\n";
            keepLooping = false;
            break;

         default:
            std::cout << "\t\t\tAn invalid choice was entered\r\n";

      }

      if (keepLooping)
      {
         std::cout << "\t\t\tTotal Tax: $" << std::fixed << std::setprecision(2) << static_cast<int>(totalTax) << std::endl << std::endl;
      }

   }

}

void readFile(std::vector <TaxRates_ST> &taxRates_st, const char* fileName)
{
   std::ifstream taxRateFile;
   taxRateFile.open(fileName);

   TaxRates_ST temp{};

   if (!taxRateFile)
   {
      std::cerr << "\t\t\tError opening the file <" << fileName
         << ">\r\n";
      return;
   }
   else
   {
      while (taxRateFile >> temp.taxRatePercentage >> temp.minTaxIncome)
      {
         if (taxRateFile >> temp.maxTaxIncome)
         {
            taxRates_st.push_back(temp);
         }
         // Since there is no max income earned for the highest tax rate, we just
         // put the value from the min tax income to the max tax income so,
         // it goes to the vector. When it calculates the tax for the highest
         // tax rate, there is no max so the logic cares for the minimum tax income
         // for the highest tax percentage.
         else
         {
            temp.maxTaxIncome = temp.minTaxIncome;
            taxRates_st.push_back(temp);
         }

      }
   }

   taxRateFile.close();
}

void inputNumberOnly(unsigned int &num)
{
   while ((std::cin >> num).fail() || std::cin.peek() != '\n')
   {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\t\t\tYour choice is incorrect. Try again: ";
   }
}

void displayMenu(unsigned int &choice)
{
   std::cout << "\t\t\t\tTax Calculator\n\n"
      << "\t\t\t1.  Married Individuals Filing Joint Returns and Surviving Spouses\r\n"
      << "\t\t\t2.  Head of Households\r\n"
      << "\t\t\t3.  Unmarried Individuals (other than Surviving Spouses and Heads of Households\r\n"
      << "\t\t\t4.  Married Individuals Filing Separate Returns\r\n"
      << "\t\t\t5.  Close the program\r\n"
      << "\t\t\tEnter your choice: ";
   inputNumberOnly(choice);
}

float calculateTaxRate(const char* fileName)
{
   std::vector<TaxRates_ST> listOfTaxRates{};
   float totalTax{};
   unsigned rowNumFound{};

   std::cout << "\t\t\tTaxable Income: $";
   float taxableIncome{};
   std::cin >> taxableIncome;

   readFile(listOfTaxRates, fileName);

   for (unsigned int count = 0; count < listOfTaxRates.size(); ++count)
   {
      if (taxableIncome >= listOfTaxRates[count].minTaxIncome && taxableIncome <= listOfTaxRates[count].maxTaxIncome ||
         taxableIncome > listOfTaxRates[count].maxTaxIncome)
      {
         rowNumFound = count;
      }

   }

   if (DEBUG)
   {
      std::cout << "\t\t\tRow Found at " << rowNumFound + 1 << std::endl;
   }

   bool loopOnce{ false };
   for (int count = rowNumFound; count >= 0; --count)
   {
      if (!loopOnce)
      {
         totalTax += (taxableIncome - listOfTaxRates[count].minTaxIncome) * (listOfTaxRates[count].taxRatePercentage / 100);
         loopOnce = true;
      }
      else
      {
         totalTax += (listOfTaxRates[count].maxTaxIncome - listOfTaxRates[count].minTaxIncome) * (listOfTaxRates[count].taxRatePercentage / 100);
      }

      if (DEBUG)
      {
         std::cout << "Row: " << count << " Running Total Tax: " << static_cast<int>(std::ceil(totalTax)) << " Percentage: " << listOfTaxRates[count].taxRatePercentage / 100 <<
            " Max Income - Min Income: " << listOfTaxRates[count].maxTaxIncome - listOfTaxRates[count].minTaxIncome << " Max Income: " << listOfTaxRates[count].maxTaxIncome <<
            " Min Income: " << listOfTaxRates[count].minTaxIncome << std::endl;
      }
   }

   return std::ceil(totalTax);
}

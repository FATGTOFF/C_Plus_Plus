#include "CoinToss.h"
#include <string>
#include <iostream>
#include <random>
#include <limits>
//#include <chrono>
#include <iomanip>

CoinToss::CoinToss()
{
   // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(std::random_device{}());

    timesToFlipCoin = 0;
    heads = "Heads";
    tails = "Tails";
	   
    //displayTossCoin(); // Perform initial flip.

    countHeads = 0;
    countTails = 0;
    percentageHeads = 0.0;
    percentageTails = 0,0;
}

std::string CoinToss::displayTossCoin()
{
    std::uniform_int_distribution<int> distributionToss(1, 2); // Set the numbers for int.
    coinFlip = distributionToss(generator);

    switch (coinFlip)
    {
    case 1:
    {
	   countHeads++;
	   return heads;
	   break;
    }
    case 2:
    {
	   countTails++;
	   return tails;
	   break;
    }

    }

    return "NO SIDES";
}

void CoinToss::displayCountFlip()
{
    std::cout << "Number of Heads Tosses: " << countHeads << std::endl;
    std::cout << "Number of Tails Tosses: " << countTails << std::endl;
}

void CoinToss::displayCountPercentage()
{
    std::cout << "Percentage of Heads Tosses: " << std::fixed << std::setprecision(2) << percentageHeads << "%" << std::endl;
    std::cout << "Percentage of Tails Tosses: " << percentageTails << "%" << std::endl;
}

void CoinToss::displayGraphicsComparison(double totalFlips)
{
    percentageHeads = (countHeads / totalFlips) * 100;
    percentageTails = (countTails / totalFlips) * 100;

    std::cout << heads << ": ";
    for (int count = 0; count < percentageHeads; count++)
    {
	   std::cout << '*';
    }

    std::cout << std::endl;

    std::cout << tails << ": ";
    for (int count = 0; count < percentageTails; count++)
    {
	   std::cout << '*';
    }

    std::cout << std::endl;
}

void CoinToss::setTimesToFlipCoin()
{
    std::cout << "How many times would you like to flip the coin?: ";
    InputNumber(timesToFlipCoin);
    while (timesToFlipCoin < 0)
    {
	   std::cout << "Your input [" << timesToFlipCoin << "] is not valid\n";
	   std::cout << "Try again.\n";
	   InputNumber(timesToFlipCoin);
    }

}

void CoinToss::InputNumber(int& choice)
{
    bool bFail{ false };

    do
    {
	   std::cin >> choice;
	   bFail = std::cin.fail();
	   if (bFail)
		  std::cout << "Ensure your input is positive numbers only: ";

	   std::cin.clear();
	   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (bFail == true);
}

void CoinToss::resetCount()
{
    percentageHeads = 0.0;
    percentageTails = 0.0;
    countHeads = 0;
    countTails = 0;
}

int CoinToss::getTimesToFlipCoin()
{
    return timesToFlipCoin;
}

#include <iostream>
#include <chrono>
#include <iomanip>
#include "CoinToss.h"

int main()
{

    CoinToss coin;
    char tryAgain{ ' ' };
    bool oneMoreTime{ true };
    int countWrongInput{ 3 };


    while (oneMoreTime)
    {
	   coin.setTimesToFlipCoin();

	   std::cout << std::showpoint << std::setprecision(7);

	   std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now(); // Start the timer

	   for (int count = 0; count < coin.getTimesToFlipCoin(); count++)
			 coin.displayTossCoin();

	   std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now(); // Determine the timer after execution.

	   std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1); // Substract the timer after execution - timer started.

	   std::cout << "Completed Heads/Tails iteration in " << time_span.count() << " seconds." << std::endl; // Notify the user.

	   coin.displayGraphicsComparison(coin.getTimesToFlipCoin());
	   coin.displayCountFlip();

	   coin.displayCountPercentage();
	   coin.resetCount();

	   std::cout << "Try Again?(Y/N): ";
	   std::cin >> tryAgain;
	   while ((toupper(tryAgain) != 'Y') && (toupper(tryAgain) != 'N'))
	   {

		  std::cout << "Sorry, but your answer is not valid\n";
		  std::cout << "You have " << countWrongInput << " tries.\n";
		  std::cout << "Try Again?(Y/N): ";
		  std::cin >> tryAgain;

		  countWrongInput--;
		  if (countWrongInput == 0)
			 tryAgain = 'N';
	   }

	   if (toupper(tryAgain) == 'Y')
		  oneMoreTime = true;

	   else if (toupper(tryAgain) == 'N')
		  oneMoreTime = false;

    }


    return 0;
}
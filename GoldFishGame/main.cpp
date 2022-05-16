#include <iostream>
#include <iomanip> // for toupper function

using std::cin;
using std::cout;
using std::endl;

int computerPick(int fish_in_bowl, int last_taken_human);
int humanPick(int fish_in_bowl);
bool validPick(int num_of_fish);
bool tryAgain(int&, int&);
void directions();

int main()
{
   int fish_in_bowl{ 21 };
   int computerChoice{ 0 };
   int last_taken_human{ 0 };
   bool keepLooping = true;

   /* Display the directions only one time. */
   directions();

   /* Run the while loop with the iteration of 
   each turn between the computer and the human
   player. The loop will stop when the fish counts
   reaches 0 and the player does not want to play 
   anymore. */
   /* NOTE: The logic of this while loop is frowned upon by
   the standard committee "Loops should not have more than
   one "break" or "goto" statement. (https://rules.sonarsource.com/cpp/RSPEC-924)
   There are better ways to control the logic flow, but for now, this would do just
   fine. */
   while (keepLooping == true)
   {
      computerChoice = computerPick(fish_in_bowl, last_taken_human);
      fish_in_bowl -= computerChoice;
      if (fish_in_bowl == 0)
      {
         cout << "The computer wins!" << endl;

         keepLooping = tryAgain(fish_in_bowl, last_taken_human);

         if (keepLooping)
         {
            computerChoice = computerPick(fish_in_bowl, last_taken_human);
            fish_in_bowl -= computerChoice;
         }
         else
         {
            break;
         }

      }

      last_taken_human = humanPick(fish_in_bowl);
      fish_in_bowl -= last_taken_human;

      /* The logic below shall not be reached due to the way is
      set up for the computer to always win. */
      if (fish_in_bowl == 0)
      {
         cout << "The human wins!" << endl;
         keepLooping = tryAgain(fish_in_bowl, last_taken_human);
         if (keepLooping == false)
         {
            break;
         }
      }
      
   }

}

int computerPick(int fish_in_bowl, int last_taken_human)
{
   cout << "\nThere are " << fish_in_bowl << " Goldfish left in the bowl." << endl;
   int computerChoice{};

   if (fish_in_bowl - last_taken_human == 21)
   {
      computerChoice = 1;
      cout << "I THE MIGHTY COMPUTER have taking " << computerChoice << " Goldfish from the fish bowl!" << endl;
      return computerChoice;
   }
   else
   {
      computerChoice = 4 - last_taken_human;
      cout << "I THE MIGHTY COMPUTER have taking " << computerChoice << " Goldfish from the fish bowl!" << endl;
      return computerChoice;
   }

}

int humanPick(int fish_in_bowl)
{
   int num_of_fish{};
   cout << "\nThere are " << fish_in_bowl << " Goldfish left in the bowl." << endl;
   cout << "How many Goldfish would you like to take (1-3): ";
   cin >> num_of_fish;

   /* Keep looping until the user input the valid number */
   while (!validPick(num_of_fish))
   {
      cout << "How many Goldfish would you like to take (1-3): ";
      cin >> num_of_fish;
   }

   return num_of_fish;
}

bool validPick(int num_of_fish)
{
   if (num_of_fish > 0 && num_of_fish < 4)
   {
      return true;
   }
   else
   {
      return false;
   }

}

bool tryAgain(int &fish_in_bowl, int &last_taken_human)
{
   char tryAgain{};
   int countWrongInput{ 3 }; // Number of tries the user has on choosing (Y/N)
   bool oneMoreTime{};

   cout << "\nWould you like to play again? (Y/N) ";
   cin >> tryAgain;

   while ((toupper(tryAgain) != 'Y') && (toupper(tryAgain) != 'N'))
   {

      cout << "Sorry, but your answer is not valid\n";
      cout << "You have " << countWrongInput << " tries.\n";
      cout << "Try Again?(Y/N): ";
      cin >> tryAgain;

      countWrongInput--;
      /* If the user does not input the allowed choice
      (Yy/Nn), then when it reaches 0, it will assume the 
      player does not want to play anymore. */
      if (countWrongInput == 0)
         tryAgain = 'N';
   }

   /* If the player decides to play again, then
   the number of fish in the bowl must be reset and
   the human choice must be reset to 0 because this
   game is set up for the computer to always start. */
   if (toupper(tryAgain) == 'Y')
   {
      oneMoreTime = true;
      fish_in_bowl = 21;
      last_taken_human = 0;
   }
   else if (toupper(tryAgain) == 'N')
   {
      oneMoreTime = false;
   }


   return oneMoreTime;
}

void directions()
{
   cout << "You have chosen to play 21 Goldfish in the fish "
      << "bowl with me the MIGHTY COMPUTER!" << endl;
   cout << "The object of the game is to take 1, 2, or 3 "
      << "Goldfish from the fish bowl on your turn." << endl;
   cout << "The player that removes the last Goldfish from "
      << "the fish bowl wins the game." << endl;
   cout << "Good Luck... you will need it I never lose!" << endl;
}

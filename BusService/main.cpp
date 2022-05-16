#include <iostream>

int main()
{
   const int maxPassengerCapacity{ 50 };

   std::cout << "Number of passenger waiting in the bus: ";
   int numOfPassengers{};
   std::cin >> numOfPassengers;

   if ((numOfPassengers % maxPassengerCapacity) == 0)
   {
      std::cout << numOfPassengers % maxPassengerCapacity << std::endl;
   }
   else
   {
      std::cout << maxPassengerCapacity - (numOfPassengers % maxPassengerCapacity) << std::endl;
   }

}
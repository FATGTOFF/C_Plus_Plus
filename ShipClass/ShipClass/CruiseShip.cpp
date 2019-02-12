#include <iostream>
#include "CruiseShip.h"

CruiseShip::CruiseShip() : Ship()
{
	maxPassengers = 0;
}

CruiseShip::CruiseShip(std::string n, int m) : Ship()
{
	setShipName(n);
	maxPassengers = m;
}

void CruiseShip::setMaxPassengers(int m)
{
	maxPassengers = m;
}

int CruiseShip::getMaxPassengers() const
{
	return maxPassengers;
}

void CruiseShip::print()
{
	std::cout << "Name of the ship: " << getShipName();
	std::cout << "\nThe maximum number of passengers for ship  " << getShipName() << " is: "
		<< maxPassengers << std::endl;
}

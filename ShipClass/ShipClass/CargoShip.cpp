#include <iostream>
#include "CargoShip.h"

CargoShip::CargoShip() : Ship()
{
	cargoCapacity = 0;
}

CargoShip::CargoShip(std::string n, int c) : Ship()
{
	setShipName(n);
	cargoCapacity = c;
}

void CargoShip::setCargoCapacity(int c)
{
	cargoCapacity = c;
}

int CargoShip::getCargoCapacity() const
{
	return cargoCapacity;
}

void CargoShip::print()
{
	std::cout << "Name of the ship: " << getShipName();
	std::cout << "\nThe maximum capacity (tonnage) for ship  " << getShipName() << " is: "
		<< cargoCapacity << std::endl;
}

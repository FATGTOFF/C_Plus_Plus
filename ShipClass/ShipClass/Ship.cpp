#include <iostream>
#include "Ship.h"

Ship::Ship()
{
	shipName = "";
	shipYear = "";
}

Ship::~Ship()
{
	std::cout << "DESTRUCTOr\n";
}

Ship::Ship(std::string n, std::string y)
{
	shipName = n;
	shipYear = y;
}

void Ship::setShipName(std::string n)
{
	shipName = n;
}

void Ship::setShipYear(std::string y)
{
	shipYear = y;
}

std::string Ship::getShipName() const
{
	return shipName;
}

std::string Ship::getShipYear() const
{
	return shipYear;
}

void Ship::print()
{
	std::cout << "Name of the Ship: " << shipName;
	std::cout << "\n Year the Ship " << shipName << " was built: "
		<< shipYear << std::endl;
}

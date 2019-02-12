#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include <string>
#include "Ship.h"

class CargoShip : public Ship
{
	private:
		int cargoCapacity;

	public:
		CargoShip();
		CargoShip(std::string, int);
		void setCargoCapacity(int);
		int getCargoCapacity() const;
		void print();
};
#endif
#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include <string>
#include "Ship.h"

class CruiseShip : public Ship
{
	private:
		int maxPassengers;

	public:
		CruiseShip();
		CruiseShip(std::string, int);
		void setMaxPassengers(int);
		int getMaxPassengers() const;
		void print();

};
#endif
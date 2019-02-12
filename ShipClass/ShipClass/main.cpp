#include <iostream>
#include "CruiseShip.h"
#include "CargoShip.h"

int main()
{
	Ship *ships[3] = {new Ship("Ponderosa", "1998"), 
		new CruiseShip("Testarosa", 1545), 
		new CargoShip("La Quinta", 3455)};

	ships[0]->print();
	ships[1]->print();
	ships[2]->print();

	delete ships[0];
	delete ships[1];
	delete ships[2];

	return 0;
}

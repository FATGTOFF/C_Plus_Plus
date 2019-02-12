#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship
{
	private:
		std::string shipName;
		std::string shipYear;

	public:
		Ship();
		virtual ~Ship();
		Ship(std::string, std::string);
		
		void setShipName(std::string);
		void setShipYear(std::string);
		std::string getShipName() const;
		std::string getShipYear() const;

		virtual void print();
};
#endif

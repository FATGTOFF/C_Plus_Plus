#ifndef PYRAMID_H
#define PYRAMID_H

class Pyramid
{
private:
	double base; //a double for the sides of the pyramid's base in feet
	double slant; //a double for the slant height of all sides from the base to the apex in feet.

public:
	Pyramid();
	Pyramid(double, double);

	void setBase(double);
	void setSlant(double);

	double getBase() const;
	double getSlant() const;

	double getBaseArea() const;
	double getFaceArea() const;
	double getTotalArea() const;
};
#endif

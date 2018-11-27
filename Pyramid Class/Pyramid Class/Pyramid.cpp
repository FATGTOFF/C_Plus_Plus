#include "Pyramid.h"

Pyramid::Pyramid()
{
	base = 0.0;
	slant = 0.0;
}

Pyramid::Pyramid(double b, double s)
{
	base = b;
	slant = s;
}

void Pyramid::setBase(double b)
{
	base = b;
}

void Pyramid::setSlant(double s)
{
	slant = s;
}

double Pyramid::getBase() const
{
	return base;
}

double Pyramid::getSlant() const
{
	return slant;
}

double Pyramid::getBaseArea() const
{
	return base * base;
}

double Pyramid::getFaceArea() const
{
	return base * slant * 0.5;
}

double Pyramid::getTotalArea() const
{
	return (getFaceArea() * 4) + getBaseArea();
}

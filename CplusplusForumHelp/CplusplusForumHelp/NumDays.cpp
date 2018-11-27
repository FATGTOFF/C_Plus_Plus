#include "NumDays.h"

NumDays::NumDays()
{
	days = 0.0;
	hours = 0.0;
}

NumDays::NumDays(double hrs)
{
	hours = hrs;
	days = convertHoursToDays();
}

void NumDays::setHours(double hrs)
{
	hours = hrs;
	convertHoursToDays();
}

void NumDays::setDays(double day)
{
	days = day;
}

double NumDays::convertHoursToDays()
{
	days = hours / 8;
	return days;
}

double NumDays::getHours() const
{
	return hours;
}

double NumDays::getDays() const
{
	return days;
}

NumDays NumDays::operator+(const NumDays &right)
{
	NumDays temp(hours);

	temp.hours = hours + right.hours;
	temp.days = days + right.days;

	return temp;
}

NumDays NumDays::operator-(const NumDays &right)
{
	NumDays temp(hours);

	temp.hours = hours - right.hours;
	temp.days = days - right.days;

	return temp;
}

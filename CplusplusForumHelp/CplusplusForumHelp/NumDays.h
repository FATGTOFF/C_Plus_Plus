#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays
{
private:
	double days;
	double hours;
	double convertHoursToDays();

public:
	NumDays();
	NumDays(double); // Use the hours as the parameter.
	void setHours(double);
	void setDays(double);
	double getHours() const;
	double getDays() const;

	NumDays operator + (const NumDays &);
	NumDays operator - (const NumDays &);
};
#endif

#include <iostream>
#include <string>

struct Person
{
	std::string first_name;
	std::string last_name;
	int bmonth;
	int byear;
	int bdate;
};

struct Date
{
	int month;
	int date;
	int year;
};

void get_info(Person& p)
{
	std::cout << "Enter First Name: ";
	std::cin >> p.first_name;
	std::cout << "Enter Last Name: ";
	std::cin >> p.last_name;
	std::cout << "Enter Birth Year: ";
	std::cin >> p.byear;
	std::cout << "Enter Birth Date: ";
	std::cin >> p.bdate;
	std::cout << "Enter Birth Month: ";
	std::cin >> p.bmonth;
}

int calc_age(Date& d, Person& p)
{
	int age = d.year - p.byear;

	return age;
}

void print_info(Person& p, Date& d)
{
	std::cout <<"Name: " << p.last_name << ", "
	<< p.first_name << std::endl;

	std::cout <<"Age: " << calc_age(d,p) << std::endl;
}

int main()
{
	Person p;
	Date Date_Today{12,7,2018};
	get_info(p);
	calc_age(Date_Today,p);
	print_info(p,Date_Today);
	return 0;
}
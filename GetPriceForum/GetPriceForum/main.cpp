/* QUESTION */
/* Write a function named getPrice
 It takes in one parameter called size which is a character and
 returns the price depending on the size
 When size is 'L' return 20.00
 When size is 'M' return 15.00
 When size is 'S' return 10.00
 For all other chars, return -1
 Use switch case statement
*/

#include <iostream>
#include <iomanip> // For the use of std::fixed and setprecision(2)
using namespace std;

double getPrice() {
	char size{};
	cout << "Enter size: ";
	cin >> size;

	double price = 1;

	switch (size) {
	case 'L':
		price = 20.00;
		break;
	case 'M':
		price = 15.00;
		break;
	case 'S':
		price = 10.00;
		break;
	default:
		price = -1;
	}
	return price;
}

int main() {
	cout << fixed << setprecision(2);
	cout << getPrice();
}
#ifndef GALLOW_H
#define GALLOW_H

#include <iomanip>
#include <iostream>
#include <string>

class Gallow
{
private:

	// Display Gallow variables.
	const std::string horizontalPole{ "+----+" };
	const std::string floor{ "============" };
	const char verticalPole{ '|' };
	const char rope{ '|' };

	// Display Hangman variables.
	const char torso{ '|' };
	const char head{ 'O' };
	const char leftArm{ '\\' };
	const char rightArm{ '/' };
	const char leftLeg{ '/' };
	const char rightLeg{ '\\' };

public:

	Gallow() = default;

	//Function to display the hangman.
	void displayGallow() const;
	void displayHead() const;
	void displayLeftArm() const;
	void displayRightArm() const;
	void displayRightLeg() const;
	void displayLeftLeg() const;

};
#endif
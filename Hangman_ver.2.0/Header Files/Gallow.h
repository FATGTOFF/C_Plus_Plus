#ifndef GALLOW_H
#define GALLOW_H
#include <string>

class Gallow
{
protected:
	// Display Hangman variables.
	char torso;
	char head;
	char leftArm;
	char rightArm;
	char leftLeg;
	char rightLeg;

	// Display Gallow variables.
	std::string horizontalPole;
	char verticalPole;
	char rope;
	std::string floor;

	//Function to display the hangman.
	void displayGallow() const;
	void displayHead() const;
	void displayLeftArm() const;
	void displayRightArm() const;
	void displayRightLeg() const;
	void displayLeftLeg() const;

public:

	Gallow();

};
#endif
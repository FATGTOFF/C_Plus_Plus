#include "Gallow.h"

void Gallow::displayGallow() const
{
	std::cout << '\n' << '\n';
	std::cout << std::setw(9) << horizontalPole << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(14) << floor << '\n';
}


void Gallow::displayHead() const
{
	std::cout << '\n' << '\n';
	std::cout << std::setw(9) << horizontalPole << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << torso << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(14) << floor << '\n';
}

void Gallow::displayLeftArm() const
{
	std::cout << '\n' << '\n';
	std::cout << std::setw(9) << horizontalPole << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(14) << floor << '\n';
}

void Gallow::displayRightArm() const
{
	std::cout << '\n' << '\n';
	std::cout << std::setw(9) << horizontalPole << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << rightArm << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(14) << floor << '\n';

}

void Gallow::displayRightLeg() const
{
	std::cout << '\n' << '\n';
	std::cout << std::setw(9) << horizontalPole << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << rightArm << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << torso << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(6) << rightLeg << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(14) << floor << '\n';

}

void Gallow::displayLeftLeg() const
{
	std::cout << '\n' << '\n';
	std::cout << std::setw(9) << horizontalPole << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << rightArm << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(5) << torso << std::setw(4) << '\n';
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftLeg << std::setw(2) << rightLeg << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(4) << verticalPole << '\n';
	std::cout << std::setw(14) << floor << '\n';

}
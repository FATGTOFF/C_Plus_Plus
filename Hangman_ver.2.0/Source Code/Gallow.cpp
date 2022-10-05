#include "Gallow.h"
#include <iostream>
#include <iomanip>


Gallow::Gallow()
{
	 torso= '|' ;
	 head= 'O' ;
	 leftArm= '\\';
	 rightArm= '/';
	 leftLeg='/';
	 rightLeg= '\\';

	 horizontalPole= "+----+";
	 verticalPole= '|';
	 rope= '|';
	 floor= "============";
}

void Gallow::displayGallow() const
{
	std::cout << std::endl << std::endl;
	std::cout << std::setw(9) << horizontalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole <<  std::endl;
	std::cout << std::setw(4) << verticalPole <<  std::endl;
	std::cout << std::setw(4) << verticalPole <<  std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(14) << floor << std::endl;
}


void Gallow::displayHead() const
{
	std::cout << std::endl << std::endl;
	std::cout << std::setw(9) << horizontalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << torso << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(14) << floor << std::endl;
}

void Gallow::displayLeftArm() const
{
	std::cout << std::endl << std::endl;
	std::cout << std::setw(9) << horizontalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(14) << floor << std::endl;
}

void Gallow::displayRightArm() const
{
	std::cout << std::endl << std::endl;
	std::cout << std::setw(9) << horizontalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << rightArm << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(14) << floor << std::endl;

}

void Gallow::displayRightLeg() const
{
	std::cout << std::endl << std::endl;
	std::cout << std::setw(9) << horizontalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << rightArm << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << torso << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(6) << rightLeg << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(14) << floor << std::endl;

}

void Gallow::displayLeftLeg() const
{
	std::cout << std::endl << std::endl;
	std::cout << std::setw(9) << horizontalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << rope << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << head << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftArm << torso << rightArm << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(5) << torso << std::setw(4) << std::endl;
	std::cout << std::setw(4) << verticalPole << std::setw(4) << leftLeg << std::setw(2) << rightLeg << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(4) << verticalPole << std::endl;
	std::cout << std::setw(14) << floor << std::endl;

}
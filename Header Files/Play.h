#ifndef PLAY_H
#define PLAY_H
#include <iostream>
#include <string>
#include "Gallow.h"
#include "menu.h"

class Play : public Gallow, Menu
{
private:

	char *answer{ nullptr };
	int countWrongGuess;
	std::string word;
	int MAX_TRIES;
	int letterFill(char, std::string, std::string&);

public:

	Play(std::string);
	~Play();

	// Friends
	//friend ostream & operator << (ostream&, const Play &obj);
	friend std::istream & operator >> (std::istream&, Play &obj);



};
#endif
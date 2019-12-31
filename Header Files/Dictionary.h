#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>

class Dictionary
{
private:

	std::string *words{ nullptr };
	int totalElements;
	int numElements;           // Number of elements.
	int getTotalElements() const;
	std::string FileName;
	int randomNumber(int) const;

public:

	Dictionary();
	~Dictionary();
	std::string getWord() const;

};
#endif
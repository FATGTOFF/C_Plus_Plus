#ifndef USABIRDS_H
#define USABIRDS_H
#include <string>

class USABirds
{
private:

	std::string *birds{ nullptr };
	int totalElements;
	int numElements;           // Number of elements.
	int getTotalElements() const;
	std::string FileName;
	int randomNumber(int) const;

public:

	USABirds();
	~USABirds();
	std::string getWord() const;

};
#endif
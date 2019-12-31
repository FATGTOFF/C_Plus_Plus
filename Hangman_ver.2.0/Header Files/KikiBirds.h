#ifndef KIKIBIRDS_H
#define KIKIBIRDS_H
#include <string>

class KIKIBirds
{
private:

	std::string *birds{ nullptr };
	int totalElements;
	int numElements;           // Number of elements.
	int getTotalElements() const;
	std::string FileName;
	int randomNumber(int) const;

public:

	KIKIBirds();
	~KIKIBirds();
	std::string getWord() const;

};
#endif
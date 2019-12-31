#ifndef BIRDS_H
#define BIRDS_H
#include <string>


class Birds
{
private:

	std::string* birds = nullptr;
	int totalElements;
	int numElements;           // Number of elements.
	int getTotalElements(std::string) const;
	int randomNumber(int) const;

public:

	Birds(std::string);
	~Birds();
	std::string getWord() const;
};
#endif

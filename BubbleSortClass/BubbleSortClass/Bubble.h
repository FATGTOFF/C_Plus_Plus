#ifndef BUBBLE_H
#define BUBBLE_H
#include <fstream>
#include <string>

class Bubble
{
private:
	int *data; //Pointer to the array.
	int numElements;
	std::ifstream inputData;
	std::ofstream outputData;
	void countNumOfElements();

public:
	Bubble();
	~Bubble();

	void getData(std::string);
	void bubbleSort();
	void writeData(std::string);

};
#endif

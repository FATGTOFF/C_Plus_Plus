#include "Bubble.h"

int main()
{
	Bubble obj1;
	obj1.getData("source.txt");
	obj1.bubbleSort();
	obj1.writeData("result.txt");

}
#include <stdio.h>
#include "StructHeader.h"
#include "StructHeader_2.h"
#include "StructHeader_3.h"


int main()
{
	structsOfNum.num1 = 45;

	printf("main() num1: %d\r\n", structsOfNum.num1);

	printNum1();
	printNum2();
}
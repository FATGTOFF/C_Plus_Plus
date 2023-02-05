#include <stdio.h>	/* printf */
#include "StructHeader.h" /* NUM_STRUCTS_ST structsOfNum */


void printNum2()
{
	structsOfNum.num1 = 98;

	printf("printNum2() num1: %d\r\n", structsOfNum.num1);
}

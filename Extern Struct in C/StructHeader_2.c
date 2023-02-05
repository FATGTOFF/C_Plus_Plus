#include <stdio.h>	/* printf */
#include "StructHeader.h" /* NUM_STRUCTS_ST structsOfNum */
#include "StructHeader_2.h" /* printNum1() */


void printNum1()
{
	structsOfNum.num1 = 10;

	printf("printNum1() num1: %d\r\n", structsOfNum.num1);
}
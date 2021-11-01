#include <stdio.h>
#include "Shape.h"

int main()
{
   Shape s1;
   Shape s2;

   ctor(&s1, 0, 1);
   ctor(&s2, -1, 2);

   printf("Shape s1 (x = %d, y = %d) \r\n", s1.getX(&s1), s1.getY(&s1));
   printf("Shape s2 (x = %d, y = %d) \r\n", s2.getX(&s2), s2.getY(&s2));

   s1.setX(&s1, 3);
   s1.setY(&s1, 7);

   s2.setX(&s2, 8);
   s2.setY(&s2, 4);

   printf("Shape s1 (x = %d, y = %d) \r\n", s1.getX(&s1), s1.getY(&s1));
   printf("Shape s2 (x = %d, y = %d) \r\n", s2.getX(&s2), s2.getY(&s2));

   return 0;
}
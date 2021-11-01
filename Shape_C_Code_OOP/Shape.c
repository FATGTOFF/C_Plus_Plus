#include "Shape.h"
#include <stdlib.h>

void ctor(Shape* const self, int x, int y)
{
   if (self)
   {
      self->setX = &setX_init;
      self->setY = &setY_init;
      self->getX = &getX_init;
      self->getY = &getY_init;
      self->x = x;
      self->y = y;
   }
}

void setX_init(Shape* const self, int x)
{
   self->x = x;
}

void setY_init(Shape* const self, int y)
{
   self->y = y;
}

int getX_init(const Shape* self)
{
   return self->x;
}


int getY_init(const Shape* self)
{
   return self->y;
}

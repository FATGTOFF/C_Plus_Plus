#ifndef SHAPE_H
#define SHAPE_H

// Forward declaration
typedef struct Shape_s Shape;

/* Shape attributes */
struct Shape_s
{
   int x;
   int y;
   void (*setX)(Shape* const, int);
   void (*setY)(Shape* const, int);
   int (*getX)(const Shape*);
   int (*getY)(const Shape*);
};

/* Shape operations */
void ctor(Shape* const self, int x, int y);
void setX_init(Shape* const self, int x);
void setY_init(Shape* const self, int y);
int getX_init(const Shape* self);
int getY_init(const Shape* self);

#endif /* SHAPE_H */
//Jack Bao and Jewon Oh
//food.h
#ifndef FOOD_H
#define FOOD_H
#include "gfxnew.h"

//For further desciption of these functions, consult the .cpp file.
class Food{
  public:
      Food();
      Food(int, int);
      ~Food();
      void setX(int);
      void setY(int);
      void setLocation(int, int);
      int getX();
      int getY();
      void draw();
      Food& operator=(Food);

  private:
      int x;
      int y;
};

#endif

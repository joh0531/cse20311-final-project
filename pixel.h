#ifndef PIXEL_H
#define PIXEL_H
#include "gfxnew.h"

class Pixel{

public:
  Pixel();
  Pixel(int, int);
  ~Pixel();
  void setX(int);
  void setY(int);
  void setLocation(int, int);
  int getX();
  int getY();
  void draw();
  Pixel& operator=(Pixel&);

private:
    int x;
    int y;
};

#endif

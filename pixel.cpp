//Jack Bao and Jewon Oh
//pixel.cpp
#include "pixel.h"

/*x and y are the x and y coordinates of the pixel on the field. These are all
fairly standard methods for accessing x and y and initializing a pixel object.*/

Pixel::Pixel(){
  x = 0;
  y = 0;
}

Pixel::Pixel(int a, int b){
  x = a;
  y = b;
}

Pixel::~Pixel(){
}

void Pixel::setX(int a){
  x = a;
}

void Pixel::setY(int a){
  y = a;
}

void Pixel::setLocation(int a, int b){
  x = a;
  y = b;
}

int Pixel::getX(){
  return x;
}

int Pixel::getY(){
  return y;
}

void Pixel::draw(){
    int side = 20;
    gfx_fill_rectangle(x * 20+20 , y * 20+20, side, side);
}
//Overload assignment operator for convenient use later.
Pixel& Pixel::operator= (Pixel &a){
  x = a.x;
  y = a.y;

  return *this;
}

#include "pixel.h"

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
    int side = 20; //block size is 20 pixels
    for (int i = y; i < y + side; i++)
    {
        for (int j = x; j < x + side; j++)
        {
            gfx_point(i, j);
        }
    }
}

Pixel& Pixel::operator= (Pixel &a){
  x = a.x;
  y = a.y;

  return *this;
}

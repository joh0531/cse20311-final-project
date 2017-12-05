#include "pixel.h"

pixel::pixel(){
  x = 0;
  y = 0;
}

pixel::pixel(int a, int b){
  x = a;
  y = b;
}

pixel::~pixel(){
}

void pixel::setX(int a){
  x = a;
}

void pixel::setY(int a){
  y = a;
}

void pixel::setLocation(int a, int b){
  x = a;
  y = b;
}

int pixel::getX(){
  return x;
}

int pixel::getY(){
  return y;
}

void pixel::draw(){ }

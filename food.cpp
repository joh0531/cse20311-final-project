//Jack Bao and Jewon Oh
//food.cpp
#include "food.h"

/*x and y are the x and y coordinates of the food on the field. These are all
fairly standard methods for accessing x and y and initializing a food object.*/

Food::Food(){
  x = 0;
  y = 0;
}

Food::Food(int a, int b){
  x = a;
  y = b;
}

Food::~Food(){
}

void Food::setX(int a){
  x = a;
}

void Food::setY(int a){
  y = a;
}

void Food::setLocation(int a, int b){
  x = a;
  y = b;
}

int Food::getX(){
  return x;
}

int Food::getY(){
  return y;
}

void Food::draw(){
    int rad = 10;
    gfx_fill_circle(x * 20+20 + rad, y * 20+20 + rad, rad);
}

//Overload assignment operator for convenient use later.
Food& Food::operator=(Food a){
  x = a.x;
  y = a.y;

  return *this;
}

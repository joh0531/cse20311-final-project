#include "food.h"

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

void Food::draw(){ }

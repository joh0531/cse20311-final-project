#include "food.h"

food::food(){
  x = 0;
  y = 0;
}

food::food(int a, int b){
  x = a;
  y = b;
}

food::~food(){
}

void food::setX(int a){
  x = a;
}

void food::setY(int a){
  y = a;
}

void food::setLocation(int a, int b){
  x = a;
  y = b;
}

int food::getX(){
  return x;
}

int food::getY(){
  return y;
}

void food::draw(){ }

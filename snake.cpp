#include "snake.h"

Snake::Snake(){
  live_snake.push_back(Pixel(15,15));
  live_snake.push_back(Pixel(15,15));
  live_snake.push_back(Pixel(15,15));
  speed = 1;
  direction = 0;
  score = 3;
}

Snake::~Snake(){ }

Pixel Snake::getPixel(int a){
  return live_snake[a];
}

void Snake::setPixel(int l, int a, int b){
  live_snake[l].setLocation(a,b);
}

int Snake::getSpeed(){
  return speed;
}

void Snake::setSpeed(int a){
  speed = a;
}

int Snake::getDirection(){
  return direction;
}

void Snake::setDirection(int a){
  direction = a;
}

void Snake::addPixel(int a, int b){
  live_snake.push_back(Pixel(a,b));
}

int Snake::getScore(){
  return score;
}

void Snake::updateScore(){
  score = live_snake.size();
}

bool Snake::checkFood(Food a){
  if (a.getX() == live_snake[0].getX() && a.getY() == live_snake[0].getY()){
    return true;
  }
  return false;
}

void Snake::eatFood(int s, int a, int b){
  for(int i = 1; i<= s; i++){
    this->addPixel(a, b);
  }
  if (speed < 16){
    speed++;
  }
  this->updateScore();
}

bool Snake::checkDeath(){
  if (live_snake.size()>1){
    auto it = live_snake.begin();
    it++;
    while(it != live_snake.end()){}
      if(it->getX() == live_snake[0].getX() && it->getY() == live_snake[0].getY()){
        return true;
      }
      it++;
    }
  if (live_snake[0].getX() > 30 || live_snake[0].getX()<0){
    return true;
  }
  if (live_snake[0].getY() > 30 || live_snake[0].getY()<0){
    return true;
  }
  return false;
}

void Snake::drawSnake(){
  for(auto it = live_snake.begin(); it != live_snake.end(); it++){
    it->draw();
  }
}

void Snake::incrementSnake(){
    auto it = live_snake.begin();
    it++;
    auto it2 = live_snake.begin();
    while (it != live_snake.end()){
      *it = *it2;
      it++;
      it2++;
    }
    switch(direction){
      case 0:
      {
        int a = live_snake[0].getX() + 1;
        live_snake[0].setX(a);
        break;
      }
      case 1:
      {
        int a = live_snake[0].getY() - 1;
        live_snake[0].setY(a);
        break;
      }
      case 2:
      {
        int a = live_snake[0].getX() - 1;
        live_snake[0].setX(a);
        break;
      }
      case 3:
      {
        int a = live_snake[0].getY() + 1;
        live_snake[0].setY(a);
        break;
      }
    }
}

bool Snake::checkFoodSpawn(int x, int y){
  for(auto it = live_snake.begin(); it != live_snake.end(); it++){
    if (x == it->getX() && y == it->getY())
      return false;
    int diffx = abs(it->getX() - x);
    int diffy = abs(it->getY() - y);
    if (diffx == 1 && diffy == 1)
      return false;
  }
  return true;
}

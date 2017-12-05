#include "snake.h"

snake::snake(){
  std::vector<pixel> live_snake;
  live_snake.push_back(pixel(15,15));
  speed = 1;
  direction = 0;
  score = 1;
}

snake::~snake(){ }

pixel snake::getPixel(int a){
  return live_snake[a];
}

void snake::setPixel(int l, int a, int b){
  live_snake[l].setLocation(a,b);
}

void snake::getSpeed(){
  return speed;
}

void snake::setSpeed(int a){
  speed = a;
}

void snake::getDirection(){
  return direction;
}

void snake::setDirection(int a){
  direction = a;
}

void snake::addPixel(int a, int b){
  live_snake.push_back(pixel(a,b));
}

int snake::getScore(){
  return score;
}

void snake::updateScore(){
  score = live_snake.size();
}

bool snake::checkFood(food a){
  if (food.getX() == live_snake[0].getX() && food.getY() == live_snake[0].getY()){
    return true;
  }
  return false;
}

void eatFood(int s, int a, int b){
  for(int i = 1; i<= s; i++){
    this->addPixel(a, b)
  }
}

int checkDeath(){
  if (live_snake.size()>1){
    auto it = live_snake.begin();
    it++;
    while(it != live_snake.end()){}
      if(*it.getX() == live_snake[0].getX() && *it.getY() == live_snake[0].getY()){
        return true;
      }
      it++;
    }
  }
  if (live_snake[0].getX() > 30 || live_snake[0].getX<0){
    return true;
  }
  if (live_snake[0].getY() > 30 || live_snake[0].getY<0){
    return true;
  }
  return false;
}

void drawSnake(){
  for(auto it = live_snake.begin(); it != live_snake.end(); it++){
    *it.draw();
  }
}

void incrementSnake(){
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
        int a = live_snake[0].getX() + 1;
        live_snake[0].setX(a);
        break;
      case 1:
        int a = live_snake[0].getY() - 1;
        live_snake[0].setY(a);
        break;
      case 2:
        int a = live_snake[0].getX() - 1;
        live_snake[0].setX(a);
        break;
      case 3:
        int a = live_snake[0].getY() + 1;
        live_snake[0].setY(a);
        break;
      default:;
    }
}

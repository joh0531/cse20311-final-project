#include "snake.h"

Snake::Snake(){
  live_snake.push_back(Pixel(16,16));
  speed = 1;
  dir = NONE;
  score = 3;
}

Snake::~Snake(){ }

void Snake::update(){
  incrementSnake();
}

void Snake::input(int event, char c){
  switch (c){
    case 'd':
      setDirection(RIGHT);
      break;
    case 'w':
      setDirection(UP);
      break;
    case 'a':
      setDirection(LEFT);
      break;
    case 's':
      setDirection(DOWN);
      break;
  }
}

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
  return dir;
}

void Snake::setDirection(Direction d){
  switch (d)
  {
      case RIGHT:
        if (this->dir != LEFT)
          this->dir = RIGHT;
        break;
      case LEFT:
        if (this->dir != RIGHT)
          this->dir = LEFT;
        break;
      case UP:
        if (this->dir != DOWN)
          this->dir = UP;
        break;
      case DOWN:
        if (this->dir != UP)
          this->dir = DOWN;
        break;
      case NONE:
        break;
  }
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

bool Snake::checkFood(int a, int b){
  if (a == live_snake[0].getX() && b == live_snake[0].getY()){
    return true;
  }
  return false;
}

void Snake::eatFood(int s, int a, int b){
  for(int i = 1; i<= s; i++){
    this->addPixel(a, b);
  }
//  if (speed < 16){
//    speed++;
//  }
  this->updateScore();
}

bool Snake::checkDeath(){
  if (live_snake.size()>1){
    auto it = live_snake.begin();
    it++;
    while(it != live_snake.end()){
      if(it->getX() == live_snake[0].getX() && it->getY() == live_snake[0].getY()){
        return true;
      }
      it++;
    }
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
    auto it2 = live_snake.rbegin();
    it2++;
    for (auto it = live_snake.rbegin(); it != live_snake.rend()-1; it++){
        *it = *it2;
        it2++;
    }
        /*auto it = live_snake.end();
    it--;
    it--;
    auto it2 = live_snake.end();
    it2--;

    do {
      *it2 = *it;
      it--;
      it2--;
    } while (it != live_snake.begin());*/

    switch(this->dir){
      case RIGHT:
      {
        int a = live_snake[0].getX() + 1;
        live_snake[0].setX(a);
        break;
      }
      case UP:
      {
        int a = live_snake[0].getY() - 1;
        live_snake[0].setY(a);
        break;
      }
      case LEFT:
      {
        int a = live_snake[0].getX() - 1;
        live_snake[0].setX(a);
        break;
      }
      case DOWN:
      {
        int a = live_snake[0].getY() + 1;
        live_snake[0].setY(a);
        break;
      }
      case NONE:
        break;
    }
}

bool Snake::checkFoodSpawn(int x, int y){
  for(auto it = live_snake.begin(); it != live_snake.end(); it++){
    if (x == it->getX() && y == it->getY()){
      return false;
    }
  }

  int diffx = std::abs(live_snake[0].getX() - x);
  int diffy = std::abs(live_snake[0].getY() - y);
  if (diffx == 1 && diffy == 1){
    return false;
  }
  return true;
}

void Snake::reset(){
  live_snake.clear();
  live_snake.push_back(Pixel(16,16));
}

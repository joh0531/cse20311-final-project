//Jack Bao and Jewon Oh
//snake.cpp
#include "snake.h"

/*Snake is essentially a class that contains a vector of pixels which represents
the snake. The snake has a couple of private variables to keep track of movement
as well as a private vector of pixels that represents the snake.*/

Snake::Snake(){
  speed = 1;
  dir = NONE;
}

Snake::~Snake(){ }

void Snake::update(){
  incrementSnake();
}

//Interprets input and converts to direction for the snake to travel.
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

//The actual assignment part of the direction.
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
  return live_snake.size();
}

//checks the head's location to see if food is there.
bool Snake::checkFood(int a, int b){
  if (a == live_snake[0].getX() && b == live_snake[0].getY()){
    return true;
  }
  return false;
}

//Increases snake length.
void Snake::eatFood(int s, int a, int b){
  for(int i = 1; i<= s; i++){
    this->addPixel(a, b);
  }
}

//Checks to see if snake dies, either by running into a wall or hitting itself.
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

//draws the snake pixel by ppixel.
void Snake::drawSnake(){
  for(auto it = live_snake.begin(); it != live_snake.end(); it++){
    it->draw();
  }
}

/*The snake moves by assigning each pixel to the value of the one ahead of it
with the head moving a specific direction based on the snake's direciton variable*/
void Snake::incrementSnake(){
    auto it2 = live_snake.rbegin();
    it2++;
    for (auto it = live_snake.rbegin(); it != live_snake.rend()-1; it++){
        *it = *it2;
        it2++;
    }

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

//Check to see if food spawned is a valid spawn.
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

//Resets the snake so that the game can be played again.
void Snake::reset(){
  dir = NONE;
  live_snake.clear();
  live_snake.push_back(Pixel(16,16));
}

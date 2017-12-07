//Jack Bao and Jewon Oh
//snake.h
#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "pixel.h"
#include "food.h"

class Snake{
  public:
      enum Direction{
          UP,
          DOWN,
          LEFT,
          RIGHT,
          NONE
      };
      Snake();
      ~Snake();
      void update();
      void input(int, char);
      Pixel getPixel(int);
      void setPixel(int, int, int);
      int getSpeed();
      void setSpeed(int);
      int getDirection();
      void setDirection(Direction);
      void addPixel(int, int);
      int getScore();
      bool checkFood(int, int);
      void eatFood(int, int, int);
      bool checkDeath();
      void drawSnake();
      //Snake moves by setting a pixel to the value of the pixel in front of it in the Snake.
      void incrementSnake();
      bool checkFoodSpawn(int, int);
      void reset();

  private:
      std::vector<Pixel> live_snake;
      int speed;
      Direction dir;
};

#endif

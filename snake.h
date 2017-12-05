#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "pixel.h"
#include "food.h"

class snake{
  public:
      snake();
      ~snake();
      pixel getPixel(int);
      void setPixel(int, int, int);
      int getSpeed();
      void setSpeed(int);
      int getDirection();
      void setDirection(int);
      void addPixel(int, int);
      int getScore();
      void updateScore();
      bool checkFood(food);
      void eatFood(int, int, int);
      bool checkDeath();
      void drawSnake();

      //snake moves by setting a pixel to the value of the pixel in front of it in the snake.
      void incrementSnake();

  private:
      std::vector<pixel> live_snake;
      int speed;
      int direction;
      int score;
};

#endif

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "pixel.h"
#include "food.h"

class Snake{
  public:
      Snake();
      ~Snake();
      Pixel getPixel(int);
      void setPixel(int, int, int);
      int getSpeed();
      void setSpeed(int);
      int getDirection();
      void setDirection(int);
      void addPixel(int, int);
      int getScore();
      void updateScore();
      bool checkFood(Food);
      void eatFood(int, int, int);
      bool checkDeath();
      void drawSnake();

      //Snake moves by setting a pixel to the value of the pixel in front of it in the Snake.
      void incrementSnake();
      bool checkFoodSpawn(int, int);

  private:
      std::vector<Pixel> live_snake;
      int speed;
      int direction;
      int score;
};

#endif

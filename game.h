#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include <cstdlib>
#include <chrono>
#include <ctime>

class Game{
  public:
    Game();
    ~Game();
    void startGame();
    Food spawnFood(Snake);
    bool checkFoodSpawn(Snake, int, int);


};
#endif

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
    void initializeGame();
    Food spawnFood(Snake);
    bool checkFoodSpawn(Snake, int, int);
private:
    bool gameover = false;
    bool atefood = false;

};
#endif

#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"

class Game{
  public:
    Game();
    ~Game();
    void startGame();
    void initializeGame();
    void spawnFood();
    void checkFoodSpawn();
    void runGame();

};
#endif

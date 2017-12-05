#ifndef GAME_H
#define GAME_H

#include snake.h
#include food.h

class Game{
  public:
    Game();
    ~Game();
    initializeGame();
    spawnFood();
    checkFoodSpawn();
    runGame();


};
#endif

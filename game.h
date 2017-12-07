//Jack Bao and Jewon Oh
//game.h
#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include "gfxnew.h"
#include <cstdlib>
#include <chrono>
#include <ctime>

class Game{
  public:
    Game();
    ~Game();
    void draw();
    void update();
    void input(int, char);
    void startGame();
    void initializeGame();
    void spawnFood();
    bool checkFoodSpawn(int, int);
    void drawBorder();
    enum State{
        WAIT,
        RUN,
        GAMEOVER
    };

private:
    bool gameover = false;
    bool atefood = false;
    State state;
    Snake snake;
    Food food;
};
#endif

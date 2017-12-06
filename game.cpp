#include "game.h"

Game::Game() {}

Game::~Game() {}

void Game::startGame(){
  Snake snake;
  Food food;
  snake.drawSnake();
  food = Game::spawnFood(snake);
  food.draw();
  bool gameover = false;

  while (gameover == false){
    bool atefood = false;
    while (atefood == false && gameover == false){
      std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
      int time_limit = 2000/(snake.getSpeed()+9);
      bool moved = false;
      while (moved == false){
        if (gfx_event_waiting()){
          int direction = 5;
          char c = gfx_wait();
          switch (c){
            case 'd': direction = 0;
              break;
            case 'w': direction = 1;
              break;
            case 'a': direction = 2;
              break;
            case 's': direction = 3;
              break;
            default:;
          }
          if (direction < 5){
            switch(direction){
              case 0:
                if (snake.getDirection() != 2){
                snake.setDirection(direction);
                }
                break;
              case 1:
                if (snake.getDirection() != 3){
                  snake.setDirection(direction);
                }
                break;
              case 2:
                if (snake.getDirection() != 0){
                  snake.setDirection(direction);
                }
                break;
              case 3:
                if (snake.getDirection() != 1){
                  snake.setDirection(direction);
                }
                break;
              default:;
            }
          }
      }

      std::chrono::time_point<std::chrono::system_clock> foo = now + std::chrono::milliseconds(100);
      auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(foo - now);
      auto ms = milliseconds.count();
      if (ms > time_limit){
        gfx_clear();
        snake.incrementSnake();
        snake.drawSnake();
        moved = true;
        if (snake.checkDeath()){
          gameover = true;
        }
        if(snake.checkFood(food)){
          atefood = true;
        }
      }
    }
    }
    snake.eatFood(3, food.getX(), food.getY());
    food = Game::spawnFood(snake);
    gfx_clear();
    food.draw();
    snake.drawSnake();
  }

}


Food Game::spawnFood(Snake snake) {
  bool check = false;
  int randx = 0;
  int randy = 0;
  while (check == false){
    randx = rand() % 31;
    randy = rand() % 31;
    check = Game::checkFoodSpawn(snake, randx, randy);
  }
  Food s;
  s = Food(randx, randy);
  return s;
}

bool Game::checkFoodSpawn(Snake snake, int x, int y) {
  bool logic = snake.checkFoodSpawn(x,y);
  return logic;
}

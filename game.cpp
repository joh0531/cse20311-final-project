#include "game.h"

Game::Game() {}

Game::~Game() {}

void Game::startGame(){
  Snake snake;
  Food food;
  snake.drawSnake();
  food = Game::spawnFood(snake);
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
  s = Food(randx, randy);
  return s;
}

bool Game::checkFoodSpawn(Snake snake, int x, int y) {
  snake.checkFoodSpawn(x,y);

}
void Game::runGame() {}

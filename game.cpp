#include "game.h"
#include <string>

Game::Game() {
    state = WAIT;
    gfx_color(255,255,255);
}

Game::~Game() {}

void Game::draw(){
    switch (state)
    {
        case WAIT:
        {
            char text[] = "click to begin game";
            char font[] = "12x24";
            gfx_changefont(font);
            int wd = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text, font) / 2);
            int ht = (gfx_windowheight() / 2) - (gfx_textpixelheight(text, font) / 2);
            gfx_text(wd, ht, text); //output something saying "click to begin game"
            break;
        }
        case RUN:
            //gfx_color(255, 0, 0);
            food.draw();
            //gfx_color(0, 255, 0);
            snake.drawSnake();
            drawBorder();
            break;
        case GAMEOVER:
        {
            gfx_clear();
            char text1[] = "GAME OVER!";
            char scoreText[] = "Score: ";
            char score[] = c_str(std::to_string(snake.getScore()));
            char text2[] = strcat(scoreText, score);
            char font[] = "12x24";
            gfx_changefont(font);
            int wd1 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text1, font) / 2);
            int ht1 = (gfx_windowheight() / 2) - (gfx_textpixelheight(text1, font) / 2);
            int wd2 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text2, font) / 2);
            int ht2 = (gfx_windowheight() / 2) - (gfx_textpixelheight(text2, font) / 2) + 20;
            gfx_text(wd1, ht1, text1);
            gfx_text(wd2, ht2, text2);
            break;
        }
    }
}

void Game::update(){
    switch (state)
    {
        case WAIT:
            break;
        case RUN:
        {
            //while (gameover == false){
              //while (atefood == false && gameover == false){
                //std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
                //int time_limit = 2000000/(snake.getSpeed()+9);
                //bool moved = false;
                //while (moved == false){
                  //if (gfx_event_waiting()){
                    //int direction = 5;
                    //char c = gfx_wait();
                    //if (direction < 5){
                      snake.update();
                      if (snake.checkDeath()){
                        state = GAMEOVER;
                      }
                      gfx_fill_circle(30,10,10);
                      if (snake.checkFood(food.getX(), food.getY())){
                        snake.eatFood(3, food.getX(), food.getY());
                        spawnFood();
                      }

                    //}
                //}

                //std::chrono::time_point<std::chrono::system_clock> foo = now + std::chrono::milliseconds(100);
                //auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(foo - now);
                //auto ms = milliseconds.count();
                /*if (ms > time_limit){
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
                }*/
              //}
              //}
              //snake.eatFood(3, food.getX(), food.getY());
              //food = this->spawnFood(snake);
            //}
        }
        break;
        case GAMEOVER:
            break;
    }
}

void Game::input(int event, char c){
    switch (state)
    {
        case WAIT:
            if (c == 1)
                startGame();
            break;
        case RUN:
            snake.input(event, c);
            break;
        case GAMEOVER:
            break;
    }
}

void Game::startGame(){
  state = RUN;
  snake.reset();
  spawnFood();
}


Food Game::spawnFood() {
  bool check = false;
  int randx = 0;
  int randy = 0;
  while (check == false){
    randx = rand() % 31;
    randy = rand() % 31;
    check = checkFoodSpawn(randx, randy);
  }
  food.setLocation(randx, randy);
}

bool Game::checkFoodSpawn(int x, int y) {
  bool logic = snake.checkFoodSpawn(x,y);
  return logic;
}

void Game::drawBorder(){
  for (int i = 0; i <= 32; i++){
    gfx_fill_rectangle(20*i, 0, 20, 20);
    gfx_fill_rectangle(20*i, 640, 20, 20);
  }
  for (int j = 0; j <= 32; j++){
    gfx_fill_rectangle(0, 20*j, 20, 20);
    gfx_fill_rectangle(640, 20*j, 20, 20);
  }
}

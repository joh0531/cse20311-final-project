#include "game.h"
#include <cstring>
#include <string>
#include <iostream>

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
            char text[] = "press enter to begin game";
            char font[] = "12x24";
            gfx_changefont(font);
            int wd = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text, font) / 2);
            int ht = (gfx_windowheight() / 2) - (gfx_textpixelheight(text, font) / 2);
            gfx_text(wd, ht, text);
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
            char text2[15];
            std::string score = "Score: " + std::to_string(snake.getScore());
            score.copy(text2, score.size());
            text2[score.size()] = '\0';
            char font[] = "12x24";
            char text3[] = "press enter to play again, press 'q' to quit";
            gfx_changefont(font);
            gfx_color(255, 255, 255);
            int wd1 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text1, font) / 2);
            int ht1 = (gfx_windowheight() / 2) - (gfx_textpixelheight(text1, font) / 2);
            int wd2 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text2, font) / 2);
            int ht2 = ht1 + (gfx_textpixelheight(text2, font));
            int wd3 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text3, font) / 2);
            int ht3 = ht2 + (gfx_textpixelheight(text3, font));
            gfx_text(wd1, ht1, text1);
            gfx_text(wd2, ht2, text2);
            gfx_text(wd3, ht3, text3);
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
          snake.update();
          if (snake.checkDeath()){
            state = GAMEOVER;
          }
          gfx_fill_circle(30,10,10);
          if (snake.checkFood(food.getX(), food.getY())){
            snake.eatFood(3, food.getX(), food.getY());
            spawnFood();
          }
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
            if (c == 13)
              startGame();
            break;
        case RUN:
            snake.input(event, c);
            break;
        case GAMEOVER:
            if (c == 13)
              startGame();
            break;
    }
}

void Game::startGame(){
  state = RUN;
  snake.reset();
  spawnFood();
}


void Game::spawnFood() {
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

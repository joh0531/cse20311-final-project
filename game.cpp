//Jack Bao and Jewon Oh
//game.cpp
#include "game.h"
#include <cstring>
#include <string>
#include <iostream>

/*Game is controlled by a state machine. THe state machine mostly only deals
with the highest level of game, that is when to draw, when to update the snake's
location, and when the game is over.*/

Game::Game() {
    state = WAIT;
    gfx_color(255,255,255);
}

Game::~Game() {}

/*draw either the start screen, the game, or the game-over screen, depending on
the state.*/
void Game::draw(){
    switch (state)
    {
        case WAIT:
        {
            char text1[] = "SNAKE";
            char text2[] = "press enter to begin game";
            char font[] = "12x24";
            gfx_changefont(font);
            int wd1 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text1, font) / 2);
            int ht1 = (gfx_windowheight() / 2) - (gfx_textpixelheight(text1, font) / 2);
            int wd2 = (gfx_windowwidth() / 2) - (gfx_textpixelwidth(text2, font) / 2);
            int ht2 = ht1 + gfx_textpixelheight(text2, font);
            gfx_text(wd1, ht1, text1);
            gfx_text(wd2, ht2, text2);
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

/*Update the snake's location if game is in the run state. It also runs through
a variety of checks, such as when the snake dies or when the snake eats food.
If the first occurs, assign the state to be GAMEOVER. If snake eats food, then
make the snake grow.
*/
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

//Grabs input if there is some.
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

//starts the game by changing state to RUN.
void Game::startGame(){
  state = RUN;
  snake.reset();
  spawnFood();
}

/*Spawns the food by randomly choosing a locaiton, then seeing if the Location
is a valid spawn point for food.*/
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

/*Checks whether the food spawned is valid by seeing if a pixel is at the Location
or if the head of the snake is one block away*/
bool Game::checkFoodSpawn(int x, int y) {
  bool logic = snake.checkFoodSpawn(x,y);
  return logic;
}

//Draws the walls around the game.
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

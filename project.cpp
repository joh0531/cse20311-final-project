//Jack Bao and Jewon Oh
//project.cpp
#include "gfxnew.h"
#include "game.h"
#include <unistd.h>
#include <cmath>

//window size
const int WIDTH = 660;
const int HEIGHT = 660;
const int FPS = 60;

//Main for our project. Main basically just controls game and also decides when to update the snake's position.
int main()
{
    gfx_open(WIDTH, HEIGHT, "Snake");

    //initiialize game.
    Game game;
    bool quit = false;
    double dt = 1.0 / FPS;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    gfx_clear();
    game.draw();
    gfx_flush();

    while (!quit){
      //chrono is used to keep track of time since last update to know when to update the snake.
      std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
      auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      auto ms = milliseconds.count();

      //update the snake if a certain amount of time has passed
      if (ms > 70){
        game.update();
        start = std::chrono::system_clock::now();
        gfx_clear();
        game.draw();
        gfx_flush();
      }

      //grab input if there is some
      int event = gfx_event_waiting();
      if (event != 0)
      {
          char c = gfx_wait();
          if (c == 'q')
            quit = true;
          else
            game.input(event, c);
      }
    }

    return 0;
}

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

int main()
{
    gfx_open(WIDTH, HEIGHT, "Snake");

    Game game;
    bool quit = false;
    double dt = 1.0 / FPS;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

    gfx_clear();
    game.draw();
    gfx_flush();

    while (!quit){

      //draw
      //gfx_clear();
      //game.draw();
      //gfx_flush();

      //sleep
      //usleep(dt * pow(10, 6)*2);
      std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
      auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      auto ms = milliseconds.count();
      //update
      if (ms > 70){
        game.update();
        start = std::chrono::system_clock::now();
        gfx_clear();
        game.draw();
        gfx_flush();
      }
      //input
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

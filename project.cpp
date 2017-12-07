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

    while (!quit){
      //draw
      gfx_clear();
      game.draw();
      gfx_flush();

      //sleep
      usleep(dt * pow(10, 6)*2);

      //update
      game.update();

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

#include "gfx.h"
#include "game.h"

int main()
{
    WIDTH = 640; HEIGHT = 640;
    gfx_open(WIDTH, HEIGHT, "Snake");

    gfx_text//output something saying "click to begin game"
    char c = gfx_wait();

    while (c != 'q'){
      if (c == 1){
        Game();
        gfx_test//output something asking user if he wants to play again
        //output: "click to play again, q to quit"
      }
      c = 0;
      gfx_wait();
    }

    return 0;
}

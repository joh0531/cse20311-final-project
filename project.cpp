#include "gfx.h"
#include "game.h"

int main()
{
    gfx_open(WIDTH, HEIGHT, "Snake");

    gfx_text(WIDTH / 2 - 52, HEIGHT / 2, "click to begin game"); //output something saying "click to begin game"
    char c = gfx_wait();
    Game game;
    game.startGame();

    while (c != 'q'){
      gfx_clear();
      if (c == 1){
        //output something asking user if he wants to play again
        //output: "click to play again, q to quit"
      }
      c = 0;
      gfx_wait();
    }

    return 0;
}

#include <exception>
#include <string>
#include <iostream>
#include "SDL2/SDL.h"
#include <Game.h>

Game *game = nullptr;

const int fps = 60;
const int frameDelay = 1000 / fps;

int main( int argc, char * argv[] )
{
    Uint32 frameStart;
    int frameTime;
    game = new Game();

    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running()){
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}

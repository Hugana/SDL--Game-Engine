#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

#include <iostream>

class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* tittle, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running();

    protected:

    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer* renderer;
};

#endif // GAME_H

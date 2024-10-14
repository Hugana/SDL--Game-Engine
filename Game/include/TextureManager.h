#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();
        static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);

    protected:

    private:
};

#endif // TEXTUREMANAGER_H

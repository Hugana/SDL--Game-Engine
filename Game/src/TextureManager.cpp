#include "TextureManager.h"

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren){

    SDL_Surface* tmpSurface = IMG_Load(filename);

    if (!tmpSurface) {
        std::cout << "Failed to load image: " << IMG_GetError() << "\n";
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren,tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;


}

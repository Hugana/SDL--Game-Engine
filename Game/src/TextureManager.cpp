#include "TextureManager.h"
#include "Game.h"

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

SDL_Texture* TextureManager::LoadTexture(const char* filename){

    SDL_Surface* tmpSurface = IMG_Load(filename);

    if (!tmpSurface) {
        std::cout << "Failed to load image: " << IMG_GetError() << "\n";
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}

void Draw(SDL_Texture* tex, const SDL_Rect* src, const SDL_Rect* dest) {
    SDL_RenderCopy(Game::renderer, tex, src, dest);
}




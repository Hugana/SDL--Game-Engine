#include "TextureManager.h"
#include "Game.h"
#include <SDL2/SDL_ttf.h>

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

SDL_Texture* TextureManager::LoadFontTexture(const char* filename, int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, const char* text){

    if (TTF_Init() == -1) {
            std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
            exit(1);
    }

    TTF_Font* fontObj = TTF_OpenFont(filename, fontSize);

    if (!fontObj) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        exit(1);
    }

    SDL_Color color = {r,g,b,a};

    SDL_Surface* textSurface = TTF_RenderText_Blended(fontObj, text, color);

    if (!textSurface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        exit(1);
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
    if (!textTexture) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_FreeSurface(textSurface);
    TTF_CloseFont(fontObj);


    return textTexture;

}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}




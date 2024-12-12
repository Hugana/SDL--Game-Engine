#include "Game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();
        static SDL_Texture* LoadTexture(const char* filename);
        static SDL_Texture* LoadFontTexture(const char* filename, int fontSize, Uint8 r, Uint8 g, Uint8 b,Uint8 a, const char* text);
        static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

    protected:

    private:
};


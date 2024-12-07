#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL_image.h>

class GameObject
{
    public:
        GameObject(const char* textureSheet,int x, int y, int srcX, int srcY, int srcW, int srcH);
        virtual ~GameObject();

        void Update();
        void Render();
        void SetSourceRect(int x, int y, int w, int h);
        int xpos;
        int ypos;



    protected:

    private:
        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;
};

#endif // GAMEOBJECT_H

#ifndef MAP_H
#define MAP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Map
{
    public:
        Map();
        virtual ~Map();
        void drawMap();
        void loadMap();

    protected:

    private:
        int map[20][20];
        SDL_Rect src, desr;
        SDL_Texture* floor;

};

#endif // MAP_H

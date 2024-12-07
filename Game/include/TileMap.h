#include "Game.h"

class TileMap
{
    public:
        TileMap();
        virtual ~TileMap();

        void LoadMap();
        void DrawMap();

    protected:

    private:
        SDL_Rect* src, dest;
        SDL_Texture* spriteSheet;
        int map[20][20];

};

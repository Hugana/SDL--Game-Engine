#include "Game.h"
#pragma once
class TileMap
{
    public:
        TileMap();
        virtual ~TileMap();

        void LoadMap(int arr[25][25]);
        void DrawMap();
        bool isWalkable(int x, int y);

    protected:

    private:
        SDL_Rect src, dest;
        SDL_Texture* spriteSheet;
        int currentLvl[25][25];

};

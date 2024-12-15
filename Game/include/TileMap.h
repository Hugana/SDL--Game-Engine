#include "Game.h"
#pragma once
class TileMap
{
    public:
        TileMap();
        virtual ~TileMap();

        void LoadMap(int arr[20][20]);
        void DrawMap();

    protected:

    private:
        SDL_Rect src, dest;
        SDL_Texture* spriteSheet;
        int currentLvl[20][20];

};

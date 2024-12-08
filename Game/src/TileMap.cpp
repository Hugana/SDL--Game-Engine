#include "TileMap.h"
#include "TextureManager.h"

int lvl1[20][20] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

TileMap::TileMap()
{
    //ctor
    spriteSheet = TextureManager::LoadTexture("assets/16x16DungeonTileset.png");

    LoadMap(lvl1);

    src.h = src.w = 16;
    dest.x = dest.y =  0;
    dest.w = src.w * 2;
    dest.h = src.h * 2;

}

TileMap::~TileMap()
{
    //dtor
}

void TileMap::LoadMap(int arr[20][20]) // Correctly qualified as TileMap::LoadMap
{
    for (size_t row = 0; row < 20); row++)
    {
        for (size_t column = 0; column < 20); column++)
        {
            currentLvl[row][column] = arr[row][column];
        }
    }
}

void TileMap::DrawMap(){
    for (size_t row = 0; row < 20; row++)
    {
        for (size_t column = 0; column < 20; column++)
        {
            switch(currentLvl[row][column]){
                case 1:
                    src.x = 0;
                    src.y = 0;
                    TextureManager()::Draw(spriteSheet,src,dest)
                    break;
                case 2:
                    src.x = 0;
                    src.y = 0;
                    TextureManager()::Draw(spriteSheet,src,dest)
                    break;
                case 3:
                    src.x = 0;
                    src.y = 0;
                    TextureManager()::Draw(spriteSheet,src,dest)
                    break;
            }
        }
    }
}

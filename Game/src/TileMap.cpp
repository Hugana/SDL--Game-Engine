#include "TileMap.h"
#include "TextureManager.h"

int lvl1[20][20] =
{
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0},
    {1,0,0,0,0,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0},
    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
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
    for (size_t row = 0; row < 20; row++)
    {
        for (size_t column = 0; column < 20; column++)
        {
            currentLvl[row][column] = arr[row][column];
        }
    }
}

void TileMap::DrawMap(){
    dest.x = dest.y = 0;
    for (size_t row = 0; row < 20; row++)
    {
        for (size_t column = 0; column < 20; column++)
        {
            dest.x = column * (16 * 2);
            dest.y = row * (16 * 2);
            switch(currentLvl[row][column]){
                case 1:
                    //Floor Plain
                    src.x = 32;
                    src.y = 48;
                    TextureManager::Draw(spriteSheet, src, dest);
                    break;
                case 2:
                    //Wall Front
                    src.x = 272;
                    src.y = 16;
                    TextureManager::Draw(spriteSheet, src, dest);
                    break;
                 case 3:
                    //Wall outer n
                    src.x = 272;
                    src.y = 0;
                    TextureManager::Draw(spriteSheet, src, dest);
                    break;
            }
        }
    }
}

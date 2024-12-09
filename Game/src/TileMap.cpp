#include "TileMap.h"
#include "TextureManager.h"

int lvl1[20][20] =
{
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,6,3,3,3,3,3,3,3,3,3,7,0,0,0,0,0},
    {1,0,0,0,4,2,2,2,2,2,2,2,2,2,5,0,0,0,0,0},
    {1,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {1,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {1,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
    {0,0,0,0,4,1,1,1,1,1,1,1,1,1,5,0,0,0,0,0},
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
                    //Floor_plain
                    src.x = 32;
                    src.y = 48;
                    TextureManager::Draw(spriteSheet, src, dest);
                    break;
                case 2:
                    //Wall_front
                    src.x = 272;
                    src.y = 16;
                    TextureManager::Draw(spriteSheet, src, dest);
                    break;
                 case 3:
                    //Wall_outer_n
                    src.x = 272;
                    src.y = 0;
                    TextureManager::Draw(spriteSheet, src, dest);
                    break;
                 case 4:
                     //Wall_outer_w
                     src.x = 256;
                     src.y = 16;
                     TextureManager::Draw(spriteSheet, src, dest);
                     break;
                case 5:
                     //Wall_outer_e
                     src.x = 288;
                     src.y = 16;
                     TextureManager::Draw(spriteSheet, src, dest);
                     break;
                case 6:
                    //Wall_outer_nw
                     src.x = 256;
                     src.y = 0;
                     TextureManager::Draw(spriteSheet, src, dest);
                     break;
                case 7:
                    //Wall_outer_ne
                     src.x = 288;
                     src.y = 0;
                     TextureManager::Draw(spriteSheet, src, dest);
                     break;

            }
        }
    }
}

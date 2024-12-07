#include "TileMap.h"
#include "TextureManager.h"

TileMap::TileMap()
{
    //ctor
    spriteSheet = TextureManager::LoadTexture("assets/16x16DungeonTileset.png");
}

TileMap::~TileMap()
{
    //dtor
}

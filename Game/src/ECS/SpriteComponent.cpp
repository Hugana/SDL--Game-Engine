#include "SpriteComponent.h"
#include "TextureManager.h"
#include "Entity.h"

SpriteComponent::SpriteComponent(const char* tex, int srcX, int srcY, int srcW, int srcH)
{
    texPath = tex;
    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcW;
    srcRect.h = srcH;
}

SpriteComponent::~SpriteComponent()
{
    //dtor
}

void SpriteComponent::init() {
    std::cout << "SpriteComponent initialized.\n";
    positionComp = entity->getComponent<PositionComponent>();
    destRect.x = positionComp->getX();
    destRect.y = positionComp->getY();
    destRect.w = 32;
    destRect.h = 32;
    texture = TextureManager::LoadTexture(texPath);
}

void SpriteComponent::update() {
    std::cout << "Updating SpriteComponent.\n";
}

void SpriteComponent::draw() {
    std::cout << "Drawing SpriteComponent.\n";
    TextureManager::Draw(texture,srcRect,destRect);
}

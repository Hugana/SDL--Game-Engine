#include "AnimatedSprite.h"
#include "TextureManager.h"
#include "Entity.h"

AnimatedSprite::AnimatedSprite(const char* tex, int srcX, int srcY, int srcW, int srcH,int nframes, Uint32 fps_value)
{
    texPath = tex;
    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcW;
    srcRect.h = srcH;
    fps = fps_value;
    frames = nframes;
    frameDelay = 1000 / fps;
    counter = 0;
    lastUpdateTime = 0;
}

AnimatedSprite::~AnimatedSprite()
{
    //dtor
}

void AnimatedSprite::init() {
    //std::cout << "SpriteComponent initialized.\n";
    positionComp = entity->getComponent<PositionComponent>();
    destRect.x = positionComp->getX();
    destRect.y = positionComp->getY();
    destRect.w = 32;
    destRect.h = 32;
    texture = TextureManager::LoadTexture(texPath);
}

void AnimatedSprite::update() {
    //std::cout << "Updating SpriteComponent.\n";
    destRect.x = positionComp->getX();
    destRect.y = positionComp->getY();
}

void AnimatedSprite::draw() {
    Uint32 currentTime = SDL_GetTicks();

    if (currentTime - lastUpdateTime >= frameDelay) {
        // Update animation frame
        if (counter < frames - 1) {
            counter++;
            srcRect.x += srcRect.w;
        } else {
            counter = 0;
            srcRect.x = 0;
        }
        lastUpdateTime = currentTime;
    }

    TextureManager::Draw(texture, srcRect, destRect);
}

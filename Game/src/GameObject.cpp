#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y, int srcX, int srcY, int srcW, int srcH) {
    objTexture = TextureManager::LoadTexture(textureSheet);
    xpos = x;
    ypos = y;
    SetSourceRect(srcX, srcY, srcW, srcH);
}

GameObject::~GameObject() {
    // Destructor logic
}

void GameObject::SetSourceRect(int x, int y, int w, int h) {
    srcRect.x = x;
    srcRect.y = y;
    srcRect.w = w;
    srcRect.h = h;
}

void GameObject::Update() {
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);  // Render the texture
}

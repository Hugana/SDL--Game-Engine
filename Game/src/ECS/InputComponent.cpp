#include "InputComponent.h"
#include <Entity.h>

InputComponent::InputComponent()
{
    // Constructor
}

InputComponent::~InputComponent()
{
    // Destructor
}

void InputComponent::init()
{
    positionComp = entity->getComponent<PositionComponent>();
    posVector = positionComp->getPos();
}

void InputComponent::update()
{
    posVector = positionComp->getPos();
}

void InputComponent::handleMovement(SDL_Event& event, TileMap* tilemap)
{
     if (event.type == SDL_KEYDOWN) {

         switch (event.key.keysym.sym) {
             case SDLK_UP:
                 posVector + Vector2D(0,32);
                 break;
            case SDLK_DOWN:
                posVector + Vector2D(0,-32);
                break;
            case SDLK_LEFT:
                posVector + Vector2D(-32,0);
                break;
            case SDLK_RIGHT:
                posVector + Vector2D(32,0);
                break;
        }
     }


}



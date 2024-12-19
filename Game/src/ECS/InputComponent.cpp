#include "InputComponent.h"
#include <Entity.h>
#include <TileMap.h>

InputComponent::InputComponent(TileMap* level)
{
    // Constructor
    tileMap = level;
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

bool InputComponent::isMoveValid(int newX, int newY)
{

    int tileX = newX / 32;
    int tileY = newY / 32;

    return tileMap->isWalkable(tileX, tileY);
}

void InputComponent::update()
{
    if (!positionComp) return;


    const Uint8* keyState = SDL_GetKeyboardState(nullptr);



    if (canMove) {
        int newX = posVector.getX();
        int newY = posVector.getY();

        if (keyState[SDL_SCANCODE_UP]) {
            newY -= 32; // Move up
        } else if (keyState[SDL_SCANCODE_DOWN]) {
            newY += 32; // Move down
        } else if (keyState[SDL_SCANCODE_LEFT]) {
            newX -= 32; // Move left
        } else if (keyState[SDL_SCANCODE_RIGHT]) {
            newX += 32; // Move right;
        }


        if (isMoveValid(newX, newY)) {
            positionComp->setPos(newX, newY);
            canMove = false;
        }
    }

    if (!keyState[SDL_SCANCODE_UP] && !keyState[SDL_SCANCODE_DOWN] &&
        !keyState[SDL_SCANCODE_LEFT] && !keyState[SDL_SCANCODE_RIGHT]) {
        canMove = true;
    }
}




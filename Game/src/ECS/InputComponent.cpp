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
    if (!positionComp) return;


    const Uint8* keyState = SDL_GetKeyboardState(nullptr);

    if (canMove) {
        if (keyState[SDL_SCANCODE_UP]) {
            positionComp->setY(positionComp->getY() - 32);
            canMove = false;
        }
        else if (keyState[SDL_SCANCODE_DOWN]) {
            positionComp->setY(positionComp->getY() + 32);
            canMove = false;
        }
        else if (keyState[SDL_SCANCODE_LEFT]) {
            positionComp->setX(positionComp->getX() - 32);
            canMove = false;
        }
        else if (keyState[SDL_SCANCODE_RIGHT]) {
            positionComp->setX(positionComp->getX() + 32);
            canMove = false;
        }
    }

    if (!keyState[SDL_SCANCODE_UP] && !keyState[SDL_SCANCODE_DOWN] &&
        !keyState[SDL_SCANCODE_LEFT] && !keyState[SDL_SCANCODE_RIGHT]) {
        canMove = true;
    }
}




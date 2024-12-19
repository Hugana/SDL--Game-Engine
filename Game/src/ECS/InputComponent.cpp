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

// Function to handle movement
void InputComponent::handleMovement(PositionComponent* positionComp, bool& canMove) {
    if (!positionComp) return;

    const Uint8* keyState = SDL_GetKeyboardState(nullptr);
    Vector2D currentPosition = positionComp->getPos();

    if (canMove) {
        int newX = currentPosition.getX();
        int newY = currentPosition.getY();

        if (keyState[SDL_SCANCODE_UP]) {
            newY -= 32;
            canMove = false;
        } else if (keyState[SDL_SCANCODE_DOWN]) {
            newY += 32;
            canMove = false;
        } else if (keyState[SDL_SCANCODE_LEFT]) {
            newX -= 32;
            canMove = false;
        } else if (keyState[SDL_SCANCODE_RIGHT]) {
            newX += 32;
            canMove = false;
        }

        if (!canMove && isMoveValid(newX, newY)) {
            positionComp->setPos(newX, newY);
        }
    }

    if (!keyState[SDL_SCANCODE_UP] && !keyState[SDL_SCANCODE_DOWN] &&
        !keyState[SDL_SCANCODE_LEFT] && !keyState[SDL_SCANCODE_RIGHT]) {
        canMove = true;
    }
}

// Update function
void InputComponent::update() {
    if (!positionComp) return;

    handleMovement(positionComp, canMove);
}

#include "PositionComponent.h"

PositionComponent::PositionComponent(int x, int y)
{
    posx = x;
    posy = y;
}

PositionComponent::~PositionComponent()
{
    // Destructor
}

int PositionComponent::getX(){
    return posx;
}

int PositionComponent::getY(){
    return posy;
}

void PositionComponent::setPos(int x, int y)
{
    posx = x;
    posy = y;
}

void PositionComponent::setX(int x)
{
    posx = x;
}

void PositionComponent::setY(int y)
{
    posy = y;
}

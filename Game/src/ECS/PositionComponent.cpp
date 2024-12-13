#include "PositionComponent.h"
#include "Vector2D.h"

PositionComponent::PositionComponent(Vector2D v)
{
    posVector = v;
}

PositionComponent::~PositionComponent()
{
    // Destructor
}

int PositionComponent::getX() const
{
    return posVector.getX();
}

int PositionComponent::getY() const
{
    return posVector.getY();
}

void PositionComponent::setPos(int x, int y) {
    posVector.setX(x);
    posVector.setY(y);
}

Vector2D PositionComponent::getPos()
{
    return posVector;
}

void PositionComponent::setX(int x)
{
    posVector.setX(x);
}

void PositionComponent::setY(int y)
{
    posVector.setY(y);
}

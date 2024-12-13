#include "Component.h"
#include "Vector2D.h"
#pragma once

class PositionComponent : public Component
{
    public:
        PositionComponent(Vector2D v);
        virtual ~PositionComponent();

        int getX() const;
        int getY() const;

        void setPos(int x,int y);
        Vector2D getPos();
        void setX(int x);
        void setY(int y);

    private:
        Vector2D posVector;
};

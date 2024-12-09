#include "Component.h"
#pragma once

class PositionComponent : public Component
{
    public:
        PositionComponent(int x, int y);
        virtual ~PositionComponent();

        int getX();
        int getY();

        void setPos(int x,int y);
        void setX(int x);
        void setY(int y);

    private:
        int posx, posy;
};

#pragma once
#include <Component.h>
#include <PositionComponent.h>
#include <Vector2D.h>
#include <TileMap.h>

class InputComponent : public Component
{
public:
    InputComponent(TileMap* tilemap);
    virtual ~InputComponent();
    bool isMoveValid(int x, int y);

    void init() override;
    void update() override;

private:
    TileMap* tileMap;
    bool canMove;
    PositionComponent* positionComp;
    Vector2D posVector;

    void handleMovement(PositionComponent* positionComp, bool& canMove);
};

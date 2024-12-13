#pragma once
#include <Component.h>
#include <PositionComponent.h>
#include <Vector2D.h>
#include <TileMap.h>

class InputComponent : public Component
{
public:
    InputComponent();
    virtual ~InputComponent();

    void init() override;
    void update() override;

    void handleMovement(SDL_Event& event, TileMap* tileMap);

private:
    PositionComponent* positionComp;
    Vector2D posVector;
};

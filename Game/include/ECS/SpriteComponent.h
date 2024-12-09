#include <iostream>
#include "Component.h"
#include "PositionComponent.h"
#include <SDL2/SDL_image.h>

class SpriteComponent : public Component {
    private:
        PositionComponent* positionComp;
        SDL_Texture* texture = nullptr;
        SDL_Rect srcRect, destRect;
        const char* texPath;
    public:
        SpriteComponent(const char* tex, int srcX, int srcY, int srcW, int srcH);
        virtual ~SpriteComponent();

        void init() override;
        void update() override;
        void draw() override;
};

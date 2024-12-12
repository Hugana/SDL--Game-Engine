#include <SDL2/SDL_image.h>
#include <Component.h>
#include <PositionComponent.h>
#include <Vector2D.h>

#pragma once

class TextComponent : public Component
{
    public:
        TextComponent(const char* font_path, int r_value, int g_value, int b_value, int pSize);
        virtual ~TextComponent();

        void init() override;
        void update() override;
        void draw() override;

    private:
        PositionComponent* positionComp;
        int r,g,b,font_size;
        char* filename;
        SDL_Texture* texture;
};



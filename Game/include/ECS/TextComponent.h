#include <SDL2/SDL_image.h>
#include <Component.h>
#include <PositionComponent.h>
#include <Vector2D.h>

#pragma once

class TextComponent : public Component
{
    public:
        TextComponent(const char* font_path, int r_value, int g_value, int b_value, int a, int pSize, const char* text);
        virtual ~TextComponent();

        void init() override;
        void update() override;
        void draw() override;

    private:
        PositionComponent* positionComp;
        int r,g,b,a,font_size;
        const char* filename;
        SDL_Texture* texture;
        SDL_Rect destRect;
        const char* text;
};



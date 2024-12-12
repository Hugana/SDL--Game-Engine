#include "TextComponent.h"
#include <SDL2/SDL_image.h>
#include <PositionComponent.h>
#include "Entity.h"


TextComponent::TextComponent(const char* font_path, int r_value, int g_value, int b_value, int pSize)
{

    font_size = pSize;
    filename = font_path;
    r = r_value;
    g = g_value;
    b = b_value;

}

TextComponent::~TextComponent()
{
    //dtor
}

void TextComponent::init()
{
     positionComp = entity->getComponent<PositionComponent>();

}

void TextComponent::update()
{

}

void TextComponent::draw()
{

}

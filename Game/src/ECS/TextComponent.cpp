#include "TextComponent.h"
#include <SDL2/SDL_image.h>
#include <PositionComponent.h>
#include "Entity.h"
#include "TextureManager.h"


TextComponent::TextComponent(const char* font_path, int r_value, int g_value, int b_value, int a_value, int pSize, const char* text_value)
{

    font_size = pSize;
    filename = font_path;
    r = r_value;
    g = g_value;
    b = b_value;
    a = a_value;
    text = text_value;


}

TextComponent::~TextComponent()
{
    //dtor
}

void TextComponent::init()
{
     positionComp = entity->getComponent<PositionComponent>();
     texture = TextureManager::LoadFontTexture(filename,font_size,r,g,b,a,text);

}

void TextComponent::update()
{
    destRect.x = positionComp->getX();
    destRect.y = positionComp->getY();
}

void TextComponent::draw() {
    if (texture) {
        int texWidth, texHeight;
        SDL_QueryTexture(texture, NULL, NULL, &texWidth, &texHeight);
        destRect.x = positionComp->getX();
        destRect.y = positionComp->getY();
        destRect.w = texWidth;
        destRect.h = texHeight;
        TextureManager::Draw(texture, SDL_Rect{0, 0, texWidth, texHeight}, destRect);
    }
}


#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <Component.h>
#include <PositionComponent.h>
#include <SDL2/SDL_image.h>


class AnimatedSprite : public Component
{
    public:
        AnimatedSprite(const char* tex, int srcX, int srcY, int srcW, int srcH,int nframes, Uint32 fps);
        virtual ~AnimatedSprite();

        void init() override;
        void update() override;
        void draw() override;

    protected:

    private:
        PositionComponent* positionComp;
        SDL_Texture* texture = nullptr;
        SDL_Rect srcRect, destRect;
        const char* texPath;
        int frames, counter;
        Uint32 frameStart, frameDelay, frameTime, fps,lastUpdateTime;
};

#endif // ANIMATEDSPRITE_H

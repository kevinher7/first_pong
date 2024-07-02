#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"
#include <SDL3_image/SDL_image.h>

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *texturePath);
    static void Draw(SDL_Texture *drawTexture, SDL_FRect srcRect, SDL_FRect destRect);
};

#endif

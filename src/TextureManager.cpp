#include "TextureManager.h"
#include "Game.h"

SDL_Texture *TextureManager::LoadTexture(const char *texturePath)
{
    SDL_Surface *tmpSurface{IMG_Load(texturePath)};
    SDL_Texture *newTexture = SDL_CreateTextureFromSurface(Game::gameRenderer, tmpSurface);
    SDL_DestroySurface(tmpSurface);

    return newTexture;
}

void TextureManager::Draw(SDL_Texture *drawTexture, SDL_FRect srcRect, SDL_FRect destRect)
{
    SDL_RenderTexture(Game::gameRenderer, drawTexture, &srcRect, &destRect);
}

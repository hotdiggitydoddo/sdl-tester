//
// Created by Ryan Dodd on 5/24/18.
//

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *fileName)
{
    SDL_Surface *tmpSurface = IMG_Load(fileName);

    if (tmpSurface == nullptr)
    {
        std::cout << "SDL could not load image!  SDL Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

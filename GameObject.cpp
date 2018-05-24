//
// Created by Ryan Dodd on 5/24/18.
//

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* spriteSheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(spriteSheet);
    xPos = x;
    yPos = y;
}

GameObject::~GameObject()
{
    objTexture = nullptr;
}

void GameObject::Update(const float deltaTime)
{
    xPos += 100 * deltaTime;
    yPos += 100 * deltaTime;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

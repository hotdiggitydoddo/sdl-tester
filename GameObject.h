//
// Created by Ryan Dodd on 5/24/18.
//

#ifndef SDL_TESTER_GAMEOBJECT_H
#define SDL_TESTER_GAMEOBJECT_H

#include "Game.h"

class GameObject {
public:
    GameObject(const char* spriteSheet, int x, int y);
    ~GameObject();

    void Update(const float deltaTime);
    void Render();

private:
    int xPos;
    int yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};


#endif //SDL_TESTER_GAMEOBJECT_H

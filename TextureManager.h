//
// Created by Ryan Dodd on 5/24/18.
//

#ifndef SDL_TESTER_TEXTUREMANAGER_H
#define SDL_TESTER_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
};


#endif //SDL_TESTER_TEXTUREMANAGER_H

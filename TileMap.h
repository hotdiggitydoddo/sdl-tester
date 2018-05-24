//
// Created by Ryan Dodd on 5/24/18.
//

#ifndef SDL_TESTER_TILEMAP_H
#define SDL_TESTER_TILEMAP_H

#include "Game.h"

class TileMap
{
public:
    TileMap();
    ~TileMap();

    void Load(int arr[20][25]);
    void Draw();

private:
    SDL_Rect srcRect, destRect;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    int map[20][25];
};

#endif //SDL_TESTER_TILEMAP_H

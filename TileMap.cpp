//
// Created by Ryan Dodd on 5/24/18.
//

#include "TileMap.h"
#include "TextureManager.h"

int lvl1[20][25] =
{
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,1,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

TileMap::TileMap()
{
    //dirt = TextureManager::LoadTexture("assets/dirt.png");
    //water = TextureManager::LoadTexture("assets/water.png");
    //grass = TextureManager::LoadTexture("assets/grass.png");

    Load(lvl1);

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = 32;
    srcRect.h = destRect.h = 32;

    destRect.x = destRect.y  = 0;
}

TileMap::~TileMap()
{

}

void TileMap::Load(int arr[20][25])
{
    for (int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 25; y++)
        {
            map[x][y] = arr[x][y];
        }
    }
}

void TileMap::Draw()
{
    for (int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 25; y++)
        {
            destRect.x = x * 32;
            destRect.y = y * 32;

            switch (map[y][x])
            {
                case 0:
                    SDL_SetRenderDrawColor(Game::renderer, 87, 180, 242, 255);
                    SDL_RenderFillRect(Game::renderer, &destRect);
                    //TextureManager::Draw(water, srcRect, destRect);
                break;

                case 1:
                    SDL_SetRenderDrawColor(Game::renderer, 4, 119, 58, 255);
                    SDL_RenderFillRect(Game::renderer, &destRect);
                    //TextureManager::Draw(grass, srcRect, destRect);
                    break;

                case 2:
                    SDL_SetRenderDrawColor(Game::renderer, 109, 74, 41, 255);
                    SDL_RenderFillRect(Game::renderer, &destRect);
                    //TextureManager::Draw(dirt, srcRect, destRect);
                    break;
                default: {}
            }
        }
    }
}

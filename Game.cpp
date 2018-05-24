//
// Created by Ryan Dodd on 5/24/18.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"

TileMap* map;
GameObject* player;


SDL_Renderer* Game::renderer = nullptr;

Game::Game() {}
Game::~Game() {}

bool Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Could not initialize SDL2: " << SDL_GetError() << std::endl;
        return false;
    }

    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if (window == NULL) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    screenWidth = width;
    screenHeight = height;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return false;
    }

    map = new TileMap();
    player = new GameObject("assets/ball.png", 10, 10);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    isRunning = true;
    return true;
}

void Game::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default: {}
    }
}

void Game::Update(float deltaTime)
{
    player->Update(deltaTime);
}

void Game::Render()
{
    SDL_RenderClear(renderer);

    //rendering here
    map->Draw();
    player->Render();

    SDL_RenderPresent(renderer);
}

void Game::Clean()
{
    delete player;
    delete map;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


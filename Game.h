//
// Created by Ryan Dodd on 5/24/18.
//

#ifndef SDL_TESTER_GAME_H
#define SDL_TESTER_GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <chrono>
#include <atomic>

class Game
{
public:
    Game();
    ~Game();

    bool Init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update(float deltaTime);
    void Render();
    void Clean();
    bool IsRunning() { return isRunning; }

    int ScreenWidth() { return screenWidth; }
    int ScreenHeight() { return screenHeight; }

    static SDL_Renderer *renderer;

private:
    bool isRunning;
    int screenWidth, screenHeight;
    SDL_Window *window;
};



#endif //SDL_TESTER_GAME_H

#include "Game.h"

int main(int argc, const char * argv[])
{
    float deltaTime = 0;
    Game game;

    if (!game.Init("SDL Test!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false))
        return EXIT_FAILURE;

    auto tp1 = std::chrono::system_clock::now();
    auto tp2 = std::chrono::system_clock::now();

    while (game.IsRunning())
    {
        tp2 = std::chrono::system_clock::now();
        std::chrono::duration<float> eTime = tp2 - tp1;
        tp1 = tp2;
        deltaTime = eTime.count();

        game.HandleEvents();
        game.Update(deltaTime);
        game.Render();
    }

    game.Clean();
    return EXIT_SUCCESS;
}

#include "Game.h"

#include <SDL3/SDL.h>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    constexpr int FPS{60};
    constexpr int frameDelay{1000 / FPS};

    Uint64 frameStart;
    Uint64 frameTime;

    Game game;

    game.initGame("First Pong", 720, 480);

    while (game.running())
    {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(static_cast<Uint32>(frameDelay - frameTime));
        }
    }

    game.clean();
}

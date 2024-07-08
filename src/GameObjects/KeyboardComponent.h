#include "Paddle.h"
#include "../Game.h"

#include <iostream>

class KeyboardComponent
{
public:
    KeyboardComponent() = delete;
    KeyboardComponent(Paddle &playerPaddle, SDL_Keycode up, SDL_Keycode down) : paddleObject{playerPaddle}, upKey{up}, downKey{down} {}
    KeyboardComponent(const KeyboardComponent &) = delete;
    KeyboardComponent &operator=(const KeyboardComponent &) = delete;
    KeyboardComponent(KeyboardComponent &&) = delete;
    KeyboardComponent &operator=(const KeyboardComponent &&) = delete;
    ~KeyboardComponent() = default;

    void update()
    {
        if (Game::event.type == SDL_EVENT_KEY_DOWN)
        {
            if (Game::event.key.keysym.sym == upKey && paddleObject.destRect.y > 0)
            {
                std::cout << "preseed up\n";

                paddleObject.paddleVelocity.ycomponent = -1;
            }
            else if (Game::event.key.keysym.sym == downKey && paddleObject.destRect.y < 480 - paddleObject.destRect.h)
            {
                std::cout << "preseed down\n";

                paddleObject.paddleVelocity.ycomponent = 1;
            }
        }

        if (Game::event.type == SDL_EVENT_KEY_UP)
        {
            if (Game::event.key.keysym.sym == upKey)
            {
                paddleObject.paddleVelocity.ycomponent = 0;
            }
            else if (Game::event.key.keysym.sym == downKey)
            {
                paddleObject.paddleVelocity.ycomponent = 0;
            }
        }
    }

    Paddle &paddleObject;
    SDL_Keycode upKey;
    SDL_Keycode downKey;
};

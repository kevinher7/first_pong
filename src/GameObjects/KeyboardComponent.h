#include "Paddle.h"
#include "../Game.h"

class KeyboardComponent
{
public:
    KeyboardComponent() = delete;
    KeyboardComponent(Paddle &playerOne, Paddle &playerTwo) : paddleObjectOne{playerOne}, paddleObjectTwo{playerTwo} {}
    KeyboardComponent(const KeyboardComponent &) = delete;
    KeyboardComponent &operator=(const KeyboardComponent &) = delete;
    KeyboardComponent(KeyboardComponent &&) = delete;
    KeyboardComponent &operator=(const KeyboardComponent &&) = delete;
    ~KeyboardComponent() = default;

    void update()
    {
        if (Game::event.type == SDL_EVENT_KEY_DOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
            // Player one controls
            case SDLK_w:
                paddleObjectOne.paddleVelocity.ycomponent = -1;
                break;
            case SDLK_s:
                paddleObjectOne.paddleVelocity.ycomponent = 1;
                break;

            // Player two controls
            case SDLK_UP:
                paddleObjectTwo.paddleVelocity.ycomponent = -1;
                break;
            case SDLK_DOWN:
                paddleObjectTwo.paddleVelocity.ycomponent = 1;
                break;

            default:
                break;
            }
        }

        if (Game::event.type == SDL_EVENT_KEY_UP)
        {
            switch (Game::event.key.keysym.sym)
            {
            // Player one controls
            case SDLK_w:
                paddleObjectOne.paddleVelocity.ycomponent = 0;
                break;
            case SDLK_s:
                paddleObjectOne.paddleVelocity.ycomponent = 0;
                break;

            // Player two controls
            case SDLK_UP:
                paddleObjectTwo.paddleVelocity.ycomponent = 0;
                break;
            case SDLK_DOWN:
                paddleObjectTwo.paddleVelocity.ycomponent = 0;
                break;

            default:
                break;
            }
        }
    }

    Paddle &paddleObjectOne;
    Paddle &paddleObjectTwo;
};

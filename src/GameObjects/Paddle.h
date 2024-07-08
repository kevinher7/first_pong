#ifndef PADDLE_H
#define PADDLE_H

#include "../Vector2D.h"
#include <SDL3_image/SDL_image.h>

class Paddle
{
public:
    Paddle()
        : paddleYPosition{0.0f}, paddleXPosition{0.0f}, paddleVelocity{0.0f, 0.0f}, srcRect{0, 0, 16, 32}, destRect{paddleXPosition, paddleYPosition, 16, 80}, m_paddleTexture{nullptr}, m_paddleSpeed{5} {};
    Paddle(const Paddle &) noexcept
        : paddleYPosition{0.0f}, paddleXPosition{0.0f}, paddleVelocity{0.0f, 0.0f}, srcRect{0, 0, 16, 32}, destRect{paddleXPosition, paddleYPosition, 16, 80}, m_paddleTexture{nullptr}, m_paddleSpeed{5} {}
    Paddle &operator=(const Paddle &) noexcept = delete;
    Paddle(Paddle &&) noexcept
        : paddleYPosition{0.0f}, paddleXPosition{0.0f}, paddleVelocity{0.0f, 0.0f}, srcRect{0, 0, 16, 32}, destRect{paddleXPosition, paddleYPosition, 16, 80}, m_paddleTexture{nullptr}, m_paddleSpeed{5} {}
    Paddle &operator=(Paddle &&) = delete;
    ~Paddle() {}

    void init(const char *spritePath, int playerNumber, int windowWidth, int windowHeight);
    void update();
    void draw();

    float paddleYPosition;
    float paddleXPosition;
    Vector2D paddleVelocity;

    SDL_FRect srcRect, destRect;

private:
    SDL_Texture *m_paddleTexture;
    float m_paddleSpeed;
};

#endif

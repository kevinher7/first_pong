#ifndef PADDLE_H
#define PADDLE_H

#include "../Vector2D.h"
#include <SDL3_image/SDL_image.h>

class Paddle
{
public:
    Paddle()
        : paddleYPosition{0.0f}, paddleXPosition{0.0f}, paddleVelocity{0.0f, 0.0f}, m_paddleTexture{nullptr}, m_paddleSpeed{3}, m_srcRect{0, 0, 16, 32}, m_destRect{paddleXPosition, paddleYPosition, 16, 80} {};
    Paddle(const Paddle &) noexcept
        : paddleYPosition{0.0f}, paddleXPosition{0.0f}, paddleVelocity{0.0f, 0.0f}, m_paddleTexture{nullptr}, m_paddleSpeed{3}, m_srcRect{0, 0, 16, 32}, m_destRect{paddleXPosition, paddleYPosition, 16, 80} {}
    Paddle &operator=(const Paddle &) noexcept = delete;
    Paddle(Paddle &&) noexcept
        : paddleYPosition{0.0f}, paddleXPosition{0.0f}, paddleVelocity{0.0f, 0.0f}, m_paddleTexture{nullptr}, m_paddleSpeed{3}, m_srcRect{0, 0, 16, 32}, m_destRect{paddleXPosition, paddleYPosition, 16, 80} {}
    Paddle &operator=(Paddle &&) = delete;
    ~Paddle() {}

    void init(const char *spritePath, int playerNumber, int windowWidth, int windowHeight);
    void update();
    void draw();

    float paddleYPosition;
    float paddleXPosition;
    Vector2D paddleVelocity;

private:
    SDL_Texture *m_paddleTexture;
    float m_paddleSpeed;
    SDL_FRect m_srcRect, m_destRect;
};

#endif

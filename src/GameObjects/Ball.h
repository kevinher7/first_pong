#ifndef BALL_H
#define BALL_H

#include "../Vector2D.h"
#include <SDL3_image/SDL_image.h>

class Ball
{
public:
    Ball() : m_ballTexture{nullptr}, m_ballPosition{0.0f, 0.0f}, m_ballVelocity{1.0f, 0.0f}, m_ballSpeed{3}, m_srcRect{0, 0, 32, 32}, m_destRect{m_ballPosition.xcomponent, m_ballPosition.ycomponent, 16, 16} {}
    Ball(const Ball &) noexcept : m_ballTexture{nullptr}, m_ballPosition{0.0f, 0.0f}, m_ballVelocity{0.0f, 0.0f}, m_ballSpeed{3}, m_srcRect{0, 0, 32, 32}, m_destRect{m_ballPosition.xcomponent, m_ballPosition.ycomponent, 16, 16} {}
    Ball &operator=(const Ball &) noexcept = delete;
    Ball(Ball &&) noexcept : m_ballTexture{nullptr}, m_ballPosition{0.0f, 0.0f}, m_ballVelocity{0.0f, 0.0f}, m_ballSpeed{3}, m_srcRect{0, 0, 32, 32}, m_destRect{m_ballPosition.xcomponent, m_ballPosition.ycomponent, 16, 16} {}
    Ball &operator=(Ball &&) = delete;
    ~Ball() {}

    void init(const char *spritePath, int windowWidth, int windowHeight);

    void update();
    void draw();

private:
    SDL_Texture *m_ballTexture;
    Vector2D m_ballPosition;
    Vector2D m_ballVelocity;
    float m_ballSpeed;
    SDL_FRect m_srcRect, m_destRect;
};

#endif

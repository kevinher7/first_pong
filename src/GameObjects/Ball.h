#ifndef BALL_H
#define BALL_H

#include "../Vector2D.h"
#include <SDL3_image/SDL_image.h>

class Ball
{
public:
    Ball() : srcRect{0, 0, 32, 32}, destRect{0.0f, 0.0f, 16, 16}, m_ballTexture{nullptr}, m_ballPosition{0.0f, 0.0f}, m_ballVelocity{1.0f, 0.0f}, m_ballSpeed{3} {}
    Ball(const Ball &) noexcept : srcRect{0, 0, 32, 32}, destRect{0.0f, 0.0f, 16, 16}, m_ballTexture{nullptr}, m_ballPosition{0.0f, 0.0f}, m_ballVelocity{0.0f, 0.0f}, m_ballSpeed{3} {}
    Ball &operator=(const Ball &) noexcept = delete;
    Ball(Ball &&) noexcept : srcRect{0, 0, 32, 32}, destRect{0.0f, 0.0f, 16, 16}, m_ballTexture{nullptr}, m_ballPosition{0.0f, 0.0f}, m_ballVelocity{0.0f, 0.0f}, m_ballSpeed{3} {}
    Ball &operator=(Ball &&) = delete;
    ~Ball() {}

    void init(const char *spritePath, int windowWidth, int windowHeight);
    void changeVelocity(Vector2D &paddleVelocity);
    void wallBounceVelocityChange();

    void update();
    void draw();

    SDL_FRect srcRect, destRect;

private:
    SDL_Texture *m_ballTexture;
    Vector2D m_ballPosition;
    Vector2D m_ballVelocity;
    float m_ballSpeed;
};

#endif

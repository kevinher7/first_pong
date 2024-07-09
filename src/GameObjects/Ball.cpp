#include "Ball.h"
#include "../TextureManager.h"

#include <iostream>
#include <cstdlib>

void Ball::init(const char *spritePath, int windowWidth, int windowHeight)
{
    m_ballTexture = TextureManager::LoadTexture(spritePath);

    m_ballPosition.xcomponent = static_cast<float>(windowWidth / 2 - 8);
    m_ballPosition.ycomponent = static_cast<float>(windowHeight / 2 - 8);

    // m_ballVelocity.xcomponent = (static_cast<float>((rand() % 5)) + 2.0f) / 10.0f;
    // m_ballVelocity.ycomponent = 1.0f - m_ballVelocity.xcomponent;
}

void Ball::update()
{
    m_ballPosition.xcomponent += m_ballVelocity.xcomponent * m_ballSpeed;
    m_ballPosition.ycomponent += m_ballVelocity.ycomponent * m_ballSpeed;

    destRect.x = m_ballPosition.xcomponent;
    destRect.y = m_ballPosition.ycomponent;
}

void Ball::handleWallBounce()
{
    m_ballVelocity.ycomponent *= -1;
}

void Ball::handleBounce(SDL_FRect collisioningRec, Vector2D &paddleVelocity)
{
    float hitboxHeight = collisioningRec.h / 3;
    float currentHit = destRect.y - collisioningRec.y;

    if (m_ballVelocity.ycomponent > 0)
    {
        if (currentHit < hitboxHeight)
        {
            m_ballVelocity.xcomponent *= -1.0f;
            m_ballVelocity.ycomponent *= -1.0f;
            m_ballSpeed *= m_speedMultiplier;
        }
        else if (currentHit < 2 * hitboxHeight)
        {
            m_ballVelocity.xcomponent *= -1;
        }
        else if (currentHit < 3 * hitboxHeight)
        {
            m_ballVelocity.xcomponent *= -1.0f;
            m_ballSpeed *= m_speedMultiplier;
        }
    }
    else
    {
        if (currentHit < hitboxHeight)
        {
            m_ballVelocity.xcomponent *= -1.0f;
            m_ballSpeed *= m_speedMultiplier;
        }
        else if (currentHit < 2 * hitboxHeight)
        {
            m_ballVelocity.xcomponent *= -1;
        }
        else if (currentHit < 3 * hitboxHeight)
        {
            m_ballVelocity.xcomponent *= -1.0f;
            m_ballVelocity.ycomponent *= -1.0f;
            m_ballSpeed *= m_speedMultiplier;
        }
    }

    m_ballVelocity.ycomponent += paddleVelocity.ycomponent;
}

void Ball::draw()
{
    TextureManager::Draw(m_ballTexture, srcRect, destRect);
}

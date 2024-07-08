#include "Ball.h"
#include "../TextureManager.h"

void Ball::init(const char *spritePath, int windowWidth, int windowHeight)
{
    m_ballTexture = TextureManager::LoadTexture(spritePath);

    m_ballPosition.xcomponent = static_cast<float>(windowWidth / 2 - 8);
    m_ballPosition.ycomponent = static_cast<float>(windowHeight / 2 - 8);
}

void Ball::update()
{
    m_ballPosition.xcomponent += m_ballVelocity.xcomponent * m_ballSpeed;
    m_ballPosition.xcomponent += m_ballVelocity.ycomponent * m_ballSpeed;

    destRect.x = m_ballPosition.xcomponent;
    destRect.y = m_ballPosition.ycomponent;
}

void Ball::changeVelocity()
{
    m_ballVelocity * -1;
}

void Ball::draw()
{
    TextureManager::Draw(m_ballTexture, srcRect, destRect);
}

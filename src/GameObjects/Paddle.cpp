#include "Paddle.h"
#include "../TextureManager.h"

void Paddle::init(const char *spritePath, int playerNumber, int windowWidth, int windowHeight)
{
    m_paddleTexture = TextureManager::LoadTexture(spritePath);
    paddleYPosition = static_cast<float>(windowHeight / 2 - 40);

    if (playerNumber == 1)
    {
        paddleXPosition = 0.0f;
    }
    else
    {
        paddleXPosition = static_cast<float>(windowWidth - 16);
    }

    m_destRect.x = paddleXPosition;
    m_destRect.y = paddleYPosition;
}

void Paddle::update()
{
    paddleYPosition += paddleVelocity.ycomponent * m_paddleSpeed;

    m_destRect.y = paddleYPosition;
}

void Paddle::draw()
{
    TextureManager::Draw(m_paddleTexture, m_srcRect, m_destRect);
}

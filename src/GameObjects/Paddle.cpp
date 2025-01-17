#include "Paddle.h"
#include "../TextureManager.h"
#include "../Collision.h"

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

    destRect.x = paddleXPosition;
    destRect.y = paddleYPosition;
}

void Paddle::update()
{
    if (paddleYPosition <= 0)
    {
        paddleYPosition = 0;
    }

    if (paddleYPosition >= 480 - destRect.h)
    {
        paddleYPosition = 480 - destRect.h;
    }

    paddleYPosition += paddleVelocity.ycomponent * m_paddleSpeed;
    destRect.y = paddleYPosition;
}

void Paddle::draw()
{
    TextureManager::Draw(m_paddleTexture, srcRect, destRect);
}

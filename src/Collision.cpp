#include "Collision.h"

bool Collision::AABB(const SDL_FRect &recA, const SDL_FRect &recB)
{
    if (
        recA.x + recA.w >= recB.x &&
        recB.x + recB.w >= recA.x &&
        recA.y + recA.h >= recB.y &&
        recB.y + recB.h >= recA.y)
    {
        return true;
    }

    return false;
}

bool Collision::windowTBCollision(const SDL_FRect &recObject)
{
    if (recObject.y <= 0 || recObject.y >= 480 - recObject.h)
    {
        return true;
    }

    return false;
}

int Collision::goalCollision(const SDL_FRect &recObject)
{
    if (recObject.x <= 0)
    {
        return 1;
    }
    if (recObject.x >= (720.0f - recObject.w))
    {
        return 2;
    }

    return 0;
}

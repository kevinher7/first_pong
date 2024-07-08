#include "Vector2D.h"

Vector2D &Vector2D::Add(const Vector2D vector)
{
    this->xcomponent += vector.xcomponent;
    this->ycomponent += vector.ycomponent;

    return *this;
}
Vector2D &Vector2D::Subtract(const Vector2D vector)
{
    this->xcomponent -= vector.xcomponent;
    this->ycomponent -= vector.ycomponent;

    return *this;
}
Vector2D &Vector2D::Multiply(const Vector2D vector)
{
    this->xcomponent *= vector.xcomponent;
    this->ycomponent *= vector.ycomponent;

    return *this;
}
Vector2D &Vector2D::Divide(const Vector2D vector)
{
    this->xcomponent /= vector.xcomponent;
    this->ycomponent /= vector.ycomponent;

    return *this;
}

Vector2D Vector2D::operator*(const int &i)
{
    this->xcomponent *= static_cast<float>(i);
    this->ycomponent *= static_cast<float>(i);

    return *this;
}

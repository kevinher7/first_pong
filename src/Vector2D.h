#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    Vector2D() : xcomponent{0.0f}, ycomponent{0.0f} {}
    Vector2D(float x, float y) : xcomponent{x}, ycomponent{y} {}

    Vector2D &Add(const Vector2D vector);
    Vector2D &Subtract(const Vector2D vector);
    Vector2D &Multiply(const Vector2D vector);
    Vector2D &Divide(const Vector2D vector);

    Vector2D operator*(const float &i);

    float xcomponent;
    float ycomponent;
};

#endif

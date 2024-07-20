#include "include/vector2.h"


Vector2::Vector2(float x, float y) : x(x), y(y) {}

void Vector2::operator=(const Vector2& other)
{
    x = other.x;
    y = other.y;
}

Vector2 Vector2::operator+(const Vector2& other)
{
    return Vector2((x + other.x), (y + other.y));
}

Vector2 Vector2::operator-(const Vector2& other)
{
    return Vector2((x - other.x), (y - other.y));
}

Vector2 Vector2::operator*(const float other)
{
    return Vector2((x * other), (y * other));
}

Vector2 Vector2::operator/(const float other)
{
    return Vector2((x / other), (y / other));
}

void Vector2::operator+=(const Vector2& other) { (*this) = (*this) + other; }
void Vector2::operator-=(const Vector2& other) { (*this) = (*this) - other; }
void Vector2::operator*=(const float other) { (*this) = (*this) * other; }
void Vector2::operator/=(const float other) { (*this) = (*this) / other; }

bool Vector2::operator==(const Vector2& other)
{
    return ((x == other.x) && (y == other.y));
}

bool Vector2::operator!=(const Vector2& other)
{
    return ((x != other.x) && (y != other.y));
}

Vector2 operator-(const Vector2& other)
{
    return Vector2(-other.x, -other.y);
}
#pragma once

struct Vector2
{
    float x, y;

    Vector2(float x = 0, float y = 0);
    void operator=(const Vector2& other);

    Vector2 operator+(const Vector2& other);

    Vector2 operator-(const Vector2& other);

    Vector2 operator*(const float other);

    Vector2 operator/(const float other);

    void operator+=(const Vector2& other);
    void operator-=(const Vector2& other);
    void operator*=(const float other);
    void operator/=(const float other);

    bool operator==(const Vector2& other);

    bool operator!=(const Vector2& other);
};

Vector2 operator-(const Vector2& other);

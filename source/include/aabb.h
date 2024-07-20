#pragma once

#include "event.h"
#include "vector2.h"
#include <cmath>

struct Rectangle {
    float x;                // Rectangle top-left corner position x
    float y;                // Rectangle top-left corner position y
    float width;            // Rectangle width
    float height;           // Rectangle height

    bool stillColliding = false;

    std::event OnEnterCollision, OnStayCollision, OnExitCollision;

    Rectangle(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height)
    {
        
    }

    Rectangle() = default;

    bool IsPositionInside(const Vector2& position);

    void CheckCollisions(const Rectangle& rec2);
};
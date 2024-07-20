#include "include/aabb.h"

bool Rectangle::IsPositionInside(const Vector2& position)
{
    return (((position.x > x) && (position.x < x + width)) &&
            ((position.y > y) && (position.y < y + height)));
}

void Rectangle::CheckCollisions(const Rectangle& rec2)
{
    bool colliding = ((this->x < (rec2.x + rec2.width) && (this->x + this->width) > rec2.x) &&
        (this->y < (rec2.y + rec2.height) && (this->y + this->height) > rec2.y));

    if (colliding)
    {
        if (!stillColliding)
        {
            stillColliding = true;
            OnEnterCollision();
        }
        OnStayCollision();
    }
    else
    {
        if (stillColliding)
        {
            stillColliding = false;
            OnExitCollision();
        }
    }
}
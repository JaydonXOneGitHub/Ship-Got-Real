#pragma once

#include <citro2d.h>
#include <3ds.h>
#include "vector2.h"
#include "aabb.h"
#include "event.h"

struct Entity
{
    Vector2 position;
    Vector2 scale = Vector2(1, 1);

    Rectangle collider;

    virtual void Update(float delta) = 0;
    virtual void Draw(float delta) = 0;

    virtual ~Entity() = default;
};
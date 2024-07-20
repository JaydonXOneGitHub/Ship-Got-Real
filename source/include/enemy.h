#pragma once

#include "entity.h"

struct Enemy : public Entity
{
private:
    C2D_Image sprite;

    Vector2 velocity;

public:
    Enemy(C2D_Image sprite);

    void Update(float delta) override;
    void Draw(float delta) override;
};
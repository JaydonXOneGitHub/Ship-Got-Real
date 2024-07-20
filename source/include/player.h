#pragma once

#include "entity.h"

struct Player : public Entity
{
private:
    C2D_Image sprite;

public:
    Player(C2D_Image sprite);

    void Update(float delta) override;
    void Draw(float delta) override;
};
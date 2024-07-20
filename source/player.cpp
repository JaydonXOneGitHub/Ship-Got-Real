#include "include/player.h"

float Clamp(float value, float min, float max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

extern bool playerDied;
extern std::list<Entity*> entities;

static int spriteWidth = 20;
static int spriteHeight = 20;

Player::Player(C2D_Image sprite) : sprite(sprite)
{
    collider = Rectangle(
        position.x + 2,
        position.y + 2,
        spriteWidth - 4,
        spriteHeight - 4
    );

    collider.OnEnterCollision += []()
    {
        playerDied = true;
    };
}

#define SPEED 180

void Player::Update(float delta)
{
    u32 buttonsDown = hidKeysHeld();

    if (buttonsDown & KEY_CSTICK_LEFT || buttonsDown & KEY_DLEFT)
    {
        position.x = position.x - SPEED * delta;
    }
    else if (buttonsDown & KEY_CSTICK_RIGHT || buttonsDown & KEY_DRIGHT)
    {
        position.x = position.x + SPEED * delta;
    }

    buttonsDown = hidKeysHeld();
    
    if (buttonsDown & KEY_CSTICK_UP || buttonsDown & KEY_DUP)
    {
        position.y = position.y - SPEED * delta;
    }
    else if (buttonsDown & KEY_CSTICK_DOWN || buttonsDown & KEY_DDOWN)
    {
        position.y = position.y + SPEED * delta;
    }

    position.x = Clamp(position.x, 0, 400 - spriteWidth);
    position.y = Clamp(position.y, 0, 240 - spriteHeight);

    for (Entity* e : entities)
    {
        if (e == this) continue;

        collider.CheckCollisions(e->collider);
    }

    collider.x = position.x + 2;
    collider.y = position.y + 2;
}

void Player::Draw(float delta)
{
    C2D_DrawImageAt(sprite, position.x, position.y, 0);
}
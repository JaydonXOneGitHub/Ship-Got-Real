#include "include/enemy.h"
#include <random>

using namespace std;

int random_int(int min, int max) {
    // Create a random device object to seed the generator
    random_device rd;
    // Create a default random engine object with the seed
    default_random_engine gen(rd());
    // Create a uniform distribution object with the range
    uniform_int_distribution<int> dist(min, max);
    // Return a random integer from the distribution
    return dist(gen);
}

float Clamp(float value, float min, float max);

static int spriteWidth = 20;
static int spriteHeight = 20;

Enemy::Enemy(C2D_Image sprite) : sprite(sprite)
{
    velocity.x = random_int(-20, 20) * 5;
    velocity.y = random_int(-20, 20) * 5;

    collider = Rectangle(
        position.x + 2,
        position.y + 2,
        spriteWidth - 4,
        spriteHeight - 4
    );
}

#define SPEED 180

void Enemy::Update(float delta)
{
    if (position.x < 0 || position.x > 400 - spriteWidth)
    {
        position.x = Clamp(position.x, 0, 400 - spriteWidth);
        velocity.x *= -1;
    }
    if (position.y < 0 || position.y > 240 - spriteHeight)
    {
        position.y = Clamp(position.y, 0, 240 - spriteHeight);
        velocity.y *= -1;
    }
    
    position += velocity * delta;

    collider.x = position.x + 2;
    collider.y = position.y + 2;
}

void Enemy::Draw(float delta)
{
    C2D_DrawImageAt(sprite, position.x, position.y, 0);
}
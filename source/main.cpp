#include <3ds.h>
#include <stdio.h>
#include <citro2d.h>
#include "include/vector2.h"
#include "include/entity.h"
#include "include/player.h"
#include "include/enemy.h"
#include <iostream>
#include <chrono>

// KEEP IN MIND: 240x400 for top screen, 240x320 for bottom

static float deltaTime = 0;

std::list<Entity*> entities;

static float timer = 5;
static int enemyAmount = 0;
static float score = 0;

bool playerDied = false;

static C2D_SpriteSheet sprites;

int main(int argc, char **argv) {
    gfxInitDefault();
    romfsInit();

    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();

    // Code

    C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    consoleInit(GFX_BOTTOM, NULL);

    std::chrono::duration<float> result;

    sprites = C2D_SpriteSheetLoad("romfs:/gfx/sprites.t3x");

    u32 bgColor = C2D_Color32(20, 20, 20, 20);

    Player* p = new Player(C2D_SpriteSheetGetImage(sprites, 0));

    p->position = Vector2(220, 290);

    entities.push_back(p);

    while(aptMainLoop()) {
        auto start = std::chrono::high_resolution_clock::now();

        gspWaitForVBlank();
        hidScanInput();

        gfxFlushBuffers();
        // gfxSwapBuffers();

        if (playerDied)
        {
            if (hidKeysDown() & KEY_START)
                break;
            
            std::cout << "\x1b[2;1HFinal Score: " << (int)score;
            std::cout << "\x1b[3;1HPress START to exit.";
            continue;
        }

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        C3D_RenderTargetClear(top, C3D_ClearBits::C3D_CLEAR_COLOR, bgColor, -8);
		C2D_SceneBegin(top);

        timer -= deltaTime;
        score += deltaTime;

        if (timer < 0 && enemyAmount < 10)
        {
            timer = 5;
            entities.push_back(new Enemy(
                C2D_SpriteSheetGetImage(sprites, 3)
            ));
            enemyAmount++;
        }

        std::cout << "\x1b[1;1HScore: " << (int)score;

        for (Entity* e : entities)
        {
            e->Update(deltaTime);
            e->Draw(deltaTime);
        }

        C3D_FrameEnd(0);

        auto end = std::chrono::high_resolution_clock::now();

        result = end - start;

        deltaTime = result.count();
    }

    for (Entity* e : entities)
    {
        delete e;
    }

    C2D_Fini();
    C3D_Fini();

    romfsExit();
    gfxExit();
    return 0;
}
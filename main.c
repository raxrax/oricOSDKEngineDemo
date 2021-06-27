#include "tileset.c"
#include "vars.h"
#include "engine.c"
#include "explosion.c"
#include "player.c"
#include "enemy1.c"
#include "enemy2.c"
#include "gamemanager.c"

void printStars();

void main()
{
    poke(0x24e, 1);
    poke(0x24f, 1);

    paper(0);
    ink(7);

    hires();
    poke(0x26a, 10);
    // memcpy(0xa000, TILESET, 8000);

    elementWidth = 2;
    elementHight = 12;

    addObject(0, player, 10, 180);
    addObject(0, gameManager, 0, 0);

    addObject(ID_ENEMY, enemy2, 10, 10);

    printStars();

    while (1)
    {
        engine();
    }
}

void printStars()
{
    unsigned char i;
    for (i = 0; i < 50; ++i)
    {
        poke(0xa000 - (rand() % 8000), 64 + 8);
    }
}

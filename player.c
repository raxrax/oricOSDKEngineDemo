#include "vars.h"
#include "engine.c"

void playerBullet();

// var1 - bullet pos
void player()
{
    elementWidth = 2;
    elementHight = 12;

    if ((*currentObject).firstPrint == 0)
    {
        elementSrc = (unsigned int)SPRITE_PLAYER;
        elementDst = POS((*currentObject).x, (*currentObject).y);
        printElementA();

        (*currentObject).firstPrint = 1;
    }

    elementSrc = (unsigned int)SPRITE_PLAYER;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();

    switch (key1)
    {
    case KEY_LEFT:
        if ((*currentObject).x > 0)
            --((*currentObject).x);
        break;

    case KEY_RIGHT:
        if ((*currentObject).x < 38)
            ++((*currentObject).x);
        break;

    case KEY_FIRE:
        if (playerBulletsCount == 0)
        {
            addObject(0, playerBullet, (*currentObject).x + (*currentObject).var1, ((*currentObject).y) - 6);
            addObject(0, playerBullet, 1 + (*currentObject).x + (*currentObject).var1, ((*currentObject).y) - 6);
            (*currentObject).var1 = (*currentObject).var1 ? 0 : 1;
            playerBulletsCount = 2;
        }
        break;
    }

    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();
}

void playerBullet()
{
    unsigned char i, x, y;

    elementWidth = 1;
    elementHight = 6;

    if ((*currentObject).firstPrint == 0)
    {
        elementSrc = (unsigned int)SPRITE_PLAYER_BULLET;
        elementDst = POS((*currentObject).x, (*currentObject).y);
        printElementA();

        (*currentObject).firstPrint = 1;
    }

    elementSrc = (unsigned int)SPRITE_PLAYER_BULLET;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();

    (*currentObject).y -= 8;

    if ((*currentObject).y < 10)
    {
        (*currentObject).active = 0;
        --playerBulletsCount;
        return;
    }

    x = (*currentObject).x;
    y = (*currentObject).y;

    //collision chech
    for (i = 0; i < OBJECTS_MAX; ++i)
    {
        if (objects[i].type == ID_ENEMY && objects[i].y > y && objects[i].y < y + 12 && (objects[i].x == x || objects[i].x + 1 == x))
        {
            objects[i].exit = 1;
            (*currentObject).active = 0;
            --playerBulletsCount;
            addObject(0, explosion, objects[i].x, objects[i].y);
            return;
        }
    }

    elementSrc = (unsigned int)SPRITE_PLAYER_BULLET;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();
}
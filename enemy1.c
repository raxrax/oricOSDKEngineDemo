#include "vars.h"
#include "engine.c"

//var3 - horizontal add
//var2 - sprite speed cunter
//var1 - sprite state
void enemy1()
{
    unsigned char state;
    unsigned int spriteAddr;

    state = ((*currentObject).var1);

    //set sprite size
    elementWidth = 2;
    elementHight = 12;

    //first print
    if ((*currentObject).firstPrint == 0)
    {
        elementSrc = (unsigned int)SPRITE_ENEMY1 + state;
        elementDst = POS((*currentObject).x, (*currentObject).y);
        printElementA();

        (*currentObject).firstPrint = 1;
    }

    // print sprite
    elementSrc = (unsigned int)SPRITE_ENEMY1 + state;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();

    // y next step
    (*currentObject).y += 4;

    // x next step
    if ((*currentObject).var3 == 1)
    {
        if ((*currentObject).x < 38)
            ++(*currentObject).x;
        else
        {
            (*currentObject).var3 = 0;
        }
    }
    else
    {
        if (((*currentObject).x) > 2)
        {
            --(*currentObject).x;
        }
        else
        {
            (*currentObject).var3 = 1;
        }
    }

    //exit
    if ((*currentObject).y > 180 || (*currentObject).exit == 1)
    {
        (*currentObject).active = 0;
        return;
    }

    //next sprite
    if (++(*currentObject).var2 > SPRITES_ROTATE_SPEED)
    {
        if (state > 4)
        {
            ((*currentObject).var1) = 0;
        }
        else
        {
            (*currentObject).var1 += 2;
        }

        (*currentObject).var2 = 0;
        state = ((*currentObject).var1);
    }

    //print sprite
    elementSrc = (unsigned int)SPRITE_ENEMY1 + state;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();
}
#include "vars.h"
#include "engine.c"

//var2 - sprite speed cunter
//var1 - sprite state
void enemy2()
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
        elementSrc = (unsigned int)SPRITE_ENEMY2 + state;
        elementDst = POS((*currentObject).x, (*currentObject).y);
        printElementA();

        (*currentObject).firstPrint = 1;
    }

    // print sprite
    elementSrc = (unsigned int)SPRITE_ENEMY2 + state;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();

    // inc y
    (*currentObject).y += 2;

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
    elementSrc = (unsigned int)SPRITE_ENEMY2 + state;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();
}
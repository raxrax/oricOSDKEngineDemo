#include "vars.h"
#include "engine.c"

//var1 counter
void explosion()
{
    unsigned char state = (*currentObject).var1;

    if ((*currentObject).firstPrint == 0)
    {
        elementSrc = (unsigned int)SPRITE_EXPLOSION;
        elementDst = POS((*currentObject).x, (*currentObject).y);
        printElementA();

        (*currentObject).firstPrint = 1;
    }

    elementSrc = (unsigned int)SPRITE_EXPLOSION + (*currentObject).var1;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();

    if ((*currentObject).var1 > 4)
    {
        (*currentObject).active = 0;
        return;
    }

    (*currentObject).var1 += 2;

    elementSrc = (unsigned int)SPRITE_EXPLOSION + (*currentObject).var1;
    elementDst = POS((*currentObject).x, (*currentObject).y);
    printElementA();
}
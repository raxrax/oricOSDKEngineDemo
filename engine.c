#ifndef __ENGINE__
#define __ENGINE__

#define OBJECTS_MAX 20

void initObjects(void);
void wait(int time);
void addObject(char type, void *func, unsigned char x, unsigned char y);
void objectProcessing(void);
void engine(void);
void replaceObjectByID(unsigned char id, char type, void *func, unsigned char x, unsigned char y);
void systemDelay(void);

// #define DEBUG_MODE

#define KEY_STOPENGINE '!'

#define STATE_STOP 0
#define STATE_RUNNING 1
#define STATE_LEVELEND 2
#define STATE_PLAYERDIE 3

static struct objectStruct
{
    char type;
    unsigned char active;
    unsigned char x;
    unsigned char y;
    unsigned char firstPrint;
    unsigned char exit;
    unsigned char counter;
    void (*func)();
    unsigned char var1;
    unsigned char var2;
    unsigned char var3;
    unsigned char var4;
    char data[4];
};

static char key1, key2, prand;

unsigned char i;

static unsigned char objectsCount;
static unsigned char engineState = 0;
static unsigned char currentObjectIndex, newObject;

static struct objectStruct objects[OBJECTS_MAX];

static struct objectStruct *currentObject;

void empty()
{
}

void initObjects(void)
{
    unsigned char i;
    for (i = 0; i < OBJECTS_MAX; i++)
    {
        objects[i].active = 0;
    }
}

void wait(int time)
{
    doke(0x276, time);
    while (deek(0x276) > 0)
        ;
}

void addObject(char type, void *func, unsigned char x, unsigned char y)
{
    for (i = 0; i < OBJECTS_MAX; ++i)
    {
        if (!objects[i].active)
        {
            objects[i].active = 1;
            objects[i].type = type;
            objects[i].x = x;
            objects[i].y = y;
            objects[i].func = func;
            objects[i].firstPrint = 0;
            objects[i].exit = 0;
            objects[i].counter = 0;
            objects[i].var1 = 0;
            objects[i].var2 = 0;
            objects[i].var3 = 0;
            objects[i].var4 = 0;
            newObject = i;
            return;
        }
    }
}

void replaceObjectByID(unsigned char id, char type, void *func, unsigned char x, unsigned char y)
{

    objects[id].active = 1;
    objects[id].type = type;
    objects[id].x = x;
    objects[id].y = y;
    objects[id].func = func;
    objects[i].firstPrint = 0;
    objects[i].exit = 0;
    objects[i].counter = 0;
    objects[i].var1 = 0;
    objects[i].var2 = 0;
    objects[i].var3 = 0;
    objects[i].var4 = 0;
    newObject = id;
    return;
}

void deleteObjectByType(unsigned char type)
{
    for (i = 0; i < OBJECTS_MAX; ++i)
    {
        if (objects[i].active && objects[i].type == type)
        {
            objects[i].active = 0;
        }
    }
}

void objectProcessing(void)
{
    unsigned char i;
    objectsCount = 0;
    for (i = 0; i < OBJECTS_MAX; ++i)
    {
        if (objects[i].active)
        {
            currentObjectIndex = i;
            currentObject = &objects[i];
            objectsCount++;
            objects[i].func();
        }
    }

#ifdef DEBUG_MODE
    sprintf((0xbb80 + 27 * 40), "%d ", objectsCount);
#endif
}

void engine(void)
{
    engineState = STATE_RUNNING;
    while (engineState == STATE_RUNNING)
    {
        key1 = key();

        prand = (char)rand();

        objectProcessing();

        if (key1 == KEY_STOPENGINE)
        {
            engineState = STATE_STOP;
        }
    }
}

#endif
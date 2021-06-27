void gameManager()
{
    unsigned char r = rand();

    if (r < 10)
    {
        addObject(ID_ENEMY, enemy1, (-rand() % 38), 10);
    }

    if (r > 240)
    {
        addObject(ID_ENEMY, enemy2, (-rand() % 38), 10);
    }
}

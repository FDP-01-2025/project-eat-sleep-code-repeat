#include "../headers/ConfigurationLevel2.h"

COORD level2Obstacles[MAX_OBSTACLES];
int obstacleCount = 0;

void configurationLevel2()
{
    int index = 0;

    // Línea horizontal superior (Y = 8), de X = 28 a 32
    for (int x = 28; x <= 32; x++)
    {
        level2Obstacles[index].X = x;
        level2Obstacles[index].Y = 8;
        index++;
    }

    // Línea horizontal inferior (Y = 12), de X = 28 a 32
    for (int x = 28; x <= 32; x++)
    {
        level2Obstacles[index].X = x;
        level2Obstacles[index].Y = 12;
        index++;
    }

    obstacleCount = index;
}

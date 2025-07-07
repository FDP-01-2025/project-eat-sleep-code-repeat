#include "../headers/ConfigurationLevel2.h"

COORD level2Obstacles[MAX_OBSTACLES];
int obstacleCountlevel2 = 0;

// Function to configure the obstacles for level 2
// This function sets the positions of the obstacles in the level 2 configuration
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

    obstacleCountlevel2 = index;
}
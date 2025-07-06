#include "../headers/ConfigurationLevel3.h"

COORD level3Obstacles[MAX_OBSTACLES];
int obstacleCountlevel3 = 0;
// Function to configure the obstacles for level 3
// This function sets the positions of the obstacles in the level 3 configuration
void configurationLevel3()
{
    int index = 0;

    // Línea horizontal superior (Y = 8), de X = 28 a 32
    for (int x = 28; x <= 32; x++)
    {
        level3Obstacles[index].X = x;
        level3Obstacles[index].Y = 8;
        index++;
    }

    // Línea horizontal inferior (Y = 12), de X = 28 a 32
    for (int x = 28; x <= 32; x++)
    {
        level3Obstacles[index].X = x;
        level3Obstacles[index].Y = 12;
        index++;
    }

    obstacleCountlevel3 = index;
}

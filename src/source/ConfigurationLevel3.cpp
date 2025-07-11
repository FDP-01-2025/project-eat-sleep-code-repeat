#include "../headers/ConfigurationLevel3.h"

COORD level3Obstacles[MAX_OBSTACLES];
int obstacleCountlevel3 = 0;

void configurationLevel3()
{
    obstacleCountlevel3 = 0;

    // Top and bottom borders with spaces (every 4 units)
    for (int x = 10; x <= 50; x += 4)
    {
        level3Obstacles[obstacleCountlevel3].X = x;
        level3Obstacles[obstacleCountlevel3].Y = 5;
        obstacleCountlevel3++;

        level3Obstacles[obstacleCountlevel3].X = x;
        level3Obstacles[obstacleCountlevel3].Y = 15;
        obstacleCountlevel3++;
    }

    // Left and right borders with spaces (every 2 units)
    for (int y = 6; y <= 14; y += 2)
    {
        level3Obstacles[obstacleCountlevel3].X = 10;
        level3Obstacles[obstacleCountlevel3].Y = y;
        obstacleCountlevel3++;

        level3Obstacles[obstacleCountlevel3].X = 50;
        level3Obstacles[obstacleCountlevel3].Y = y;
        obstacleCountlevel3++;
    }

    // Internal pattern: horizontal bars with gaps (creates corridors)
    for (int x = 20; x <= 40; x += 2)
    {
        if (x != 30)
        { // Leave the center open
            level3Obstacles[obstacleCountlevel3].X = x;
            level3Obstacles[obstacleCountlevel3].Y = 8;
            obstacleCountlevel3++;

            level3Obstacles[obstacleCountlevel3].X = x;
            level3Obstacles[obstacleCountlevel3].Y = 12;
            obstacleCountlevel3++;
        }
    }

    // Internal pattern: vertical bars with gaps (creates corridors)
    for (int y = 7; y <= 13; y += 2)
    {
        if (y != 10)
        { // Leave the center open
            level3Obstacles[obstacleCountlevel3].X = 25;
            level3Obstacles[obstacleCountlevel3].Y = y;
            obstacleCountlevel3++;

            level3Obstacles[obstacleCountlevel3].X = 35;
            level3Obstacles[obstacleCountlevel3].Y = y;
            obstacleCountlevel3++;
        }
    }
}
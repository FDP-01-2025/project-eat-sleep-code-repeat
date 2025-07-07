#include "../headers/ConfigurationLevel3.h"

COORD level3Obstacles[MAX_OBSTACLES];
int obstacleCountlevel3 = 0;
// Function to configure the obstacles for level 3
// This function sets the positions of the obstacles in the level 3 configuration
void configurationLevel3() {
    int index = 0;
    // 8 obstáculos en forma de marco
    int obstacles[8][2] = {
        {10, 5}, {50, 5}, {10, 15}, {50, 15},  // Esquinas
        {30, 5}, {30, 15}, {10, 10}, {50, 10}   // Nuevos
    };
    for (int i = 0; i < 8; i++) {
        level3Obstacles[index].X = obstacles[i][0];
        level3Obstacles[index].Y = obstacles[i][1];
        index++;
    }
    obstacleCountlevel3 = index;
}
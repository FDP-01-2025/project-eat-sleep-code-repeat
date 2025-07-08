#include "../headers/ConfigurationLevel3.h"

COORD level3Obstacles[MAX_OBSTACLES];
int obstacleCountlevel3 = 0;

void configurationLevel3() {
    int index = 0;
    int obstacles[][2] = {
        // Marco superior e inferior (X = 12 a 48)
        {12, 6}, {14, 6}, {16, 6}, {18, 6}, {20, 6}, {22, 6}, {24, 6}, {26, 6}, {28, 6}, {30, 6}, {32, 6}, {34, 6}, {36, 6}, {38, 6}, {40, 6}, {42, 6}, {44, 6}, {46, 6}, {48, 6},
        {12, 14}, {14, 14}, {16, 14}, {18, 14}, {20, 14}, {22, 14}, {24, 14}, {26, 14}, {28, 14}, {30, 14}, {32, 14}, {34, 14}, {36, 14}, {38, 14}, {40, 14}, {42, 14}, {44, 14}, {46, 14}, {48, 14},
        // Marco izquierdo y derecho (Y = 7 a 13)
        {12, 7}, {12, 8}, {12, 9}, {12, 10}, {12, 11}, {12, 12}, {12, 13},
        {48, 7}, {48, 8}, {48, 9}, {48, 10}, {48, 11}, {48, 12}, {48, 13},
        // Líneas horizontales internas (X = 20 a 40, Y = 9 y 11), pero deja libre X=28 a X=32
        {20, 9}, {22, 9}, {24, 9}, {26, 9}, /*{28, 9},*/ /*{30, 9},*/ /*{32, 9},*/ {34, 9}, {36, 9}, {38, 9}, {40, 9},
        {20, 11}, {22, 11}, {24, 11}, {26, 11}, /*{28, 11},*/ /*{30, 11},*/ /*{32, 11},*/ {34, 11}, {36, 11}, {38, 11}, {40, 11}
    };
    int numObstacles = sizeof(obstacles) / sizeof(obstacles[0]);
    for (int i = 0; i < numObstacles; i++) {
        level3Obstacles[index].X = obstacles[i][0];
        level3Obstacles[index].Y = obstacles[i][1];
        index++;
    }
    obstacleCountlevel3 = index;
}
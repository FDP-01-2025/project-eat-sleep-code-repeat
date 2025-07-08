#include "../headers/ConfigurationLevel1.h"

COORD level1Obstacles[MAX_OBSTACLES];
int obstacleCountLevel1 = 0;

void configurationLevel1() {
    obstacleCountLevel1 = 0;
    
    // Left column (X=10) - 16 vertical obstacles
    for(int y = 1; y <= 16; y++) {  
        level1Obstacles[obstacleCountLevel1].X = 10;
        level1Obstacles[obstacleCountLevel1].Y = y;
        obstacleCountLevel1++;
    }

   // Right column (X=49) - 16 vertical obstacles
    for(int y = 1; y <= 16; y++) {  
        level1Obstacles[obstacleCountLevel1].X = 49;
        level1Obstacles[obstacleCountLevel1].Y = y;
        obstacleCountLevel1++;
    }

    // Top center row (Y=6) - 16 horizontal obstacles
    for(int x = 22; x <= 37; x++) {  
        level1Obstacles[obstacleCountLevel1].X = x;
        level1Obstacles[obstacleCountLevel1].Y = 6;
        obstacleCountLevel1++;
    }

    // Bottom center row (Y=13) - 16 horizontal obstacles
    for(int x = 22; x <= 37; x++) {  
        level1Obstacles[obstacleCountLevel1].X = x;
        level1Obstacles[obstacleCountLevel1].Y = 13;
        obstacleCountLevel1++;
    }
}
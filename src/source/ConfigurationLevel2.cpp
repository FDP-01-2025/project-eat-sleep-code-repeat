#include "../headers/ConfigurationLevel2.h"

COORD level2Obstacles[MAX_OBSTACLES];
int obstacleCountlevel2 = 0;

void configurationLevel2() {
    obstacleCountlevel2 = 0;

    // Marco simple con más espacios
    for(int x = 15; x <= 45; x += 6) {  // Bordes superior e inferior
        level2Obstacles[obstacleCountlevel2].X = x;
        level2Obstacles[obstacleCountlevel2].Y = 5;
        obstacleCountlevel2++;
        
        level2Obstacles[obstacleCountlevel2].X = x;
        level2Obstacles[obstacleCountlevel2].Y = 15;
        obstacleCountlevel2++;
    }

    for(int y = 7; y <= 13; y += 4) {  // Bordes laterales
        level2Obstacles[obstacleCountlevel2].X = 15;
        level2Obstacles[obstacleCountlevel2].Y = y;
        obstacleCountlevel2++;
        
        level2Obstacles[obstacleCountlevel2].X = 45;
        level2Obstacles[obstacleCountlevel2].Y = y;
        obstacleCountlevel2++;
    }

    // Solo 4 obstáculos centrales en forma de cruz simple
    level2Obstacles[obstacleCountlevel2].X = 30; level2Obstacles[obstacleCountlevel2].Y = 8; obstacleCountlevel2++;
    level2Obstacles[obstacleCountlevel2].X = 30; level2Obstacles[obstacleCountlevel2].Y = 12; obstacleCountlevel2++;
    level2Obstacles[obstacleCountlevel2].X = 25; level2Obstacles[obstacleCountlevel2].Y = 10; obstacleCountlevel2++;
    level2Obstacles[obstacleCountlevel2].X = 35; level2Obstacles[obstacleCountlevel2].Y = 10; obstacleCountlevel2++;
}
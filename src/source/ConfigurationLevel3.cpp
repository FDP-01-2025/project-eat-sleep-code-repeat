#include "../headers/ConfigurationLevel3.h"

COORD level3Obstacles[MAX_OBSTACLES];
int obstacleCountlevel3 = 0;

void configurationLevel3() {
    obstacleCountlevel3 = 0;

    // Marco con espacios para movimiento (X = 10 a 50)
    for(int x = 10; x <= 50; x += 4) {  // Bordes superior e inferior con espacios
        level3Obstacles[obstacleCountlevel3].X = x;
        level3Obstacles[obstacleCountlevel3].Y = 5;
        obstacleCountlevel3++;
        
        level3Obstacles[obstacleCountlevel3].X = x;
        level3Obstacles[obstacleCountlevel3].Y = 15;
        obstacleCountlevel3++;
    }

    for(int y = 6; y <= 14; y += 2) {  // Bordes laterales con espacios
        level3Obstacles[obstacleCountlevel3].X = 10;
        level3Obstacles[obstacleCountlevel3].Y = y;
        obstacleCountlevel3++;
        
        level3Obstacles[obstacleCountlevel3].X = 50;
        level3Obstacles[obstacleCountlevel3].Y = y;
        obstacleCountlevel3++;
    }

    // Patrón interno con pasillos
    for(int x = 20; x <= 40; x += 2) {  // Barras horizontales con espacios
        if(x != 30) {  // Dejar espacio central
            level3Obstacles[obstacleCountlevel3].X = x;
            level3Obstacles[obstacleCountlevel3].Y = 8;
            obstacleCountlevel3++;
            
            level3Obstacles[obstacleCountlevel3].X = x;
            level3Obstacles[obstacleCountlevel3].Y = 12;
            obstacleCountlevel3++;
        }
    }

    for(int y = 7; y <= 13; y += 2) {  // Barras verticales con espacios
        if(y != 10) {  // Dejar espacio central
            level3Obstacles[obstacleCountlevel3].X = 25;
            level3Obstacles[obstacleCountlevel3].Y = y;
            obstacleCountlevel3++;
            
            level3Obstacles[obstacleCountlevel3].X = 35;
            level3Obstacles[obstacleCountlevel3].Y = y;
            obstacleCountlevel3++;
        }
    }
}
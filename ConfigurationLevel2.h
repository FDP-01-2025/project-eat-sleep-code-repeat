#ifndef CONFIGURATION_LEVEL2_H_
#define CONFIGURATION_LEVEL2_H_

#include <windows.h>

#define MAX_OBSTACLES 10

// Arreglo global que contiene las posiciones de los obstáculos del nivel 2
extern COORD level2Obstacles[MAX_OBSTACLES];
extern int obstacleCount;

// Configura los obstáculos del nivel 2
void configurationLevel2();

#endif 

#ifndef CONFIGURATION_LEVEL1_H_
#define CONFIGURATION_LEVEL1_H_

#include <windows.h>
#include "Config.h"   // Include global configuration

// Global array that contains the positions of level 1 obstacles
extern COORD level1Obstacles[MAX_OBSTACLES];
extern int obstacleCountLevel1;

// Number of obstacles in level 1
void configurationLevel1();

#endif
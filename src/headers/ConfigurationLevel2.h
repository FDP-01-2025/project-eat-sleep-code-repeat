#ifndef CONFIGURATION_LEVEL2_H_
#define CONFIGURATION_LEVEL2_H_

#include <windows.h>
#include "Config.h"  // Include global configuration

// Global array that contains the positions of level 2 obstacles
extern COORD level2Obstacles[MAX_OBSTACLES];
extern int obstacleCount;

// Configures level 2 obstacles
void configurationLevel2();

#endif
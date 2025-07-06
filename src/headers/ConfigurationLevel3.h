#ifndef CONFIGURATION_LEVEL3_H_
#define CONFIGURATION_LEVEL3_H_

#include <windows.h>
#include "Config.h"  // Include global configuration

// Global array that contains the positions of level 3 obstacles
extern COORD level3Obstacles[MAX_OBSTACLES];

extern int obstacleCountlevel3;  // Number of obstacles in level 3

// Configures level 3 obstacles
void configurationLevel3();

#endif
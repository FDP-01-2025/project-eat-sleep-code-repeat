#ifndef CONFIG_H_
#define CONFIG_H_
#include <windows.h>

// Game window dimensions
#define GAME_WIDTH 60
#define GAME_HEIGHT 20

// Snake configuration
#define MAX_SNAKE_LENGTH 100

// Obstacles configuration
#define MAX_OBSTACLES 200

// Game speed (milliseconds between frames)
#define GAME_SPEED 65

// Level progression
#define POINTS_PER_FOOD 10
#define POINTS_FOR_LEVEL_2 50
#define POINTS_FOR_LEVEL_3 100

// Colors definition
#define MUSTARD_YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define FOREST_GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define DARK_RED FOREGROUND_RED | FOREGROUND_INTENSITY
#define FREEZE_COLOR FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY

#endif /* CONFIG_H_ */
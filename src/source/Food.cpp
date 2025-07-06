#include "../headers/Food.h"

COORD foodPosition; // This is the global variable to store the position of the food.

void initFood() // We start the food in a random position.
{
    spawnFood(); // Generates a random position at startup
}

// Random position of the food is generated.
void spawnFood()
{
    foodPosition.X = rand() % GAME_WIDTH;
    foodPosition.Y = rand() % GAME_HEIGHT;
}

// Returns the current position of the food.
COORD getFoodPos()
{
    return foodPosition;
}
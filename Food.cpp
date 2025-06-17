#include "Food.h"

//Constructor:
Food::Food()
{
    spawnFood();
}

//Methods:
void Food::spawnFood()
{
    srand(time(0));

    foodPos.X = rand() % W; // X position of the food (Define the maximum range (w))
    foodPos.Y = rand() % H; // Y position of the food (Define the maximum range (h))
}

//Getters:
COORD Food::getFoodPos()
{
    return foodPos;
}
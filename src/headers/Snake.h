#ifndef SNAKE_H_
#define SNAKE_H_

#include <windows.h> // This library is for cleaning the console (cls)
#include "Config.h"  // Include global configuration

// Declaration of functions:
void initSnake();
void changeDirection(char newDirection);
void moveSnake();
void increaseSnakeLength();
int checkEatFood(COORD foodPos);
int checkCollision();
COORD getSnakeHead();
void getSnakeBody(COORD bodyOut[], int *lengthOut);

#endif /* SNAKE_H_ */
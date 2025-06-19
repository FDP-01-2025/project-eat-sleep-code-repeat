#ifndef SNAKE_H_
#define SNAKE_H_

#include <windows.h> //This library is for cleaning the console (cls)

#define width 20       // Height and width of the game window.
#define height 20      // Height and width of the game window.
#define MAX_LENGTH 100 // maximum allowed length of the snake for the moment

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
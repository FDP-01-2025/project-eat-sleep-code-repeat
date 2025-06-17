#ifndef SNAKE_H_
#define SNAKE_H_

#include <windows.h> //This library is for cleaning the console (cls)
#include <vector>    ////Check since we cannot use Vectors 😅

using namespace std;

#define W 20 // Height and width of the game window.
#define H 20 // Height and width of the game window.

class Snake
{
private:
    COORD snakePos;
    int snakeLength;
    int snakeVelocity;
    char snakeDirection;
    vector<COORD> body;

public:
    // Constructor:
    Snake(COORD _snakePos, int _snakeVelocity);

    // Methods:
    void changeDirection(char _newDirection);
    void move();
    void increaseSnakeTail();
    bool checkEatFood(COORD _foodPos);
    bool checkCollision();

    // Getters:
    COORD getSnakePos();
    vector<COORD> getBody();

    
};

#endif /* SNAKE_H_ */
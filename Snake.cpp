#include "Snake.h"

Snake::Snake(COORD _snakePos, int _snakeVelocity)
{
    snakePos = _snakePos;
    snakeVelocity = _snakeVelocity;
    snakeLength = 1;
    snakeDirection = 'S';
    body.push_back(snakePos);
}

void Snake::changeDirection(char _newDirection)
{
    snakeDirection = _newDirection;
}

void Snake::move()
{
    switch (snakeDirection)
    {
    case 'U': // UP
        snakePos.Y -= snakeVelocity;
        break;

    case 'D': // DOWN
        snakePos.Y += snakeVelocity;
        break;

    case 'L': // LEFT
        snakePos.X -= snakeVelocity;
        break;

    case 'R': // RIGHT
        snakePos.X += snakeVelocity;
        break;
    }
    body.push_back(snakePos);

    if (body.size() > snakeLength)
    {
        body.erase(body.begin());
    }
}

void Snake::increaseSnakeTail()
{
    snakeLength++;
}

bool Snake::checkEatFood(COORD _foodPos)
{
    bool eat = false;

    if (snakePos.X == _foodPos.X && snakePos.Y == _foodPos.Y)
        eat = true;

    return eat;
}

bool Snake::checkCollision()
{
    bool collision = false;

    if (snakePos.X >= W || snakePos.X < 0 || snakePos.Y >= H || snakePos.Y < 0)

        collision = true;

    for (int i = 0; i < snakeLength - 1; i++) // Traverse the snake's tail
    {
        if (snakePos.X == body[i].X && snakePos.Y == body[i].Y) // If the snake head touches its tail
        {
            collision = true;
        }
    }

    return collision;
}

COORD Snake::getSnakePos()
{
    return snakePos;
}

vector<COORD> Snake::getBody()
{
    return body;
}

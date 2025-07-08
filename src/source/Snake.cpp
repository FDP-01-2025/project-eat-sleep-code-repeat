#include "../headers/Snake.h"

COORD snakeBody[MAX_SNAKE_LENGTH]; // Serpent body (COORD ARRAY).
int snakeLength;                   // Actual length.
int snakeVelocity;                 // Movement speed (init 1).
char snakeDirection;               // Current direction (UP, DOWN, LEFT, RIGHT).

// Init the snake in the center of the game.
void initSnake()
{
    snakeLength = 1;
    snakeVelocity = 1;
    snakeDirection = 'S'; // Quiet at the start.
    /*
     * Place the snake's head in the center of the playing area.
     * - snakeBody[0] represents the head.
     * - GAME_WIDTH / 2: half of width (COORD X).
     * - GAME_HEIGHT / 2: half of height (COORD Y).
     */
    snakeBody[0].X = GAME_WIDTH / 2;
    snakeBody[0].Y = GAME_HEIGHT / 2;
}

// Changes the direction of the snake.
void changeDirection(char newDirection)
{
    // Do not allow turning in direct opposite direction
    if ((snakeDirection == 'U' && newDirection == 'D') ||
        (snakeDirection == 'D' && newDirection == 'U') ||
        (snakeDirection == 'L' && newDirection == 'R') ||
        (snakeDirection == 'R' && newDirection == 'L'))
    {
        return; // Ignore Invalid Change
    }

    snakeDirection = newDirection;
}

// Moves the snake according to its current direction.
void moveSnake()
{
    // Moving the body forward.
    for (int i = snakeLength - 1; i > 0; i--)
    {
        snakeBody[i] = snakeBody[i - 1];
    }

    // Move the head of the snake.
    switch (snakeDirection)
    {
    case 'U':
        snakeBody[0].Y -= snakeVelocity;
        break;
    case 'D':
        snakeBody[0].Y += snakeVelocity;
        break;
    case 'L':
        snakeBody[0].X -= snakeVelocity;
        break;
    case 'R':
        snakeBody[0].X += snakeVelocity;
        break;
    }
}

// Increase the length of snake.
void increaseSnakeLength()
{
    if (snakeLength < MAX_SNAKE_LENGTH)
    {
        snakeBody[snakeLength] = snakeBody[snakeLength - 1];
        snakeLength++;
    }
}

// Check if the snake has eaten the food.
int checkEatFood(COORD foodPos)
{
    if (snakeBody[0].X == foodPos.X && snakeBody[0].Y == foodPos.Y)
    {
        return 1;
    }
    return 0;
}

// Check if the snake has collided with itself or with the edges.
int checkCollision()
{
    // Collision with edges
    if (snakeBody[0].X < 0 || snakeBody[0].X >= GAME_WIDTH || snakeBody[0].Y < 0 || snakeBody[0].Y >= GAME_HEIGHT)
    {
        return 1;
    }

    // Collision with itself
    for (int i = 1; i < snakeLength; i++)
    {
        if (snakeBody[0].X == snakeBody[i].X && snakeBody[0].Y == snakeBody[i].Y)
        {
            return 1;
        }
    }

    return 0;
}

// Returns the position of the head.
COORD getSnakeHead()
{
    return snakeBody[0];
}

// Returns a copy of the snake body and its length.
void getSnakeBody(COORD bodyOut[], int *lengthOut)
{
    for (int i = 0; i < snakeLength; i++)
    {
        bodyOut[i] = snakeBody[i];
    }
    *lengthOut = snakeLength;
}
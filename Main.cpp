#include <iostream>
#include <windows.h> //This library is for cleaning the console (cls)
#include <time.h>    //This library is for using time() in srand()
#include <stdlib.h>  //This library is for using rand() and srand()
#include <conio.h>   //This library is for using _getch() for keyboard input

using namespace std;

const int W = 20, H = 20;   // Height and width of the game window.
bool gameOver;              // Determine if the game is over
int headPos[2], foodPos[2]; // Position of X and Y of the snake and the food
int tailPosX[100], tailPosY[100], tailLength; // Positions of the snake's tail
int score;                  // Player's score

enum directionEnum
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};                            // Enumeration for directions
directionEnum snakeDirection; // Variable for the snake's direction

// Initialize everything
void init()
{
    system("cls"); // Clear the console when starting the game

    headPos[0] = W / 2; // X position of the snake
    headPos[1] = H / 2; // Y position of the snake

    foodPos[0] = rand() % W; // X position of the food (Define the maximum range (w))
    foodPos[1] = rand() % H; // Y position of the food (Define the maximum range (h))

    score = 0;  // Initialize the score to 0

    snakeDirection = STOP; // Initialize the snake's direction

    gameOver = false;
}
// Render everything on the screen
void render()
{
    system("cls"); // Clear the console (in Linux it would be system("clear"))

    // Render the top part of the frame
    for (int i = 0; i < W + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    // Render the middle parts (the game area)
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j == 0) // Left wall
                cout << "#";

            if (j == headPos[0] && i == headPos[1]) // Snake head
                cout << "O";

            else if (j == foodPos[0] && i == foodPos[1]) // Food
                cout << "*";

            else
            {
                bool printTail = false;

                // Draw the snake's tail
                for (int k = 0; k < tailLength; k++)
                {
                    if (tailPosX[k] == j && tailPosY[k] == i)
                    {
                        cout << "o";
                        printTail = true;
                    }
                }

                if (!printTail) // Blank space if there is no snake or food
                    cout << " ";
            }

            if (j == W - 1) // Right wall
                cout << "#";
        }

        cout << endl;
    }

    // Render the bottom part of the frame
    for (int i = 0; i < W + 2; i++)
    {
        cout << "#";
    }

    cout << endl
         << endl;

    // Show the current score
    cout << "Score: " << score << endl;
}

// Receive the input from the user keyboard
void input()
{
    if (_kbhit()) // Check if a key has been pressed
    {
        switch (_getch()) // Get the pressed key
        {
        case 'a':                  // If the 'a' key is pressed
            snakeDirection = LEFT; // The snake goes left
            break;
        case 'd':                   // If the 'd' key is pressed
            snakeDirection = RIGHT; // The snake goes right
            break;
        case 'w':                   // If the 'w' key is pressed
            snakeDirection = UP;    // The snake goes up
            break;
        case 's':                   // If the 's' key is pressed
            snakeDirection = DOWN;  // The snake goes down
            break;
        case 'q':                   // If the 'q' key is pressed
            gameOver = true;        // The game is over
            break;
        }
    }
}

// All the game logic is here
void gameLogic()
{
    int prevTailPosX = tailPosX[0]; // Save the X position of the tail
    int prevTailPosY = tailPosY[0]; // Save the Y position of the tail

    int prevTailPosX2, prevTailPosY2; // Save the X and Y position of the previous tail
    tailPosX[0] = headPos[0]; // Update the X position of the snake head
    tailPosY[0] = headPos[1]; // Update the Y position of the snake head

    for(int i = 1; i < tailLength; i++) // Traverse the snake's tail
    {
        prevTailPosX2 = tailPosX[i]; // Save the X position of the previous tail
        prevTailPosY2 = tailPosY[i]; // Save the Y position of the previous tail

        tailPosX[i] = prevTailPosX; // Update the X position of the tail
        tailPosY[i] = prevTailPosY; // Update the Y position of the tail

        prevTailPosX = prevTailPosX2; // Update the X position of the previous tail
        prevTailPosY = prevTailPosY2; // Update the Y position of the previous tail

    }


    switch (snakeDirection)
    {
    case STOP:
        // Don't move the snake if the direction is STOP
        break;

    case LEFT:
        headPos[0]--; // Move the snake head one position to the left
        break;

    case RIGHT:
        headPos[0]++; // Move the snake head one position to the right
        break;

    case UP:
        headPos[1]--; // Move the snake head one position up
        break;

    case DOWN:
        headPos[1]++; // Move the snake head one position down
        break;
    }

    if(headPos[0] >= W || headPos[0] < 0 || headPos [1] >= H || headPos[1] < 0)//If the snake head touches the game borders
        gameOver = true; // The game is over


    for(int i = 0; i < tailLength; i++) // Traverse the snake's tail
    {
        if(tailPosX[i] == headPos[0] && tailPosY[i] == headPos[1]) // If the snake head touches its tail
        {
            gameOver = true; // The game is over
        }
    }
    if(headPos[0] == foodPos[0] && headPos[1] == foodPos[1]) // If the snake head touches the food
    {
        score += 10; // Increase the score
        foodPos[0] = rand() % W; // Generate a new X position for the food
        foodPos[1] = rand() % H; // Generate a new Y position for the food
        tailLength++; // Increase the length of the tail
    }
}

int main()
{
    srand(time(0)); // Initialize the random seed

    init();

    while (!gameOver) // While gameOver is false the game continues
    {
        render();
        input();
        gameLogic();
        Sleep(50); // Pause so the game doesn't go too fast
    }
}
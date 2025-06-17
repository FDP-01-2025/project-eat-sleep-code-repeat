#include <iostream>
#include <conio.h> //This library is for using _getch() for keyboard input
#include <time.h>
#include "Snake.h"
#include "Food.h"

#define W 20 // Height and width of the game window.
#define H 20 // Height and width of the game window.

using namespace std;

//Variables:
bool gameOver; // Determine if the game is over
int score;     // Player's score


Snake snake({W/2, H/2}, 1);
Food food;

// Initialize everything

//Methods:

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void init()
{
    system("cls"); // Clear the console when starting the game

    score = 0; // Initialize the score to 0

    gameOver = false;
}
// Render everything on the screen
void render()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0}); // To avoid the flickering generated when running the game.

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

            if (j == snake.getSnakePos().X && i == snake.getSnakePos().Y) // Snake head
                cout << "O";

            else if (j == food.getFoodPos().X && i == food.getFoodPos().Y) // Food
                cout << "*";

            else
            {
                bool printTail = false;

                // Draw the snake's tail
                for (int k = 0; k < snake.getBody().size(); k++)
                {
                    if (j == snake.getBody()[k].X && i == snake.getBody()[k].Y)
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

    cout<<endl<<endl;

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
        case 'a':                       // If the 'a' key is pressed
            snake.changeDirection('L'); // The snake goes left
            break;
        case 'd':                       // If the 'd' key is pressed
            snake.changeDirection('R'); // The snake goes right
            break;
        case 'w':                       // If the 'w' key is pressed
            snake.changeDirection('U'); // The snake goes up
            Sleep(25);
            break;
        case 's':                       // If the 's' key is pressed
            snake.changeDirection('D'); // The snake goes down
            Sleep(25);
            break;
        case 'q':            // If the 'q' key is pressed
            gameOver = true; // The game is over
            break;
        }
    }
    snake.move();
}

// All the game logic is here
void gameLogic()
{

    if (snake.checkCollision()) // If the snake head touches the game borders
    {
        gameOver = true; // The game is over
    }
    if (snake.checkEatFood(food.getFoodPos())) // If the snake head touches the food
    {
        score += 10; // Increase the score
        food.spawnFood();
        snake.increaseSnakeTail(); // Increase the length of the tail
    }
}

int main()
{
    srand(time(0)); // Initialize the random seed

    init();

     ShowConsoleCursor(false);

    while (!gameOver) // While gameOver is false the game continues
    {
        render();
        Sleep(65); // Pause so the game doesn't go too fast
        input();
        gameLogic();
    }

    cout << "End of the Game :(" << endl;

    return 0;
}
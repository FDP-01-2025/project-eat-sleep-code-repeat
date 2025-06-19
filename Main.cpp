#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Snake.h"
#include "Food.h"

#define width 20
#define height 20

using namespace std;

// Global variables
bool gameOver = false;
int score = 0;

// Hides or shows the cursor in the console.
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Init the game.
void initGame()
{
    system("cls");
    score = 0;
    gameOver = false;
    initSnake();
    initFood();
    ShowConsoleCursor(false);
}

// Draw the scenario, snake and food
void render()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    // top edge.
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    COORD head = getSnakeHead();
    COORD food = getFoodPos();
    COORD body[100];
    int length;
    getSnakeBody(body, &length);

    // Game area.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            if (j == head.X && i == head.Y)
                cout << "O";
            else if (j == food.X && i == food.Y)
                cout << "*";
            else
            {
                bool tailPart = false;
                for (int k = 1; k < length; k++)
                {
                    if (j == body[k].X && i == body[k].Y)
                    {
                        cout << "o";
                        tailPart = true;
                        break;
                    }
                }
                if (!tailPart)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    // lower edge.
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << "\n\nScore: " << score << endl;
}

// Handles keyboard input
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            changeDirection('L');
            break;
        case 'd':
            changeDirection('R');
            break;
        case 'w':
            changeDirection('U');
            break;
        case 's':
            changeDirection('D');
            break;
        case 'q':
            gameOver = true;
            break;
        }
    }
    moveSnake();
}

/*
//Check if there is a collision, end the game.
Also if there is a collision with the food, increase the score.
Respawn another food and increase the length of the snake by 1
*/
void gameLogic()
{
    if (checkCollision())
        gameOver = true;

    if (checkEatFood(getFoodPos()))
    {
        score += 10;
        spawnFood();
        increaseSnakeLength();
    }
}

int main()
{
    srand(time(0));
    initGame();

    while (!gameOver)
    {
        render();
        Sleep(65);
        input();
        gameLogic();
    }
    cout << "End of the Game :(" << endl;
    return 0;
}
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Snake.h"
#include "Food.h"
#include "ConfigurationLevel2.h"  // NUEVO: incluir archivo de obstáculos *cambiar a ingles

#define width 60
#define height 20

using namespace std;

void showStartMenu()
{
    system("cls");
    cout << "*---------------------------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "|                                                                                                                                             |" << endl;
    cout << "| *********  * *         *          *          *       *  *         *  **********  *      *  **********  * *         *  **********  ********* |" << endl;
    cout << "| *          *  *        *         * *         *     *     *       *       **      *      *      **      *  *        *  **          *         |" << endl;
    cout << "| *          *   *       *        *   *        *   *        *     *        **      *      *      **      *   *       *  **          *         |" << endl;
    cout << "| *          *    *      *       *     *       * *           *   *         **      *      *      **      *    *      *  **          *         |" << endl;
    cout << "| *********  *     *     *      *       *      * *            ***          **      ********      **      *     *     *  **  ******  ********* |" << endl;
    cout << "|         *  *      *    *     * ******* *     *   *           *           **      *      *      **      *      *    *  **      **          * |" << endl;
    cout << "|         *  *       *   *    *           *    *     *         *           **      *      *      **      *       *   *  **      **          * |" << endl;
    cout << "|         *  *        *  *   *             *   *       *       *           **      *      *      **      *        *  *  **      **          * |" << endl;
    cout << "| *********  *         * *  *               *  *         *     *           **      *      *  **********  *         * *  **********  ********* |" << endl;
    cout << "|                                                                                                                                             |" << endl;
    cout << "*---------------------------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "                                                         PRESS ENTER TO START!                                                              \n";
    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 13)
                break; // 13 = Enter
        }
    }
}

// Global variables
bool gameOver = false;
int score = 0;
int level = 1; // NUEVO: control de nivel *cambiar a ingles

COORD obstacles[MAX_OBSTACLES]; // NUEVO: arreglo para los obstáculos *cambiar a ingles
int activeObstacleCount = 0;    // NUEVO: número actual de obstáculos*cambiar a ingles

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void initGame()
{
    system("cls");
    score = 0;
    gameOver = false;
    initSnake();
    initFood();
    ShowConsoleCursor(false);
}

void render()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    COORD head = getSnakeHead();
    COORD food = getFoodPos();
    COORD body[100];
    int length;
    getSnakeBody(body, &length);

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

                bool isObstacle = false;
                for (int o = 0; o < activeObstacleCount; o++)
                {
                    if (j == obstacles[o].X && i == obstacles[o].Y)
                    {
                        cout << "$";
                        isObstacle = true;
                        break;
                    }
                }

                if (!tailPart && !isObstacle)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << "\n\nScore: " << score << "  Level: " << level << endl;
}

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

void gameLogic()
{
    COORD head = getSnakeHead();
    for (int i = 0; i < activeObstacleCount; i++)
    {
        if (head.X == obstacles[i].X && head.Y == obstacles[i].Y)
        {
            gameOver = true;
            return;
        }
    }

    if (checkCollision())
        gameOver = true;

    if (checkEatFood(getFoodPos()))
    {
        score += 10;
        spawnFood();
        increaseSnakeLength();

        if (score >= 50 && level == 1)
        {
            level = 2;
            configurationLevel2();
            for (int i = 0; i < obstacleCount; i++)
                obstacles[i] = level2Obstacles[i];
            activeObstacleCount = obstacleCount;
            initGame();
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {width / 2 - 5, height / 2});
            cout << "LEVEL 2!";
            Sleep(2000);
        }
    }
}

int main()
{
    srand(time(0));
    showStartMenu();
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

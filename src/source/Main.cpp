#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/Snake.h"
#include "../headers/Food.h"
#include "../headers/ConfigurationLevel2.h"
#include "../headers/ConfigurationLevel3.h"

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
    cout << "                                                      PRESS SPACE FOR HOW TO PLAY!                                                          \n";
    cout << "                                                      PRESS X FOR EXIT THE GAME :(                                                          \n";
}
void showHowToPlayMenu()
{
    system("cls");
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "|                                                                                                                            |" << endl;
    cout << "| *       *     ******     **       **     ***********     ******        *********    **              ***      **         ** |" << endl;
    cout << "| *       *   **      **   **       **         **        **      **      **       **  **             **  **     **       **  |" << endl;
    cout << "| *       *  **        **  **       **         **       **        **     **       **  **            **    **     **     **   |" << endl;
    cout << "| *********  **        **  **   *   **         **       **        **     **********   **           **********      **  **    |" << endl;
    cout << "| *       *  **        **  **  ***  **         **       **        **     **           **           **      **        **      |" << endl;
    cout << "| *       *  **        **  ** ** ** **         **       **        **     **           **           **      **        **      |" << endl;
    cout << "| *       *   **      **   ***********         **        **      **      **           **           **      **        **      |" << endl;
    cout << "| *       *     ******     ***     ***         **          ******        **           ***********  **      **        **      |" << endl;
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "                                                        *---------*                                                           " << endl;
    cout << "                                                        |CONTROLS:|                                                        \n";
    cout << "                                                        *---------*                                                           " << endl;
    cout << "                                                       W - MOVE UP                                                         \n";
    cout << "                                                       A - MOVE LEFT                                                       \n";
    cout << "                                                       S - MOVE DOWN                                                       \n";
    cout << "                                                       D - MOVE RIGHT                                                      \n";
    cout << "                                                                                                                           \n";
    cout << "                                          GOAL: EAT TO GROW MORE AD SURPASS THE LEVELS!                                    \n";
    cout << "                                                                                                                           \n";
    cout << "                                         GAME OVER: IF YOU HIT YOUR OWN TAIL OR THE WALLS!                                 \n";
    cout << "                                                                                                                           \n";
    cout << "                                                 PRESS O TO RETURN TO THE MENU.                                            \n";
}

// Global variables
bool gameOver = false;
int score = 0;
int level = 1;

COORD obstacles[MAX_OBSTACLES];
int activeObstacleCount = 0;

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
    score = 0; // Just change it for testing purposes
    gameOver = false;
    initSnake();
    initFood();
    ShowConsoleCursor(false);
}

void render()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    for (int i = 0; i < GAME_WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    COORD head = getSnakeHead();
    COORD food = getFoodPos();
    COORD body[MAX_SNAKE_LENGTH];
    int length;
    getSnakeBody(body, &length);

    for (int i = 0; i < GAME_HEIGHT; i++)
    {
        for (int j = 0; j < GAME_WIDTH; j++)
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

            if (j == GAME_WIDTH - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < GAME_WIDTH + 2; i++)
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
        score += POINTS_PER_FOOD;
        spawnFood();
        increaseSnakeLength();

        if (score >= POINTS_FOR_LEVEL_2 && level == 1)
        {
            level = 2;
            configurationLevel2();
            for (int i = 0; i < obstacleCountlevel2; i++)
                obstacles[i] = level2Obstacles[i];
            activeObstacleCount = obstacleCountlevel2;
            initGame();
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 5, GAME_HEIGHT / 2});
            cout << "LEVEL 2!";
            Sleep(2000);

            
        }

        if (score >= POINTS_FOR_LEVEL_3 && level == 2)
            {
                level = 3;
                configurationLevel3();
                for (int i = 0; i < obstacleCountlevel3; i++)
                    obstacles[i] = level3Obstacles[i];
                activeObstacleCount = obstacleCountlevel3;
                initGame();
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 5, GAME_HEIGHT / 2});
                cout << "LEVEL 3!";
                Sleep(2000);
            }
            
    }
}

int main()
{
    srand(time(0));

    bool inMainMenu = true; // The game is initialized in the Main Menu

    while (inMainMenu)
    {
        showStartMenu(); // This displays the start menu

        // Wait for the user to press ENTER, SPACE, or X
        while (true)
        {
            if (_kbhit())
            {
                char key = _getch();
                if (key == 13) // KEY ENTER
                {
                    inMainMenu = false;
                    break; // Start the game
                }
                else if (key == ' ') // KEY SPACE
                {
                    showHowToPlayMenu();

                    // Wait for 'O' to return to the main menu
                    while (true)
                    {
                        if (_kbhit())
                        {
                            char subKey = _getch();
                            if (subKey == 'o' || subKey == 'O') // KEY O
                                break;                          // Return to the main menu
                        }
                    }

                    break; // Exit How To Play and return to start menu
                }
                else if (key == 'x' || key == 'X') // KEY X
                {
                    exit(0); // Exit the game
                }
            }
        }
    }

    initGame();

    while (!gameOver)
    {
        render();
        Sleep(GAME_SPEED);
        input();
        gameLogic();
    }
    cout << "End of the Game :(" << endl;
    return 0;
}
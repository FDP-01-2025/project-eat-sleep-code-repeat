#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "../headers/Snake.h"
#include "../headers/Food.h"
#include "../headers/PowerUps.h"
#include "../headers/ConfigurationLevel2.h"
#include "../headers/ConfigurationLevel3.h"
#include "../headers/Player.h"

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
    cout << "                                                      PRESS L FOR LEVEL SELECTOR!                                                          \n";
    cout << "                                                      PRESS H FOR HIGH SCORES!                                                             \n";
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

void showLevelSelectorMenu()
{
    system("cls");
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "|                                                                                                                            |" << endl;
    cout << "| *       *     ******     **       **     ******     **             ***********     ******        *********    **       ** |" << endl;
    cout << "| *       *   **      **   **       **   **      **   **                 **        **      **      **       **  **       ** |" << endl;
    cout << "| *       *  **        **  **       **  **        **  **                 **       **        **     **       **  **       ** |" << endl;
    cout << "| *       *  **        **  **       **  **        **  **                 **       **        **     **********   **       ** |" << endl;
    cout << "| *       *  **        **  **       **  **        **  **                 **       **        **     **           **       ** |" << endl;
    cout << "| *       *  **        **  **       **  **        **  **                 **       **        **     **           **       ** |" << endl;
    cout << "| *       *   **      **    **     **    **      **   **                 **        **      **      **            **     **  |" << endl;
    cout << "| *********     ******        *****        ******     ***********        **          ******        **             *******   |" << endl;
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "                                                                                                                           \n";
    cout << "                                                    *-----------------*                                                     \n";
    cout << "                                                    |SELECTOR DE NIVEL:|                                                   \n";
    cout << "                                                    *-----------------*                                                     \n";
    cout << "                                                                                                                           \n";
    cout << "                                                      PRESS 1 FOR LEVEL 1                                                  \n";
    cout << "                                                      PRESS 2 FOR LEVEL 2                                                  \n";
    cout << "                                                      PRESS 3 FOR LEVEL 3                                                  \n";
    cout << "                                                                                                                           \n";
    cout << "                                                    PRESS O TO RETURN TO MENU                                              \n";
}

// Global variables
bool gameOver = false;
int score = 0;
int level = 1;
string playerName;

COORD obstacles[MAX_OBSTACLES];
int activeObstacleCount = 0;

int currentGameSpeed = GAME_SPEED;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void setupLevel(int selectedLevel)
{
    level = selectedLevel;
    activeObstacleCount = 0; // Reset obstacles

    switch (selectedLevel)
    {
    case 1:
        // No reset score here if you want to keep it persistent
        break;
    case 2:
        configurationLevel2();
        for (int i = 0; i < obstacleCountlevel2; i++)
            obstacles[i] = level2Obstacles[i];
        activeObstacleCount = obstacleCountlevel2;
        break;
    case 3:
        configurationLevel3();
        for (int i = 0; i < obstacleCountlevel3; i++)
            obstacles[i] = level3Obstacles[i];
        activeObstacleCount = obstacleCountlevel3;
        break;
    }
}

void initGame()
{
    system("cls");
    // Don't reset score or level here - they should be preserved
    gameOver = false;
    initSnake();
    initFood();
    initPowerUps();
    ShowConsoleCursor(false);
}

void resetSnakeOnly()
{
    // Reset only the snake, keep score and level
    initSnake();
    initFood();
    initPowerUps();
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
    cout << "\n\nPlayer: " << playerName << "  Score: " << score << "  Level: " << level << "\n";

    // Show active effect message
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD messagePos = {0, GAME_HEIGHT + 4};

    // Clear message line
    SetConsoleCursorPosition(hConsole, messagePos);
    cout << string(GAME_WIDTH, ' ');

    if (showingMessage)
    {
        SetConsoleCursorPosition(hConsole, messagePos);

        if (activeEffectMessage.find("BOOST") != string::npos)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        else if (activeEffectMessage.find("REDUCED") != string::npos)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        }
        else if (activeEffectMessage.find("2x") != string::npos)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }

        cout << activeEffectMessage;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
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
        int pointsEarned = POINTS_PER_FOOD;

        // Apply 2x multiplier if active
        if (doubleScoreActive)
        {
            pointsEarned *= 2;
        }

        score += pointsEarned;
        spawnFood();
        increaseSnakeLength();

        // Check for level progression - only check the immediate next level
        if (level == 1 && score >= POINTS_FOR_LEVEL_2)
        {
            level = 2;
            configurationLevel2();
            for (int i = 0; i < obstacleCountlevel2; i++)
                obstacles[i] = level2Obstacles[i];
            activeObstacleCount = obstacleCountlevel2;

            // Reset only the snake, keep the score
            resetSnakeOnly();

            // Clear screen and show level message
            system("cls");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 5, GAME_HEIGHT / 2});
            cout << "LEVEL 2!";
            Sleep(2000);
        }
        else if (level == 2 && score >= POINTS_FOR_LEVEL_3)
        {
            level = 3;
            configurationLevel3();
            for (int i = 0; i < obstacleCountlevel3; i++)
                obstacles[i] = level3Obstacles[i];
            activeObstacleCount = obstacleCountlevel3;

            // Reset only the snake, keep the score
            resetSnakeOnly();

            // Clear screen and show level message
            system("cls");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 5, GAME_HEIGHT / 2});
            cout << "LEVEL 3!";
            Sleep(2000);
        }
    }
}

int main()
{
    srand(time(0));

    // Pedir nombre del jugador
    system("cls");
    do
    {
        system("cls"); // Limpia la pantalla
        cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
        cout << "|                                                     ENTER YOUR NAME                                                        |" << endl;
        cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;

        if (!playerName.empty())
        {
            cout << "\nName cannot be empty. Please enter a valid name.\n\n";
        }

        cout << "\nPlease enter your name: ";
        getline(cin, playerName);
    } while (playerName.empty());
    bool inMainMenu = true;
    int selectedLevel = 1; // Default level

    while (inMainMenu)
    {
        showStartMenu();

        while (true)
        {
            if (_kbhit())
            {
                char key = _getch();
                if (key == 13) // KEY ENTER
                {
                    inMainMenu = false;
                    break;
                }
                else if (key == ' ') // KEY SPACE
                {
                    showHowToPlayMenu();

                    while (true)
                    {
                        if (_kbhit())
                        {
                            char subKey = _getch();
                            if (subKey == 'o' || subKey == 'O')
                                break;
                        }
                    }
                    break;
                }
                else if (key == 'l' || key == 'L') // KEY L for Level Selector
                {
                    showLevelSelectorMenu();

                    while (true)
                    {
                        if (_kbhit())
                        {
                            char levelKey = _getch();
                            if (levelKey == '1')
                            {
                                selectedLevel = 1;
                                inMainMenu = false;
                                break;
                            }
                            else if (levelKey == '2')
                            {
                                selectedLevel = 2;
                                inMainMenu = false;
                                break;
                            }
                            else if (levelKey == '3')
                            {
                                selectedLevel = 3;
                                inMainMenu = false;
                                break;
                            }
                            else if (levelKey == 'o' || levelKey == 'O')
                            {
                                break; // Return to main menu
                            }
                        }
                    }
                    if (!inMainMenu)
                        break; // Exit if level was selected
                    break;     // Return to main menu if 'O' was pressed
                }
                else if (key == 'h' || key == 'H') // KEY H for High Scores
                {
                    Player::showHighScores();
                    break;
                }
                else if (key == 'x' || key == 'X') // KEY X
                {
                    exit(0);
                }
            }
        }
    }

    // Setup the selected level before starting the game
    setupLevel(selectedLevel);
    initGame();

    // Show level start message
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 10, GAME_HEIGHT / 2});
    cout << "STARTING LEVEL " << selectedLevel << "!";
    Sleep(1500);

    while (!gameOver)
    {
        render();
        renderPowerUps();
        Sleep(currentGameSpeed);
        input();
        gameLogic();
        spawnPowerUp();
        clearExpiredPowerUps();
        checkPowerUpCollision(getSnakeHead(), &score, &currentGameSpeed);
    }

    // Guardar los datos del jugador
    Player currentPlayer;
    currentPlayer.name = playerName;
    currentPlayer.score = score;
    currentPlayer.level = level;
    Player::saveToFile(currentPlayer);

    // Mostrar mensaje de fin de juego con el puntaje
    system("cls");
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "|                                                     GAME OVER                                                              |" << endl;
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "\n\nPlayer: " << playerName << endl;
    cout << "Final Score: " << score << endl;
    cout << "Level Reached: " << level << endl;
    cout << "\nPress any key to exit...";
    _getch();

    return 0;
}
#include "../headers/GameManager.h"
#include "../headers/ConfigurationLevel1.h"
#include "../headers/ConfigurationLevel2.h"
#include "../headers/ConfigurationLevel3.h"
#include "../headers/Player.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

GameManager::GameManager()
{
    gameOver = false;
    score = 0;
    level = 1;
    activeObstacleCount = 0;
    currentGameSpeed = GAME_SPEED;
}

COORD obstacles[MAX_OBSTACLES];
int activeObstacleCount = 0;

void GameManager::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void GameManager::setupLevel(int selectedLevel)
{
    level = selectedLevel;
    activeObstacleCount = 0;

    switch (selectedLevel)
    {
    case 1:
        configurationLevel1();
        for (int i = 0; i < obstacleCountLevel1; i++)
            obstacles[i] = level1Obstacles[i];
        activeObstacleCount = obstacleCountLevel1;
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

void GameManager::initGame()
{
    system("cls");
    score = 0;
    gameOver = false;
    initSnake();
    initFood();
    initPowerUps();
    ShowConsoleCursor(false);

    originalGameSpeed = GAME_SPEED;
    speedEffectActive = false;
}

void GameManager::resetSnakeOnly()
{
    initSnake();
    initFood();
    initPowerUps();
}

void GameManager::render()
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
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
                        cout << "$";
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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

void GameManager::input()
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

void GameManager::gameLogic()
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

        if (doubleScoreActive)
        {
            pointsEarned *= 2;
        }

        score += pointsEarned;
        spawnFood();
        increaseSnakeLength();

        // Se eliminó completamente la lógica de progresión automática de niveles
        // Ahora el jugador permanece en el nivel seleccionado independientemente de los puntos
    }
}

void GameManager::runGameLoop()
{
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
}

void GameManager::endGame()
{
    Player currentPlayer;
    currentPlayer.name = playerName;
    currentPlayer.score = score;
    currentPlayer.level = level;
    Player::saveToFile(currentPlayer);

    system("cls");
    cout << "*------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "| **********     ***     **         **  **********     *******   **              ** **********  ******       _________   |" << endl;
    cout << "| **            **  **   ***       ***  **            **     **   **            **  **          *     **     |       |   |" << endl;
    cout << "| **           **    **  ** *      ***  **           **       **   **          **   **          *     **     |       |   |" << endl;
    cout << "| **  ******   **    **  **  *    * **  **           **       **    **        **    **          *     **     |  o o  |   |" << endl;
    cout << "| **      **   ********  **   *  *  **  **********   **       **     **      **     **********  ******       |   >   |   |" << endl;
    cout << "| **      **   **    **  **    *    **  **           **       **      **    **      **          *     *      | ----- |   |" << endl;
    cout << "| **      **   **    **  **         **  **            **     **        **  **       **          *      *     |       |   |" << endl;
    cout << "| **********   **    **  **         **  **********     *******           **         **********  *       *    |_______|   |" << endl;
    cout << "*------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "\n\nPlayer: " << playerName << endl;
    cout << "Final Score: " << score << endl;
    cout << "Level Reached: " << level << endl;
    cout << "\nPress any key to exit...";
    _getch();
}
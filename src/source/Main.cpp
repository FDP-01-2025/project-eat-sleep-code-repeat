#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/Snake.h"
#include "../headers/Food.h"
#include "../headers/ConfigurationLevel2.h"

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

void showLevelSelectionMenu()
{
    system("cls");
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "|                                                                                                                            |" << endl;
    cout << "| **          **********  **       **  **********  **           ********  **********  **          **********  *********** |" << endl;
    cout << "| **          **          **       **  **          **           **        **          **          **          **         |" << endl;
    cout << "| **          **          **       **  **          **           **        **          **          **          **         |" << endl;
    cout << "| **          **          **       **  **          **           **        **          **          **          **         |" << endl;
    cout << "| **          **********  **       **  **********  **           ********  **********  **          **********  ********** |" << endl;
    cout << "| **          **          **       **  **          **                 **  **          **          **          **         |" << endl;
    cout << "| **          **          **       **  **          **                 **  **          **          **          **         |" << endl;
    cout << "| **          **           **     **   **          **                 **  **          **          **          **         |" << endl;
    cout << "| **********  **********    *******    **********  **********  ********  **********  **********  **********  *********** |" << endl;
    cout << "|                                                                                                                            |" << endl;
    cout << "*----------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "                                                                                                                           " << endl;
    cout << "                                               SELECT YOUR STARTING LEVEL:                                                 " << endl;
    cout << "                                                                                                                           " << endl;
    cout << "                                                   1 - LEVEL 1 (EASY)                                                    " << endl;
    cout << "                                                   2 - LEVEL 2 (OBSTACLES)                                               " << endl;
    cout << "                                                                                                                           " << endl;
    cout << "                                              PRESS THE NUMBER OF YOUR CHOICE                                             " << endl;
    cout << "                                                   OR ESC TO GO BACK                                                     " << endl;
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
int selectedLevel = 1; // Nueva variable para el nivel seleccionado

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
    gameOver = false;
    level = selectedLevel; // Establecer el nivel al nivel seleccionado
    
    // Configurar score según el nivel seleccionado
    if (selectedLevel == 1) {
        score = 0; // Empezar desde 0 en nivel 1
    } else if (selectedLevel == 2) {
        score = 0; // Empezar desde 0 en nivel 2 también
    }
    
    // IMPORTANTE: Reiniciar la serpiente ANTES de configurar obstáculos
    initSnake(); // Esto reinicia la serpiente a su tamaño inicial
    
    // Configurar obstáculos según el nivel seleccionado
    if (selectedLevel == 2) {
        configurationLevel2();
        for (int i = 0; i < obstacleCount; i++)
            obstacles[i] = level2Obstacles[i];
        activeObstacleCount = obstacleCount;
    } else {
        activeObstacleCount = 0; // Sin obstáculos en nivel 1
    }
    
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

        // Solo avanzar de nivel si empezamos en nivel 1 Y estamos actualmente en nivel 1
        if (selectedLevel == 1 && score >= POINTS_FOR_LEVEL_2 && level == 1)
        {
            level = 2;
            
            // Guardar el score actual antes de reiniciar
            int currentScore = score;
            
            // Reiniciar la serpiente pero mantener el score
            initSnake(); // Reinicia la serpiente a tamaño pequeño
            score = currentScore; // Restaurar el score
            
            // Configurar obstáculos del nivel 2
            configurationLevel2();
            for (int i = 0; i < obstacleCount; i++)
                obstacles[i] = level2Obstacles[i];
            activeObstacleCount = obstacleCount;
            
            // Generar nueva comida después de reiniciar
            initFood();
            
            // Mostrar mensaje de nivel 2
            system("cls");
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 5, GAME_HEIGHT / 2});
            cout << "LEVEL 2!";
            Sleep(2000);
        }
    }
}

int main()
{
    srand(time(0));

    bool inMainMenu = true;

    while (inMainMenu)
    {
        showStartMenu();

        while (true)
        {
            if (_kbhit())
            {
                char key = _getch();
                if (key == 13) // ENTER - Mostrar menú de selección de nivel
                {
                    bool inLevelMenu = true;
                    
                    while (inLevelMenu)
                    {
                        showLevelSelectionMenu();
                        
                        while (true)
                        {
                            if (_kbhit())
                            {
                                char levelKey = _getch();
                                if (levelKey == '1')
                                {
                                    selectedLevel = 1;
                                    inLevelMenu = false;
                                    inMainMenu = false;
                                    break;
                                }
                                else if (levelKey == '2')
                                {
                                    selectedLevel = 2;
                                    inLevelMenu = false;
                                    inMainMenu = false;
                                    break;
                                }
                                else if (levelKey == 27) // ESC - Volver al menú principal
                                {
                                    inLevelMenu = false;
                                    break;
                                }
                            }
                        }
                    }
                    
                    if (!inMainMenu) break; // Salir del menú principal si se seleccionó un nivel
                }
                else if (key == ' ') // SPACE - Mostrar cómo jugar
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
                else if (key == 'x' || key == 'X') // X - Salir del juego
                {
                    exit(0);
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
#include "../headers/MenuManager.h"
#include "../headers/Player.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;
// Constructor: initializes default level
MenuManager::MenuManager()
{
    selectedLevel = 1;
}
// Returns the player's name
string MenuManager::getPlayerNameValue() const
{
    return playerName;
}
// Displays the start menu with ASCII art and instructions
void MenuManager::showStartMenu()
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
    cout << "                                                      PRESS SPACE FOR HOW TO PLAY!                                                          \n";
    cout << "                                                      PRESS L FOR LEVEL SELECTOR!                                                           \n";
    cout << "                                                      PRESS H FOR HIGH SCORES!                                                              \n";
    cout << "                                                      PRESS X FOR EXIT THE GAME :(                                                          \n";
}
// Displays how-to-play instructions
void MenuManager::showHowToPlayMenu()
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
// Displays level selection screen
void MenuManager::showLevelSelectorMenu()
{
    system("cls");
    cout << "*----------------------------------------------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "|                                                                                                                                                                |" << endl;
    cout << "| **         **********   **            ** **********  **          *********  **********   **        **********  **********  **********   *******    ******      |" << endl;
    cout << "| **         **            **          **  **          **          *          **           **        **          **             **       **     **   *     **    |" << endl;
    cout << "| **         **             **        **   **          **          *          **           **        **          **             **      **       **  *     **    |" << endl;
    cout << "| **         **********      **      **    **********  **          *********  **********   **        *********   **             **      **       **  ******      |" << endl;
    cout << "| **         **               **    **     **          **                  *  **           **        **          **             **      **       **  *     **    |" << endl;
    cout << "| **         **                **  **      **          **                  *  **           **        **          **             **       **     **   *      **   |" << endl;
    cout << "| *********  **********          **        **********  *********   *********  **********   ********* **********  **********     **        *******    *       **  |" << endl;
    cout << "*----------------------------------------------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << "                                                                                                                                                               \n";
    cout << "                                                                 *----------------*                                                                            \n";
    cout << "                                                                 |     LEVELS:    |                                                                            \n";
    cout << "                                                                 *----------------*                                                                            \n";
    cout << "                                                                                                                                                               \n";
    cout << "                                                                 PRESS 1 FOR LEVEL 1                                                                           \n";
    cout << "                                                                 PRESS 2 FOR LEVEL 2                                                                           \n";
    cout << "                                                                 PRESS 3 FOR LEVEL 3                                                                           \n";
    cout << "                                                                                                                                                               \n";
    cout << "                                                              PRESS O TO RETURN TO MENU                                                                        \n";
}
// Prompts user for player name
void MenuManager::getPlayerName()
{
    system("cls");
    do
    {
        system("cls");
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
}
// Handles logic for the main menu loop
void MenuManager::handleMainMenu()
{
    bool inMainMenu = true;

    while (inMainMenu)
    {
        showStartMenu();

        while (true)
        {
            if (_kbhit())
            {
                char key = _getch();
                if (key == 13)
                { // ENTER
                    inMainMenu = false;
                    break;
                }
                else if (key == ' ')
                { // SPACE
                    handleHowToPlayMenu();
                    break;
                }
                else if (key == 'l' || key == 'L')
                { // L for Level Selector
                    handleLevelSelectorMenu();
                    // After exiting the level selector, exit the main menu.
                    inMainMenu = false;
                    break;
                }
                else if (key == 'h' || key == 'H')
                { // H for High Scores
                    Player::showHighScores();
                    break;
                }
                else if (key == 'x' || key == 'X')
                { // X for exit
                    exit(0);
                }
            }
        }
    }
}
// Handles logic for the how-to-play menu
void MenuManager::handleHowToPlayMenu()
{
    showHowToPlayMenu();

    while (true)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'o' || key == 'O')
            {
                break;
            }
        }
    }
}
// Handles logic for selecting level
void MenuManager::handleLevelSelectorMenu()
{
    bool levelSelected = false;

    while (!levelSelected)
    {
        showLevelSelectorMenu();

        while (true)
        {
            if (_kbhit())
            {
                char key = _getch();
                if (key == '1')
                {
                    selectedLevel = 1;
                    levelSelected = true;
                    break;
                }
                else if (key == '2')
                {
                    selectedLevel = 2;
                    levelSelected = true;
                    break;
                }
                else if (key == '3')
                {
                    selectedLevel = 3;
                    levelSelected = true;
                    break;
                }
                else if (key == 'o' || key == 'O')
                {
                    // Return to main menu without changing level
                    return;
                }
            }
        }
    }
}
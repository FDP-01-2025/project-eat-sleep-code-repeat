#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../headers/GameManager.h"
#include "../headers/MenuManager.h"

using namespace std;

int main() {
    srand(time(0));
    
    // Initialize managers
    MenuManager menuManager;
    GameManager gameManager;
    
    // Get player name
    menuManager.getPlayerName();
    
    // Handle main menu navigation
    menuManager.handleMainMenu();
    
    // Set player name and selected level in game manager
    gameManager.setPlayerName(menuManager.getPlayerNameValue());
    gameManager.setupLevel(menuManager.getSelectedLevel());
    
    // Initialize and start the game
    gameManager.initGame();
    
    // Show level start message
    system("cls");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {GAME_WIDTH / 2 - 10, GAME_HEIGHT / 2});
    cout << "STARTING LEVEL " << menuManager.getSelectedLevel() << "!";
    Sleep(1500);
    
    // Run the game loop
    gameManager.runGameLoop();
    
    // Handle game end
    gameManager.endGame();
    
    return 0;
}
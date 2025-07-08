#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <windows.h>
#include <string>
#include "Snake.h"
#include "Food.h"
#include "PowerUps.h"
#include "ConfigurationLevel1.h"
#include "ConfigurationLevel2.h"
#include "ConfigurationLevel3.h"

class GameManager
{
private:
    bool gameOver;
    int score;
    int level;
    std::string playerName;
    COORD obstacles[MAX_OBSTACLES]; // Stores current level's obstacles
    int activeObstacleCount;        // Keeps track of how many obstacles are currently used
    int currentGameSpeed;           // Controls the current speed of the game loop (lower = faster)

public:
    GameManager();

    // Game state management
    void initGame();
    void resetSnakeOnly();
    void setupLevel(int selectedLevel);

    // Game loop functions
    void render();
    void input();
    void gameLogic();
    int getCurrentLevel() const { return level; }

    // Utility functions
    void ShowConsoleCursor(bool showFlag);

    // Getters and setters
    bool isGameOver() const { return gameOver; }
    int getScore() const { return score; }
    int getLevel() const { return level; }
    std::string getPlayerName() const { return playerName; }
    void setPlayerName(const std::string &name) { playerName = name; }
    void setGameOver(bool over) { gameOver = over; }

    // Game control
    void runGameLoop();
    void endGame();
};

#endif
#include "../headers/PowerUps.h"
#include <stdlib.h>
#include <iostream>
#include <string>

PowerUp activePowerUps[MAX_ACTIVE_POWERUPS]; // Array for active power-ups
time_t lastSpawnTime = 0;                    // Last spawn time
bool doubleScoreActive = false;              // Double score state
time_t doubleScoreEndTime = 0;               // Double score expiration

bool speedChanged = false;
time_t effectEndTime = 0;
std::string currentEffectMessage = "";

// Custom color definitions
#define DARK_RED BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY
#define FOREST_GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define MUSTARD_YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY

// Initialize power-up system
void initPowerUps()
{
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        activePowerUps[i].active = false;
    }
    lastSpawnTime = time(NULL);
    doubleScoreActive = false;
}

// Spawn new power-ups when conditions are met
void spawnPowerUp()
{
    time_t currentTime = time(NULL);

    // Check if ready to spawn new power-up (12 second interval)
    if (difftime(currentTime, lastSpawnTime) < POWERUP_SPAWN_INTERVAL)
    {
        return;
    }

    // Count active power-ups
    int activeCount = 0;
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active)
            activeCount++;
    }

    // Don't spawn if we already have max active power-ups
    if (activeCount >= MAX_ACTIVE_POWERUPS)
    {
        return;
    }

    // Find empty slot and spawn new power-up
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (!activePowerUps[i].active)
        {
            // Generate random position
            bool validPosition = false;
            COORD newPos;

            while (!validPosition)
            {
                newPos.X = rand() % GAME_WIDTH;
                newPos.Y = rand() % GAME_HEIGHT;
                validPosition = true;
            }

            activePowerUps[i].position = newPos;
            activePowerUps[i].type = (PowerUpType)(rand() % PU_TYPE_COUNT);
            activePowerUps[i].active = true;
            activePowerUps[i].spawnTime = currentTime;

            lastSpawnTime = currentTime;
            break;
        }
    }
}

// Check if snake head collides with any power-up
void checkPowerUpCollision(COORD headPos, int *score, int *gameSpeed)
{
    time_t currentTime = time(NULL);

    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active &&
            headPos.X == activePowerUps[i].position.X &&
            headPos.Y == activePowerUps[i].position.Y)
        {

            // Apply power-up effect
            switch (activePowerUps[i].type)
            {
            case PU_SPEED_UP:
                *gameSpeed -= SPEED_CHANGE_AMOUNT;
                if (*gameSpeed < 20)
                    *gameSpeed = 20;
                speedChanged = true;
                currentEffectMessage = "SPEED INCREASED!";
                break;

            case PU_SPEED_DOWN:
                *gameSpeed += SPEED_CHANGE_AMOUNT;
                if (*gameSpeed > 150)
                    *gameSpeed = 150;
                speedChanged = true;
                currentEffectMessage = "SPEED DECREASED!";
                break;

            case PU_DOUBLE_SCORE:
                doubleScoreActive = true;
                currentEffectMessage = "2x SCORE ACTIVATED!";
                break;
            }

            effectEndTime = currentTime + 2;
            activePowerUps[i].active = false;
        }
    }

    if (currentTime >= effectEndTime) {
        currentEffectMessage = "";
        speedChanged = false;
    }
    
    // Check if double score has expired
    if (doubleScoreActive && currentTime >= doubleScoreEndTime) {
        doubleScoreActive = false;
        currentEffectMessage = "2x SCORE ENDED!";
        effectEndTime = currentTime + 2;
    }
}

// Render all active power-ups
void renderPowerUps()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active)
        {
            SetConsoleCursorPosition(hConsole, activePowerUps[i].position);

            // Set color and symbol based on power-up type
            switch (activePowerUps[i].type)
            {
            case PU_SPEED_UP:
                SetConsoleTextAttribute(hConsole, FOREST_GREEN);
                std::cout << "^";
                break;

            case PU_SPEED_DOWN:
                SetConsoleTextAttribute(hConsole, DARK_RED);
                std::cout << "v";
                break;

            case PU_DOUBLE_SCORE:
                SetConsoleTextAttribute(hConsole, MUSTARD_YELLOW);
                std::cout << "2x";
                break;
            }
        }
    }

    // Reset to default console color
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

// Remove power-ups that have been on screen too long
void clearExpiredPowerUps()
{
    time_t currentTime = time(NULL);

    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active &&
            difftime(currentTime, activePowerUps[i].spawnTime) >= POWERUP_DURATION)
        {
            activePowerUps[i].active = false;
        }
    }
}
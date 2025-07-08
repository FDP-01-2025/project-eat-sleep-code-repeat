#include "../headers/PowerUps.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

extern COORD obstacles[MAX_OBSTACLES];
extern int activeObstacleCount;

PowerUp activePowerUps[MAX_ACTIVE_POWERUPS]; // Array for active power-ups
time_t lastSpawnTime = 0;                    // Last spawn time

// POWER UP | 2x Score
bool doubleScoreActive = false; // Double score state
time_t doubleScoreEndTime = 0;  // Double score expiration

// MESSAGE | Power Up
std::string activeEffectMessage = "";
time_t messageEndTime = 0;
bool showingMessage = false;

// POWER UP | Speed
int originalGameSpeed = GAME_SPEED;
bool speedEffectActive = false;
time_t speedEffectEndTime = 0;

// POWER UP | Freeze
bool freezeActive = false;
time_t freezeEndTime = 0;
int frozenGameSpeed = 0;

bool isPositionValidForPowerUp(COORD pos)
{
    // 1. Avoiding game edges
    if (pos.X <= 0 || pos.X >= GAME_WIDTH - 1 || pos.Y <= 0 || pos.Y >= GAME_HEIGHT - 1)
    {
        return false;
    }

    // 2. Avoid obstacles of the current level
    for (int i = 0; i < activeObstacleCount; i++)
    {
        if (pos.X == obstacles[i].X && pos.Y == obstacles[i].Y)
        {
            return false;
        }
    }

    // 3. Avoid snake body
    COORD snakeBody[MAX_SNAKE_LENGTH];
    int snakeLength;
    getSnakeBody(snakeBody, &snakeLength);
    for (int i = 0; i < snakeLength; i++)
    {
        if (pos.X == snakeBody[i].X && pos.Y == snakeBody[i].Y)
        {
            return false;
        }
    }

    // 4. Avoid food position
    COORD foodPos = getFoodPos();
    if (pos.X == foodPos.X && pos.Y == foodPos.Y)
    {
        return false;
    }

    // 5. Avoid other active power-ups
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active &&
            pos.X == activePowerUps[i].position.X &&
            pos.Y == activePowerUps[i].position.Y)
        {
            return false;
        }
    }

    return true;
}

void initPowerUps()
{
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        activePowerUps[i].active = false;
    }
    lastSpawnTime = time(NULL);
    doubleScoreActive = false;
}

void spawnPowerUp()
{
    time_t currentTime = time(NULL);

    // 1. Check if enough time has passed since last spawn
    if (difftime(currentTime, lastSpawnTime) < POWERUP_SPAWN_INTERVAL)
    {
        return;
    }

    // 2. Count currently active power-ups
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

    // 3. Find an empty slot for new power-up
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (!activePowerUps[i].active)
        {
            bool validPosition = false;
            COORD newPos;
            int attempts = 0;
            const int MAX_ATTEMPTS = 100; // Increased from 50 for better reliability

            // 4. Keep trying random positions until valid or max attempts reached
            while (!validPosition && attempts < MAX_ATTEMPTS)
            {
                attempts++;

                // Generate random position within playable area (avoiding borders)
                newPos.X = 1 + rand() % (GAME_WIDTH - 2);
                newPos.Y = 1 + rand() % (GAME_HEIGHT - 2);
                validPosition = true; // Assume valid until proven otherwise

                // 4.1 Check for snake body collision
                COORD snakeBody[MAX_SNAKE_LENGTH];
                int snakeLength;
                getSnakeBody(snakeBody, &snakeLength);
                for (int j = 0; j < snakeLength; j++)
                {
                    if (newPos.X == snakeBody[j].X && newPos.Y == snakeBody[j].Y)
                    {
                        validPosition = false;
                        break;
                    }
                }

                // 4.2 Check for food collision
                if (validPosition)
                {
                    COORD foodPos = getFoodPos();
                    if (newPos.X == foodPos.X && newPos.Y == foodPos.Y)
                    {
                        validPosition = false;
                    }
                }

                // 4.3 Check for other active power-ups
                if (validPosition)
                {
                    for (int j = 0; j < MAX_ACTIVE_POWERUPS; j++)
                    {
                        if (activePowerUps[j].active &&
                            newPos.X == activePowerUps[j].position.X &&
                            newPos.Y == activePowerUps[j].position.Y)
                        {
                            validPosition = false;
                            break;
                        }
                    }
                }

                // 4.4 Check for obstacle collision (for all three levels)
                if (validPosition && activeObstacleCount > 0)
                {
                    for (int j = 0; j < activeObstacleCount; j++)
                    {
                        if (newPos.X == obstacles[j].X && newPos.Y == obstacles[j].Y)
                        {
                            validPosition = false;
                            break;
                        }
                    }
                }
            }

            // 5. If valid position found, create the power-up
            if (validPosition)
            {
                activePowerUps[i].position = newPos;
                activePowerUps[i].type = (PowerUpType)(rand() % PU_TYPE_COUNT);
                activePowerUps[i].active = true;
                activePowerUps[i].spawnTime = currentTime;
                lastSpawnTime = currentTime;
            }
            break; // Exit after attempting to spawn one power-up
        }
    }
}

void checkPowerUpCollision(COORD headPos, int *score, int *gameSpeed)
{
    time_t currentTime = time(NULL);

    //  check if we're in a valid position (not inside obstacle)
    bool positionValid = true;
    for (int i = 0; i < activeObstacleCount; i++)
    {
        if (headPos.X == obstacles[i].X && headPos.Y == obstacles[i].Y)
        {
            positionValid = false;
            break;
        }
    }
    if (!positionValid)
        return;

    // Handle active effects expiration
    if (speedEffectActive && currentTime >= speedEffectEndTime)
    {
        *gameSpeed = originalGameSpeed;
        speedEffectActive = false;
    }

    if (freezeActive && currentTime >= freezeEndTime)
    {
        *gameSpeed = originalGameSpeed;
        freezeActive = false;
    }

    if (doubleScoreActive && currentTime >= doubleScoreEndTime)
    {
        doubleScoreActive = false;
    }

    //  Check collisions with active power-ups
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active)
        {
            //  precise collision detection
            bool collisionX = abs(headPos.X - activePowerUps[i].position.X) <= 1;
            bool collisionY = abs(headPos.Y - activePowerUps[i].position.Y) <= 1;

            if (collisionX && collisionY)
            {
                // Additional safety check
                bool safeToCollect = true;
                for (int j = 0; j < activeObstacleCount; j++)
                {
                    if (headPos.X == obstacles[j].X && headPos.Y == obstacles[j].Y)
                    {
                        safeToCollect = false;
                        break;
                    }
                }

                if (safeToCollect)
                {
                    switch (activePowerUps[i].type)
                    {
                    case PU_SPEED_UP:
                        originalGameSpeed = *gameSpeed;
                        *gameSpeed = std::max(MIN_GAME_SPEED, *gameSpeed - SPEED_CHANGE_AMOUNT);
                        activeEffectMessage = "|SPEED BOOST!|";
                        messageEndTime = currentTime + EFFECT_DURATION;
                        speedEffectEndTime = messageEndTime;
                        speedEffectActive = true;
                        showingMessage = true;
                        break;

                    case PU_SPEED_DOWN:
                        originalGameSpeed = *gameSpeed;
                        *gameSpeed = std::min(MAX_GAME_SPEED, *gameSpeed + SPEED_CHANGE_AMOUNT);
                        activeEffectMessage = "|SPEED REDUCED!|";
                        messageEndTime = currentTime + EFFECT_DURATION;
                        speedEffectEndTime = messageEndTime;
                        speedEffectActive = true;
                        showingMessage = true;
                        break;

                    case PU_DOUBLE_SCORE:
                        doubleScoreActive = true;
                        doubleScoreEndTime = currentTime + DOUBLE_SCORE_DURATION;
                        activeEffectMessage = "|2x SCORE!|";
                        messageEndTime = doubleScoreEndTime;
                        showingMessage = true;
                        break;

                    case PU_FREEZE:
                        frozenGameSpeed = *gameSpeed;
                        *gameSpeed = 0;
                        activeEffectMessage = "|FREEZE!|";
                        messageEndTime = currentTime + 7;
                        freezeEndTime = messageEndTime;
                        freezeActive = true;
                        showingMessage = true;
                        break;
                    }

                    activePowerUps[i].active = false;
                    break; // Only process one power-up per frame
                }
            }
        }
    }

    // 4. Handle message expiration
    if (showingMessage && currentTime >= messageEndTime)
    {
        activeEffectMessage = "";
        showingMessage = false;
    }
}
// Renders all active power-ups on the screen
void renderPowerUps()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active)
        {
            SetConsoleCursorPosition(hConsole, activePowerUps[i].position);
            // Choose the color and symbol based on power-up type
            switch (activePowerUps[i].type)
            {
            case PU_SPEED_UP:
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "^"; // speed boost
                break;

            case PU_SPEED_DOWN:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "v"; // slow down
                break;

            case PU_DOUBLE_SCORE:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "2x"; // double points
                break;

            case PU_FREEZE:
                SetConsoleTextAttribute(hConsole, FREEZE_COLOR);
                std::cout << "*"; // freeze effect
                break;
            }
        }
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
// Deactivates any expired power-ups based on duration
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

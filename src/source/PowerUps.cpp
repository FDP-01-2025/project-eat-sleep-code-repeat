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

bool isPositionValid(COORD pos)
{
    // Avoid edges (walls)
    if (pos.X == 0 || pos.X == GAME_WIDTH - 1 || pos.Y == 0 || pos.Y == GAME_HEIGHT - 1)
        return false;

    // Avoid obstacles
    for (int i = 0; i < activeObstacleCount; i++)
    {
        if (obstacles[i].X == pos.X && obstacles[i].Y == pos.Y)
            return false;
    }

    // Avoid snakes
    COORD snakeBody[MAX_SNAKE_LENGTH];
    int snakeLength;
    getSnakeBody(snakeBody, &snakeLength);
    for (int i = 0; i < snakeLength; i++)
    {
        if (snakeBody[i].X == pos.X && snakeBody[i].Y == pos.Y)
            return false;
    }

    // Avoid food
    COORD foodPos = getFoodPos();
    if (pos.X == foodPos.X && pos.Y == foodPos.Y)
        return false;

    // Avoid other active power-ups
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active && activePowerUps[i].position.X == pos.X && activePowerUps[i].position.Y == pos.Y)
            return false;
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

    // Check spawn interval
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
    if (activeCount >= MAX_ACTIVE_POWERUPS)
    {
        return;
    }

    // Find empty slot and spawn new power-up
    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (!activePowerUps[i].active)
        {
            bool validPosition = false;
            COORD newPos;
            int attempts = 0;
            const int MAX_ATTEMPTS = 50;

            while (!validPosition && attempts < MAX_ATTEMPTS)
            {
                attempts++;

                // Generate position avoiding borders
                newPos.X = 1 + rand() % (GAME_WIDTH - 2);
                newPos.Y = 1 + rand() % (GAME_HEIGHT - 2);
                validPosition = true;

                // 1 | Check snake collision
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

                // 2 | Check food collision
                if (validPosition)
                {
                    COORD foodPos = getFoodPos();
                    if (newPos.X == foodPos.X && newPos.Y == foodPos.Y)
                    {
                        validPosition = false;
                    }
                }

                // 3 | Check other power-ups
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

                // 4 | Check obstacles
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

            if (validPosition)
            {
                // Randomly select power-up type (now includes FREEZE)
                activePowerUps[i].position = newPos;
                activePowerUps[i].type = (PowerUpType)(rand() % PU_TYPE_COUNT);
                activePowerUps[i].active = true;
                activePowerUps[i].spawnTime = currentTime;
                lastSpawnTime = currentTime;
            }
            break;
        }
    }
}

void checkPowerUpCollision(COORD headPos, int *score, int *gameSpeed)
{
    time_t currentTime = time(NULL);

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

    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active)
        {
            bool collisionX = abs(headPos.X - activePowerUps[i].position.X) <= 1;
            bool collisionY = abs(headPos.Y - activePowerUps[i].position.Y) <= 1;

            if (collisionX && collisionY)
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
                break;
            }
        }
    }

    if (showingMessage && currentTime >= messageEndTime)
    {
        activeEffectMessage = "";
        showingMessage = false;
    }

    if (doubleScoreActive && currentTime >= doubleScoreEndTime)
    {
        doubleScoreActive = false;
    }
}

void renderPowerUps()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < MAX_ACTIVE_POWERUPS; i++)
    {
        if (activePowerUps[i].active)
        {
            SetConsoleCursorPosition(hConsole, activePowerUps[i].position);

            switch (activePowerUps[i].type)
            {
            case PU_SPEED_UP:
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "^";
                break;

            case PU_SPEED_DOWN:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "v";
                break;

            case PU_DOUBLE_SCORE:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "2x";
                break;

            case PU_FREEZE:
                SetConsoleTextAttribute(hConsole, FREEZE_COLOR);
                std::cout << "*";
                break;
            }
        }
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

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

#include "../headers/PowerUps.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

PowerUp activePowerUps[MAX_ACTIVE_POWERUPS]; // Array for active power-ups
time_t lastSpawnTime = 0;                    // Last spawn time
bool doubleScoreActive = false;              // Double score state
time_t doubleScoreEndTime = 0;               // Double score expiration

std::string activeEffectMessage = "";
time_t messageEndTime = 0;
bool showingMessage = false;

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

    if (difftime(currentTime, lastSpawnTime) < POWERUP_SPAWN_INTERVAL)
    {
        return;
    }

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
                newPos.X = rand() % GAME_WIDTH;
                newPos.Y = rand() % GAME_HEIGHT;
                validPosition = true;

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

                if (validPosition)
                {
                    COORD foodPos = getFoodPos();
                    if (newPos.X == foodPos.X && newPos.Y == foodPos.Y)
                    {
                        validPosition = false;
                    }
                }

                attempts++;
            }

            if (validPosition)
            {
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

// Check if snake head collides with any power-up
void checkPowerUpCollision(COORD headPos, int *score, int *gameSpeed)
{
    time_t currentTime = time(NULL);

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
                    *gameSpeed = std::max(MIN_GAME_SPEED, *gameSpeed - SPEED_CHANGE_AMOUNT);
                    activeEffectMessage = "|SPEED BOOST!|";
                    messageEndTime = currentTime + EFFECT_DURATION;
                    break;

                case PU_SPEED_DOWN:
                    *gameSpeed = std::min(MAX_GAME_SPEED, *gameSpeed + SPEED_CHANGE_AMOUNT);
                    activeEffectMessage = "|SPEED REDUCED!|";
                    messageEndTime = currentTime + EFFECT_DURATION;
                    break;

                case PU_DOUBLE_SCORE:
                    doubleScoreActive = true;
                    doubleScoreEndTime = currentTime + DOUBLE_SCORE_DURATION;
                    activeEffectMessage = "|2x SCORE!|";
                    messageEndTime = doubleScoreEndTime;
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

// Render all active power-ups
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
                std::cout << "^"; // Up arrow
                break;

            case PU_SPEED_DOWN:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                std::cout << "v"; // Down arrow
                break;

            case PU_DOUBLE_SCORE:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
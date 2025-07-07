#ifndef POWER_UPS_H_
#define POWER_UPS_H_

#include <windows.h>
#include <time.h>
#include <string>
#include "Config.h"
#include "../headers/Snake.h"
#include "../headers/Food.h"
#include "../headers/PowerUps.h"
#include "../headers/ConfigurationLevel2.h"
#include "../headers/ConfigurationLevel3.h"

// Power-up types
typedef enum {
    PU_SPEED_UP,     // Increases snake speed
    PU_SPEED_DOWN,   // Decreases snake speed
    PU_DOUBLE_SCORE, // Doubles points earned
    PU_TYPE_COUNT    // Total count of power-up types
} PowerUpType;

// Power-up structure
typedef struct {
    COORD position;  
    PowerUpType type; 
    bool active;      
    time_t spawnTime; 
} PowerUp;

// Function declarations
void initPowerUps();                     // Initialize power-up system
void spawnPowerUp();                     // Spawn new power-ups
void checkPowerUpCollision(COORD headPos, int* score, int* gameSpeed); // Check if snake collected power-up
void renderPowerUps();                   // Draw power-ups on screen
void clearExpiredPowerUps();             // Remove expired power-ups

// Configuration
#define POWERUP_DURATION 8          // Seconds power-up stays on screen
#define POWERUP_SPAWN_INTERVAL 12   // Seconds between power-up spawns
#define SPEED_CHANGE_AMOUNT 15      // Speed change amount (ms)
#define DOUBLE_SCORE_DURATION 10    // Seconds double score remains active
#define MAX_ACTIVE_POWERUPS 2       // Maximum active power-ups at once

extern bool doubleScoreActive;      // Global double score state
extern time_t doubleScoreEndTime;   // When double score expires

extern bool speedChanged;
extern time_t effectEndTime;
extern std::string currentEffectMessage;

#endif
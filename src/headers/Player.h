// headers/Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>

struct Player {
    std::string name;
    int score;
    int level;
    std::string date;
    
    static void saveToFile(const Player& player);
    static void showHighScores();
};

#endif
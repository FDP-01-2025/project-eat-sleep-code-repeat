// headers/Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string> // For using strings like player name and date
#include <fstream>
#include <ctime>   // To get the current date and time
#include <iomanip> // For formatting output (like aligning columns)

struct Player
{
    std::string name;
    int score;
    int level;
    std::string date;
    // Saves player info to file
    static void saveToFile(const Player &player);
    // Displays top scores on screen
    static void showHighScores();
};

#endif
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <string>

class MenuManager
{
private:
    std::string playerName;
    int selectedLevel;

public:
    MenuManager();

    // Menu display functions
    void showStartMenu();
    void showHowToPlayMenu();
    void showLevelSelectorMenu();

    // Menu interaction functions
    void handleMainMenu();
    void handleHowToPlayMenu();
    void handleLevelSelectorMenu();

    // Player name input
    void getPlayerName();

    // Getters
    std::string getPlayerName() const { return playerName; }
    int getSelectedLevel() const { return selectedLevel; }
    std::string getPlayerNameValue() const;
};

#endif
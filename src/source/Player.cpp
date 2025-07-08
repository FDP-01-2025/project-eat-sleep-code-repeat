#include "../headers/Player.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
// Saves the player's data to a file with current date
void Player::saveToFile(const Player &player)
{
    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open())
    {
        // Obtener fecha actual
        time_t now = time(0);
        tm *localTime = localtime(&now);
        char dateStr[11];
        strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", localTime);

        file << player.name << ","
             << player.score << ","
             << player.level << ","
             << dateStr << "\n";
        file.close();
    }
}
// Reads the scores file, sorts top scores and displays top 10
void Player::showHighScores()
{
    system("cls");
    std::ifstream file("scores.txt");
    std::vector<Player> players;

    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);

            if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos)
            {
                Player p;
                p.name = line.substr(0, pos1);
                p.score = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
                p.level = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                p.date = line.substr(pos3 + 1);
                players.push_back(p);
            }
        }
        file.close();
    }

    // Ordenar por puntaje descendente
    std::sort(players.begin(), players.end(), [](const Player &a, const Player &b)
              { return a.score > b.score; });

    // Display top 10 high scores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    std::cout << "*----------------------------------------------------------------------------------------------------------------------------*" << std::endl;
    std::cout << "|                                                    TOP 10 HIGH SCORES                                                     |" << std::endl;
    std::cout << "*----------------------------------------------------------------------------------------------------------------------------*" << std::endl;
    std::cout << "| " << std::left << std::setw(20) << "PLAYER"
              << " | " << std::setw(10) << "SCORE"
              << " | " << std::setw(10) << "LEVEL"
              << " | " << std::setw(12) << "DATE"
              << " |" << std::endl;
    std::cout << "*----------------------------------------------------------------------------------------------------------------------------*" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    int count = 0;
    for (const auto &p : players)
    {
        if (count++ >= 10)
            break;

        std::cout << "| " << std::left << std::setw(20) << p.name
                  << " | " << std::setw(10) << p.score
                  << " | " << std::setw(10) << p.level
                  << " | " << std::setw(12) << p.date
                  << " |" << std::endl;
    }

    if (players.empty())
    {
        std::cout << "|                                       NO HIGH SCORES RECORDED YET                                        |" << std::endl;
    }

    std::cout << "*----------------------------------------------------------------------------------------------------------------------------*" << std::endl;
    std::cout << "\nPress any key to return to the menu...";
    _getch();
}
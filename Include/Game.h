//
// Created by Anice on 04/11/2024.
//

#ifndef GAME_H
#define GAME_H

#endif //GAME_H
#include <vector>
#include "Player.h"
#include "Board.h"

class Game {
public:
    Game(int boardSize, const std::vector<std::string> &playerNames, const std::vector<std::string> &playerColors);

    void start(); // Démarre le jeu
    void nextTurn(); // Passe au tour suivant

private:
    Board board;
    std::vector<Player> players;
    int currentPlayerIndex;

    void initializePlayers(const std::vector<std::string> &playerNames, const std::vector<std::string> &playerColors);
};


<<<<<<< Updated upstream
//
// Created by Peon4 on 04/11/2024.
//

#ifndef C_SUPINFO_GAME_H
#define C_SUPINFO_GAME_H

int Game_loop();

#endif //C_SUPINFO_GAME_H
=======
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../include/Player.h"
#include "../include/Board.h"

class Game {
public:


private:

    std::vector<Player> players;
    Board board;
};

int Game_loop();

#endif //GAME_H
>>>>>>> Stashed changes

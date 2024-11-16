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


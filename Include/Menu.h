#ifndef MENU_H
#define MENU_H

#include <queue>
#include "Tiles.h"

int Menu_player_number();
int menu_player_info(int number_of_players, std::queue<Tile>& tileQueue);
int Menu_exit();


#endif //MENU_H

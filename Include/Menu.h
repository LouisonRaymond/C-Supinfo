#ifndef MENU_H
#define MENU_H

#include <queue>
#include "Tiles.h"

int Menu_player_number();  //function to get the number of players
int menu_player_info(int number_of_players, std::queue<Tile>& tileQueue); // function to get the player info (name color id)
int Menu_exit(); // function to exit the game

#endif //MENU_H

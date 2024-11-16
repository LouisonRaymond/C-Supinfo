//Library
#include <iostream>

//Include
#include "../include/Game.h"
#include "../include/Menu.h"


int Game_loop()
{
    while (true) {

        int number_of_players = Menu_player_number();

        if (number_of_players >= 2 && number_of_players <= 9) {
            std::cout << "Nombre de joueurs valide : " << number_of_players << std::endl;
            break;
        }
    }


    return 0;
}
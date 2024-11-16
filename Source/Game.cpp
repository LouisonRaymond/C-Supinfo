//Library
#include <iostream>
#include <vector>

//Include
#include "../include/Game.h"
#include "../include/Menu.h"
#include "../include/Board.h"
#include "../include/Player.h"



int Game_loop()
{
    // Get the number of players
    const int player_number = Menu_player_number();

    // Get the player information
    extern std::vector<Player> players;
    menu_player_info(player_number);


    // afficher tous les joueurs
    std::cout << "\nliste des joueurs inscrits :\n";
    for (const auto& player : players) {
        player.display();
    }

    // Create the board
    Board gameBoard(player_number);

    while (true) {
        gameBoard.display();







        //if l & L is pressed the game will stop
        if (Menu_exit() == 0) {
            break;
        }
    }
    return 0;
}
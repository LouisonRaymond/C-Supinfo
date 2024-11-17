//Library
#include <iostream>
#include <vector>

//Include
#include "../include/Game.h"
#include "../include/Menu.h"
#include "../include/Board.h"
#include "../include/Player.h"
#include "../include/Tiles.h"



int Game_loop()
{
    //Tiles
    std::vector<Tile> tiles = initializeTiles();
    tiles[12].displayTile();

    // Get the number of players
    const int player_number = Menu_player_number();

    // Get the player information
    extern std::vector<Player> players;
    menu_player_info(player_number);



    // Create the board
    Board gameBoard(player_number);

    // afficher tous les joueurs
    // std::cout << "\nliste des joueurs inscrits :\n";
    // for (const auto& player : players) {
    //     player.display();
    // }

    bool turn_left = true;
    while (turn_left) {
        turn_left = false;

        for (auto& player : players) {
            if (player.hasRemainingTurns()) {

                gameBoard.display();
                player.takeTurn();
                turn_left = true; // Il y a encore des tours restants
            }
        }






        //if l & L is pressed the game will stop
        if (Menu_exit() == 0) {
            break;
        }
    }
    std::cout << "The Game is finished ! " << std::endl;
    return 0;
}
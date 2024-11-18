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
    // Get the number of players
    const int player_number = Menu_player_number();

    // //Tiles
    // std::vector<Tile> tiles = initializeTiles();
    // tiles[12].displayTile();
    //
    // // Tester la rotation
    // tiles[12].rotate();
    // std::cout << "\nTuile après rotation :\n";
    // tiles[12].displayTile();
    //
    // // Tester le flip
    // tiles[12].flip();
    // std::cout << "\nTuile après flip :\n";
    // tiles[12].displayTile();

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

        // during all player turn
        for (auto& player : players) {
            if (player.hasRemainingTurns()) {

                //print player info
                player.display();

                gameBoard.display();
                player.takeTurn();
                turn_left = true; // there is still turn left
            }
        }
    }
    std::cout << "The Game is finished ! " << std::endl;
    return 0;
}
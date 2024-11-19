//Library
#include <iostream>
#include <vector>
#include <queue>

//Include
#include "../include/Game.h"
#include "../include/Menu.h"
#include "../include/Board.h"
#include "../include/Player.h"
#include "../include/Tiles.h"

extern std::vector<Player> players;


int Game_loop()
{
    // Get the number of players
    const int player_number = Menu_player_number();

    // Create the board
    Board gameBoard(player_number);

    // Initialiser la queue des tuiles
    std::queue<Tile> tileQueue = initializeTileQueue(player_number);

    // Initialiser les joueurs avec leurs noms et leurs tuiles
    menu_player_info(player_number, tileQueue);

    // gameBoard.display();

    bool turn_left = true;
    while (turn_left) {
        turn_left = false;

        // during all player turn
        for (auto& player : players) {
            if (player.hasRemainingTurns()) {

                //display player info
                player.display();

                //display the board
                gameBoard.display();

                //turn of the players
                player.takeTurn(tileQueue);

                turn_left = true; // there is still turn left
            }
        }
    }
    std::cout << "The Game is finished ! " << std::endl;
    return 0;
}


// afficher tous les joueurs
// std::cout << "\nliste des joueurs inscrits :\n";
// for (const auto& player : players) {
//     player.display();
// }



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

// Ajouter la tuile à la fin de la queue si échangée
// tileQueue.push(currentTile);

// // Prendre la première tuile
// Tile currentTile = tileQueue.front();
// tileQueue.pop();
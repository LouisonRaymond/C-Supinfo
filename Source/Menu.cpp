//Library
#include <iostream>
#include <limits>

//Include file
#include "../Include/Menu.h"
#include "../Include/Board.h"
#include "../Include/Player.h"
#include "../Include/Tiles.h"

//function to get the number of players
int Menu_player_number() {
    int number_of_players;

    std::cout << "Enter the number of players (2 to 9) : ";
    std::cin >> number_of_players;

    // Check Entry validity
    if (std::cin.fail() || number_of_players < 2 || number_of_players > 9) {
        std::cin.clear(); // Error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line

        std::cout << "Invalid entry to put something between 2 and 9." << std::endl;
    } else {
        // nothing (maybe add a message)
    }

    return number_of_players;
}

int menu_player_info(int number_of_players, std::queue<Tile>& tileQueue) {
    // init player
    extern std::vector<Player> players;

    for (int i = 1; i <= number_of_players; ++i) {
        std::string name;

        // get name
        std::cout << "Write your player name " << i << " : ";
        std::cin >> name;

        // create player
        Player player(i, name);

        // give init tiles
        player.updateTiles(tileQueue);

        // add it to the list of players
        players.push_back(player);
    }

    return 0;
}

// function to exit the game
int Menu_exit() {
    char key;
    std::cin >> key;
    if (key == 'l' || key == 'L') {
        std::cout << "You Successful leaved the game " << std::endl;
        return 0;
    }
    return 1;
}











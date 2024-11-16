//Library
#include <iostream>
#include <limits>

//Include file
#include "../Include/Menu.h"
#include "../Include/Board.h"
#include "../Include/Player.h"
#include "../Include/Game.h"

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
        // rien pour instant
    }

    return number_of_players;
}

int menu_player_info(int number_of_players) {

    // Initialiser et afficher chaque joueur
    extern std::vector<Player> players;
    for (int i = 1; i <= number_of_players; ++i) {
        std::string name;

        // Demander le nom du joueur
        std::cout << "Entrez le nom du joueur " << i << " : ";
        std::cin >> name;

        // Créer un joueur et l'ajouter au vecteur
        players.emplace_back(i, name);
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






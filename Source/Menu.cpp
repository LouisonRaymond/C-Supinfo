//Library
#include <iostream>
#include <limits>

//Include file
#include "../Include/Menu.h"


int Menu_player_number() {
    int number_of_players;

    std::cout << "Entrez le nombre de joueurs (2 à 9) : ";
    std::cin >> number_of_players;

    // Check Entry validity
    if (std::cin.fail() || number_of_players < 2 || number_of_players > 9) {
        std::cin.clear(); // Error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne

        std::cout << "Entrée invalide. Veuillez entrer un nombre entre 2 et 9." << std::endl;
    } else {
        std::cout << "\nError Try to restart the Game\n" << std::endl;
    }

    return number_of_players;
}


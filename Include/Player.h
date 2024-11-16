#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "../include/Tiles.h"

class Player {
public:
    // Constructeur pour initialiser un joueur avec son numéro et son nom
    Player(int id, const std::string& name);

    // Afficher le joueur avec sa couleur
    void display() const;

private:
    int id;                 // Numéro du joueur
    std::string name;       // Nom du joueur
    std::string color;      // Couleur du joueur
};

#endif //PLAYER_H

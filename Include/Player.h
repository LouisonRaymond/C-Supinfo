#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <queue>
#include "../include/Tiles.h"

class Player {
public:
    // Constructeur pour initialiser un joueur avec son numéro et son nom
    Player(int id, std::string  name);

    // Afficher le joueur avec sa couleur
    void display() const;

    // Méthode pour que le joueur prenne son tour
    void takeTurn(std::queue<Tile>& tileQueue);

    // Vérifier si le joueur a atteint le nombre maximum de tours
    bool hasRemainingTurns() const;

    // Méthode pour ajouter une tuile d'échange
    void addExchangeTile();

    // Méthode pour obtenir le nombre de tuiles d'échange
    int getExchangeTiles() const;

    // Mettre à jour les tuiles du joueur
    void updateTiles(std::queue<Tile>& tileQueue);

    int getId() const;                  // Retourne l'ID du joueur
    const std::string& getName() const; // Retourne le nom du joueur
    const std::string& getColor() const; // Retourne la couleur du joueur



private:
    int id;                 // Numéro du joueur
    std::string name;       // Nom du joueur
    std::string color;      // Couleur du joueur
    int currentTurn;        // Compteur de tours pour chaque joueur
    int exchangeTiles;      // Nombre de tuiles d'échange
    std::vector<Tile> tiles; // Tuiles du joueur
};



#endif //PLAYER_H

//
// Created by Anice on 04/11/2024.
//

/* #ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tile.h"
#include "Player.h"

class Board {
public:
    Board(int size);

    bool placeTile(const Player &player, const Tile &tile, int x, int y); // Place une tuile sur la grille
    void display() const; // Affiche la grille

private:
    int size;
    std::vector<std::vector<char>> grid; // Représentation de la grille de jeu
    bool isPlacementValid(const Tile &tile, int x, int y) const; // Vérifie la validité du placement
};

#endif // BOARD_H
*/

#ifndef BOARD_H
#define BOARD_H

#include <vector>

// Classe Board qui représente le plateau de jeu
class Board {
private:
    int size;  // Taille du plateau
    std::vector<std::vector<char>> grid; // Grille représentant l'état du plateau

public:
    // Constructeur
    Board(int size);

    // Méthode pour afficher le plateau
    void display() const;

    // Méthode pour placer une tuile sur le plateau
    bool placeTile(char symbol, int x, int y);

    // Méthode pour vérifier si le placement d'une tuile est valide
    bool isPlacementValid(int x, int y) const;
};

#endif // BOARD_H

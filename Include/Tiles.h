#ifndef TILES_H
#define TILES_H

#include <vector>
#include <iostream>

class Tile {
private:
    int tileNumber; // Numéro de la tuile (1 à 96)
    std::vector<std::vector<int>> shape; // Forme de la tuile (matrice 2D)

public:
    // Constructeur
    Tile(int number, const std::vector<std::vector<int>>& shape);

    // Obtenir le numéro de la tuile
    int getTileNumber() const;

    // Obtenir la forme de la tuile
    const std::vector<std::vector<int>>& getShape() const;

    // Afficher la tuile
    void displayTile() const;

    void rotate();

    void flip();


};

// Déclaration de la fonction pour initialiser les tuiles
std::vector<Tile> initializeTiles();

std::queue<Tile> initializeTileQueue(int numPlayers);

#endif // TILES_H


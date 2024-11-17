//Library
#include <iostream>

//Include
#include "../Include/Tiles.h"

// Constructeur
Tile::Tile(int number, const std::vector<std::vector<int>>& shape)
    : tileNumber(number), shape(shape) {}

// Obtenir le numéro de la tuile
int Tile::getTileNumber() const {
    return tileNumber;
}

// Obtenir la forme de la tuile
const std::vector<std::vector<int>>& Tile::getShape() const {
    return shape;
}

// Afficher la tuile
void Tile::displayTile() const {
    std::cout << "Tile #" << tileNumber << ":\n";
    for (const auto& row : shape) {
        for (int cell : row) {
            std::cout << (cell == 1 ? "x " : ". ");
        }
        std::cout << std::endl;
    }
}

// Fonction pour initialiser les 96 tuiles avec des formes prédéfinies
std::vector<Tile> initializeTiles() {
    std::vector<Tile> tiles;

    // Exemple de formes pour les tuiles
    std::vector<std::vector<std::vector<int>>> tileShapes = {
        {{1}},  // Tuile 1
        {{1, 1}}, // Tuile 2
        {{1}, {1}}, // Tuile 3
        {{1, 1, 1}}, // Tuile 4
        {{1}, {1}, {1}}, // Tuile 5
        {{1, 1, 1, 1}}, // Tuile 6
        {{1}, {1}, {1}, {1}}, // Tuile 7
        {{1, 0}, {1, 1}}, // Tuile 8
        {{1, 1}, {1, 0}}, // Tuile 9
        {{1, 1}, {1, 1}}, // Tuile 10
        // Ajouter d'autres formes jusqu'à 96 tuiles
    };
    return tiles;
}





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
            // Afficher "x" si cell vaut 1, sinon ne rien afficher
            if (cell == 1) {
                std::cout << "x ";
            } else {
                std::cout << "  "; // Afficher un espace vide pour conserver l'alignement
            }
        }
        std::cout << std::endl;
    }
}

// Fonction pour initialiser les 96 tuiles avec des formes prédéfinies
std::vector<Tile> initializeTiles() {
    std::vector<Tile> tiles;

    // Exemple de formes pour les tuiles
    std::vector<std::vector<std::vector<int>>> tileShapes = {
        {{1}, {1, 1, 1}},  // Tuile 1
        {{0, 1}, {0, 1}, {1, 1, 1}}, // Tuile 2
        {{0, 1}, {1, 1, 1}, {0, 1}}, // Tuile 3
        {{0, 0, 1}, {1, 1, 1}, {1}}, // Tuile 4
        {{0, 1}, {1, 1, 1}}, // Tuile 5
        {{1, 1}, {1, 1}}, // Tuile 6
        {{1, 0, 1}, {1, 1, 1}}, // Tuile 7
        {{1, 1, 1}}, // Tuile 8
        {{0, 1}, {1, 1}, {1}}, // Tuile 9
        {{1}, {1, 1}}, // Tuile 10
        {{0, 0, 1}, {0, 1, 1}, {1, 1}}, // Tuile 11
        {{1, 1}}, // Tuile 12
        {{0, 1}, {1, 1}, {1}, {1}, {1, 1}}, // Tuile 13
        {{1, 1, 1}, {1}, {1}, {1}, {1}},  // Tuile 14
        {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1, 1}, {0, 1, 1, 1}, {1, 1}},  // Tuile 15
        {{0, 0, 1}, {0, 1, 1}, {1, 1}, {1}},  // Tuile 16 fin premiere ligne




    };
    for (int i = 0; i < 96; ++i) {
        tiles.emplace_back(i + 1, tileShapes[i % tileShapes.size()]);
    }

    return tiles;
}





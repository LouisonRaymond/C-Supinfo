//Library
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

//Include
#include "../Include/Tiles.h"
#include "../include/Menu.h"
#include "../include/Player.h"


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

// Méthode pour faire pivoter la tuile de 90 degrés dans le sens horaire
void Tile::rotate() {
    int rows = shape.size();
    int cols = shape[0].size();
    std::vector<std::vector<int>> rotatedShape(cols, std::vector<int>(rows));

    // Transposer puis inverser les colonnes
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotatedShape[j][rows - 1 - i] = shape[i][j];
        }
    }
    shape = rotatedShape;
}

// Méthode pour retourner la tuile horizontalement (flip)
void Tile::flip() {
    int rows = shape.size();
    // Inverser l'ordre des lignes
    for (int i = 0; i < rows / 2; ++i) {
        std::swap(shape[i], shape[rows - 1 - i]);
    }
}








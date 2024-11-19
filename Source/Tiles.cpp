//Library
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <queue>
#include <chrono>

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
        {{0, 1}, {1, 1, 1}, {1, 1}}, // Tuile 17 fin premiere ligne
        {{1, 1, 1}},  // Tuile 18 fin premiere ligne
        {{1}, {1, 1}, {1}, {1}},  // Tuile 19 fin premiere ligne
        {{0,1,1}, {1, 1}, {1,1}},  // Tuile 20 fin premiere ligne
        {{0,1}, {1, 1}, {1,1,1}},  // Tuile 21 fin premiere ligne
        {{0,1}, {0,1}, {1,1,1}, {1}},  // Tuile 22 fin premiere ligne
        {{1},{1,1}},  // Tuile 23 fin premiere ligne
        {{1, 1}, {1,1}, {1,1}},  // Tuile 24 fin premiere ligne
        {{1,1,1}, {0, 1}, {0,1}, {0,1}},  // Tuile 25 fin premiere ligne
        {{1}, {1, 1}, {0,1,1}, {0,0,1,1}},  // Tuile 26 fin premiere ligne
        {{1,1,1,1,1}},  // Tuile 27 fin premiere ligne
        {{1}, {1, 1,1}, {0,0,1}, {0,0,1}},  // Tuile 28 fin premiere ligne
        {{1}, {1, 1}, {1}, {1,1},{1}},  // Tuile 29 fin premiere ligne
        {{1}, {1,1}, {1,1},{1}},  // Tuile 30 fin premiere ligne
        {{0,1}, {0,1}, {0,1}, {1,1,1},{1,0,1}},  // Tuile 31 fin premiere ligne
        {{1, 1}},  // Tuile 32 fin premiere ligne
        {{1}, {1,1,1}, {1,0,1,1}},  // Tuile 33
        {{0,1}, {0,1}, {1,1}, {1}, {1}},  // Tuile 34
        {{1,1}, {0,1}, {0,1,1,1},{1,1},{1}},  // Tuile 35
        {{1}, {1}, {1,1},{1}},  // Tuile 36
        {{0,1}, {1,1}, {1}},  // Tuile 37
        {{1,0,0,1}, {1,1,1,1}},  // Tuile 38
        {{0,0,0,1,1}, {1,0,0,0,1}, {1,1,1,1,1}},  // Tuile 39
        {{1}, {1}, {1,1},{0,1,1,1}},  // Tuile 40
        {{1,1}, {0,1,1}, {1,1,0},{0,1,1},{0,1}},  // Tuile 41
        {{1,0}, {1,1}, {1,1}},  // Tuile 42
        {{0,1}, {0,1}, {1,1,1,1}},  // Tuile 43
        {{1,1}, {1,1}},  // Tuile 44
        {{0,1}, {1,1}, {1,1},{1,0}},  // Tuile 45
        {{1,1,1}, {0,1,0}, {1,1,0}},  // Tuile 46
        {{1,1,1,1}},  // Tuile 47
        {{0,1,0}, {1,1,1}},  // Tuile 48
        {{1}, {1}, {1,1,1,1}},  // Tuile 49
        {{0,1,1}, {1,1}, {0,1,1,1}},  // Tuile 50
        {{0,1}, {1,1}, {1,},{1}},  // Tuile 51
        {{1}, {1,1,1}},  // Tuile 52
        {{1}, {1,1}, {1},{1},{1}},  // Tuile 53
        {{0,0,1,1,1}, {0,0,1}, {0,0,1},{0,0,1},{1,1,1,0,0}},  // Tuile 54
        {{0,1}, {0,1}, {1,1},{1},{1,1},{1}},  // Tuile 55
        {{1,1,1,1}},  // Tuile 56
        {{1,1}, {0,1}, {0,1,1,1},{0,0,0,1}},  // Tuile 57
        {{0,1}, {0,1}, {1,1,1},{0,1},{0,1}},  // Tuile 58
        {{0,0,1}, {0,0,1}, {1,1,1}},  // Tuile 59
        {{1}, {1}, {1},{1},{1},{1}},  // Tuile 60
        {{1,0,1}, {1,1,1}, {0,1,0},{1,1}},  // Tuile 61
        {{0,0,1}, {1,1,1}, {0,1,1,1},{0,1}},  // Tuile 62
        {{0,1,1}, {0,1}, {0,1},{1,1,1}},  // Tuile 63
        {{1}, {1}, {1,1},{1},{1}},  // Tuile 64
        {{1,1}, {0,1}, {0,1,0,1},{1,1,1,1}},  // Tuile 65
        {{0,0,1}, {0,1,1}, {1,1,0},{1},{1,1}},  // Tuile 66
        {{0,1,1}, {0,1,0}, {0,1,0},{0,1,0},{1,1},{1}}, // Tuile 67
        {{1,0,1}, {1,1,1,1}},  // Tuile 68
        {{1,1}, {0,1,0,1}, {0,1,0,1},{0,1,1,1}}, // Tuile 69
        {{1}, {1,1}, {1},{1},{1}}, // Tuile 70
        {{1}, {1,0,1}, {1,1,1,1},{0,1},{0,1}},  // Tuile 71
        {{1,1}, {1}, {1},{1},{1},{1},{1}},  // Tuile 72
        {{0,1}, {1,1,1}, {1,},{1}},  // Tuile 73
        {{1,1}},  // Tuile 74
        {{0,0,1}, {1,0,1}, {1,1,1}},  // Tuile 75
        {{0,1,0}, {1,1,1}, {1,0,1}},  // Tuile 76
        {{0,0,1}, {0,0,1}, {1,1,1,1,1},{0,0,1},{0,0,1,}},  // Tuile 77
        {{0,0,0,1}, {0,0,1,1}, {0,0,1},{0,0,1},{0,1,1},{1,1}},  // Tuile 78
        {{1,1}, {1}, {1,1},{1},{1,1}},  // Tuile 79
        {{0,1}, {0,1}, {0,1},{1,1,1,1},{0,1}},  // Tuile 80
        {{0,1}, {1,1}, {1,},{1},{1}},  // Tuile 81
        {{0,1,1}, {0,1,1}, {1,1},{1}},  // Tuile 82
        {{0,1,1}, {0,1}, {1,1},{0,1,1},{0,1}, {0,1}},  // Tuile 83
        {{1,1}, {1,1}, {0,1,1},{0,1},{0,1}, {0,1}},  // Tuile 84
        {{0,1}, {0,1,1}, {1,1},{0,1}},  // Tuile 85
        {{1,1}, {1,1,1,1}},  // Tuile 86
        {{0,0,1,1}, {1,1,1}, {1},{1,1}},  // Tuile 87
        {{0,1,1}, {0,1,0}, {0,1,0},{1,1}},  // Tuile 88
        {{0,1}, {0,1}, {1,1,1},{0,1}},  // Tuile 89
        {{1,1,1}, {1,0,1}, {1},{1,1}},  // Tuile 90
        {{0,1}, {0,1,1}, {1,1},{1}},  // Tuile 91
        {{1}, {1,1}, {1,1,1}},  // Tuile 92
        {{1}, {1}, {1},{1,1},{0,1}},  // Tuile 93
        {{0,1}, {1,1,1,1}, {1}},  // Tuile 94
        {{0,1,1}, {1,1}, {1},{1}},  // Tuile 95
        {{0,1}, {1,1}, {1},{1,1}},  // Tuile 96
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

std::queue<Tile> initializeTileQueue(int numPlayers) {
    std::vector<Tile> allTiles = initializeTiles();
    int totalPlayableTiles = static_cast<int>(std::round(10.67 * numPlayers));
    totalPlayableTiles = std::min(totalPlayableTiles, 96); // Limiter à 96 tuiles maximum

    // Mélanger l'ensemble des tuiles avec une graine aléatoire
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(allTiles.begin(), allTiles.end(), std::default_random_engine(seed));

    // Mettre les tuiles mélangées dans une queue
    std::queue<Tile> tileQueue;
    for (int i = 0; i < totalPlayableTiles; ++i) {
        tileQueue.push(allTiles[i]);
    }

    return tileQueue;
}








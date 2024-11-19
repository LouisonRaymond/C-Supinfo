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

// Constructor
Tile::Tile(int number, const std::vector<std::vector<int>>& shape)
    : tileNumber(number), shape(shape) {}

// get tile number
int Tile::getTileNumber() const {
    return tileNumber;
}

// get tile shape
const std::vector<std::vector<int>>& Tile::getShape() const {
    return shape;
}

// display tile
void Tile::displayTile() const {
    std::cout << "Tile #" << tileNumber << ":\n";
    for (const auto& row : shape) {
        for (int cell : row) {
            // 1 for x to display tile and nothing for 0
            if (cell == 1) {
                std::cout << "x ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

// tile init (96)
std::vector<Tile> initializeTiles() {
    std::vector<Tile> tiles;

    // tiles shape
    std::vector<std::vector<std::vector<int>>> tileShapes = {
        {{1}, {1, 1, 1}},  // Tile 1
        {{0, 1}, {0, 1}, {1, 1, 1}}, // Tile 2
        {{0, 1}, {1, 1, 1}, {0, 1}}, // Tile 3
        {{0, 0, 1}, {1, 1, 1}, {1}}, // Tile 4
        {{0, 1}, {1, 1, 1}}, // Tile 5
        {{1, 1}, {1, 1}}, // Tile 6
        {{1, 0, 1}, {1, 1, 1}}, // Tile 7
        {{1, 1, 1}}, // Tile 8
        {{0, 1}, {1, 1}, {1}}, // Tile 9
        {{1}, {1, 1}}, // Tile 10
        {{0, 0, 1}, {0, 1, 1}, {1, 1}}, // Tile 11
        {{1, 1}}, // Tile 12
        {{0, 1}, {1, 1}, {1}, {1}, {1, 1}}, // Tile 13
        {{1, 1, 1}, {1}, {1}, {1}, {1}},  // Tile 14
        {{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1, 1}, {0, 1, 1, 1}, {1, 1}},  // Tile 15
        {{0, 0, 1}, {0, 1, 1}, {1, 1}, {1}},  // Tile 16
        {{0, 1}, {1, 1, 1}, {1, 1}}, // Tile 17
        {{1, 1, 1}},  // Tile 18
        {{1}, {1, 1}, {1}, {1}},  // Tile 19
        {{0,1,1}, {1, 1}, {1,1}},  // Tile 20
        {{0,1}, {1, 1}, {1,1,1}},  // Tile 21
        {{0,1}, {0,1}, {1,1,1}, {1}},  // Tile 22
        {{1},{1,1}},  // Tile 23
        {{1, 1}, {1,1}, {1,1}},  // Tile 24
        {{1,1,1}, {0, 1}, {0,1}, {0,1}},  // Tile 25
        {{1}, {1, 1}, {0,1,1}, {0,0,1,1}},  // Tile 26
        {{1,1,1,1,1}},  // Tile 27
        {{1}, {1, 1,1}, {0,0,1}, {0,0,1}},  // Tile 28
        {{1}, {1, 1}, {1}, {1,1},{1}},  // Tile 29
        {{1}, {1,1}, {1,1},{1}},  // Tile 30
        {{0,1}, {0,1}, {0,1}, {1,1,1},{1,0,1}},  // Tile 31
        {{1, 1}},  // Tile 32
        {{1}, {1,1,1}, {1,0,1,1}},  // Tile 33
        {{0,1}, {0,1}, {1,1}, {1}, {1}},  // Tile 34
        {{1,1}, {0,1}, {0,1,1,1},{1,1},{1}},  // Tile 35
        {{1}, {1}, {1,1},{1}},  // Tile 36
        {{0,1}, {1,1}, {1}},  // Tile 37
        {{1,0,0,1}, {1,1,1,1}},  // Tile 38
        {{0,0,0,1,1}, {1,0,0,0,1}, {1,1,1,1,1}},  // Tile 39
        {{1}, {1}, {1,1},{0,1,1,1}},  // Tile 40
        {{1,1}, {0,1,1}, {1,1,0},{0,1,1},{0,1}},  // Tile 41
        {{1,0}, {1,1}, {1,1}},  // Tile 42
        {{0,1}, {0,1}, {1,1,1,1}},  // Tile 43
        {{1,1}, {1,1}},  // Tile 44
        {{0,1}, {1,1}, {1,1},{1,0}},  // Tile 45
        {{1,1,1}, {0,1,0}, {1,1,0}},  // Tile 46
        {{1,1,1,1}},  // Tile 47
        {{0,1,0}, {1,1,1}},  // Tile 48
        {{1}, {1}, {1,1,1,1}},  // Tile 49
        {{0,1,1}, {1,1}, {0,1,1,1}},  // Tile 50
        {{0,1}, {1,1}, {1,},{1}},  // Tile 51
        {{1}, {1,1,1}},  // Tile 52
        {{1}, {1,1}, {1},{1},{1}},  // Tile 53
        {{0,0,1,1,1}, {0,0,1}, {0,0,1},{0,0,1},{1,1,1,0,0}},  // Tile 54
        {{0,1}, {0,1}, {1,1},{1},{1,1},{1}},  // Tile 55
        {{1,1,1,1}},  // Tile 56
        {{1,1}, {0,1}, {0,1,1,1},{0,0,0,1}},  // Tile 57
        {{0,1}, {0,1}, {1,1,1},{0,1},{0,1}},  // Tile 58
        {{0,0,1}, {0,0,1}, {1,1,1}},  // Tile 59
        {{1}, {1}, {1},{1},{1},{1}},  // Tile 60
        {{1,0,1}, {1,1,1}, {0,1,0},{1,1}},  // Tile 61
        {{0,0,1}, {1,1,1}, {0,1,1,1},{0,1}},  // Tile 62
        {{0,1,1}, {0,1}, {0,1},{1,1,1}},  // Tile 63
        {{1}, {1}, {1,1},{1},{1}},  // Tile 64
        {{1,1}, {0,1}, {0,1,0,1},{1,1,1,1}},  // Tile 65
        {{0,0,1}, {0,1,1}, {1,1,0},{1},{1,1}},  // Tile 66
        {{0,1,1}, {0,1,0}, {0,1,0},{0,1,0},{1,1},{1}}, // Tile 67
        {{1,0,1}, {1,1,1,1}},  // Tile 68
        {{1,1}, {0,1,0,1}, {0,1,0,1},{0,1,1,1}}, // Tile 69
        {{1}, {1,1}, {1},{1},{1}}, // Tile 70
        {{1}, {1,0,1}, {1,1,1,1},{0,1},{0,1}},  // Tile 71
        {{1,1}, {1}, {1},{1},{1},{1},{1}},  // Tile 72
        {{0,1}, {1,1,1}, {1,},{1}},  // Tile 73
        {{1,1}},  // Tile 74
        {{0,0,1}, {1,0,1}, {1,1,1}},  // Tile 75
        {{0,1,0}, {1,1,1}, {1,0,1}},  // Tile 76
        {{0,0,1}, {0,0,1}, {1,1,1,1,1},{0,0,1},{0,0,1,}},  // Tile 77
        {{0,0,0,1}, {0,0,1,1}, {0,0,1},{0,0,1},{0,1,1},{1,1}},  // Tile 78
        {{1,1}, {1}, {1,1},{1},{1,1}},  // Tile 79
        {{0,1}, {0,1}, {0,1},{1,1,1,1},{0,1}},  // Tile 80
        {{0,1}, {1,1}, {1,},{1},{1}},  // Tile 81
        {{0,1,1}, {0,1,1}, {1,1},{1}},  // Tile 82
        {{0,1,1}, {0,1}, {1,1},{0,1,1},{0,1}, {0,1}},  // Tile 83
        {{1,1}, {1,1}, {0,1,1},{0,1},{0,1}, {0,1}},  // Tile 84
        {{0,1}, {0,1,1}, {1,1},{0,1}},  // Tile 85
        {{1,1}, {1,1,1,1}},  // Tile 86
        {{0,0,1,1}, {1,1,1}, {1},{1,1}},  // Tile 87
        {{0,1,1}, {0,1,0}, {0,1,0},{1,1}},  // Tile 88
        {{0,1}, {0,1}, {1,1,1},{0,1}},  // Tile 89
        {{1,1,1}, {1,0,1}, {1},{1,1}},  // Tile 90
        {{0,1}, {0,1,1}, {1,1},{1}},  // Tile 91
        {{1}, {1,1}, {1,1,1}},  // Tile 92
        {{1}, {1}, {1},{1,1},{0,1}},  // Tile 93
        {{0,1}, {1,1,1,1}, {1}},  // Tile 94
        {{0,1,1}, {1,1}, {1},{1}},  // Tile 95
        {{0,1}, {1,1}, {1},{1,1}},  // Tile 96
    };
    // if no 96 tiles create random one
    for (int i = 0; i < 96; ++i) {
        tiles.emplace_back(i + 1, tileShapes[i % tileShapes.size()]);
    }

    return tiles;
}

// rotate tile for 90 degrees
void Tile::rotate() {
    int rows = shape.size();
    int cols = shape[0].size();
    std::vector<std::vector<int>> rotatedShape(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotatedShape[j][rows - 1 - i] = shape[i][j];
        }
    }
    shape = rotatedShape;
}

// flip the tile
void Tile::flip() {
    int rows = shape.size();

    for (int i = 0; i < rows / 2; ++i) {
        std::swap(shape[i], shape[rows - 1 - i]);
    }
}

// Initialize the queue of tiles
std::queue<Tile> initializeTileQueue(int numPlayers) {
    std::vector<Tile> allTiles = initializeTiles();
    int totalPlayableTiles = static_cast<int>(std::round(10.67 * numPlayers));
    totalPlayableTiles = std::min(totalPlayableTiles, 96);

    // mix the tiles
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(allTiles.begin(), allTiles.end(), std::default_random_engine(seed));

    // create the queue of tiles
    std::queue<Tile> tileQueue;
    for (int i = 0; i < totalPlayableTiles; ++i) {
        tileQueue.push(allTiles[i]);
    }

    return tileQueue;
}








#ifndef TILES_H
#define TILES_H

#include <vector>

class Tile {
private:
    int tileNumber; // number of the tile
    std::vector<std::vector<int>> shape; // shape of the tile

public:
    // Constructor
    Tile(int number, const std::vector<std::vector<int>>& shape);

    // get tile number
    int getTileNumber() const;

    // get tile shape
    const std::vector<std::vector<int>>& getShape() const;

    // display the tile
    void displayTile() const;

    // rotate the tile
    void rotate();

    // flip the tile
    void flip();

};

// Initialize the tiles
std::vector<Tile> initializeTiles();

std::queue<Tile> initializeTileQueue(int numPlayers);

#endif // TILES_H


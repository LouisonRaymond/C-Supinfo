#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<std::vector<int>> board;
    int size = 0;

public:
    explicit Board(int players);  // Constructor
    void initialize(int players); // Initialize the grid
    void display() const; // print the grid
    void reset(int players); // Initialize the grid with special tiles


private:
    void placeSpecialTiles(int count, int type); // Place special tiles
    bool isValidPosition(int row, int col) const; // Check if the position is valid
};

#endif // BOARD_H


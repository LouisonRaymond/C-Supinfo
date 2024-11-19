//Library
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

//Include
#include "../include/Board.h"
#include "../include/Player.h"

// Constructor
Board::Board(int players) {
    initialize(players);
    reset(players);
}

// Give size to the grid and initialize it with 0
void Board::initialize(int players) {
    if (players >= 2 && players <= 4) {
        size = 20;
    } else if (players >= 5 && players <= 9) {
        size = 30;
    }
    board = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
}

//Print the grid with the alphabet on the sides
void Board::display() const {
    // Upper line with the alphabet
    std::cout << "  ";
    for (char c = 'A'; c < 'A' + size; ++c) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // Left side with the alphabet
    for (int i = 0; i < size; ++i) {
        std::cout << static_cast<char>('A' + i) << " ";
        std::cout << " ";

        // print the grid
        for (int j = 0; j < size; ++j) {
            switch (board[i][j]) {
                case 0: std::cout << ". "; break;
                case 1: std::cout << "E "; break;
                case 2: std::cout << "S "; break;
                case 3: std::cout << "R "; break;
                default: break;
            }
        }
        std::cout << std::endl;
    }
}


// Identify how many spécial tiles to place on the grid / 1 = Exchange, 2 = Stone, 3 = Robbery
void Board::reset(int players) {
    int exchange_count = static_cast<int>(std::ceil(1.5 * players));
    int stone_count = static_cast<int>(std::ceil(0.5 * players));
    int robbery_count = players;

    srand(static_cast<unsigned int>(time(0)));

    placeSpecialTiles(exchange_count, 1);
    placeSpecialTiles(stone_count, 2);
    placeSpecialTiles(robbery_count, 3);
}

// Add special tiles to the grid
void Board::placeSpecialTiles(int count, int type) {
    while (count > 0) {
        int row = rand() % size;
        int col = rand() % size;

        if (isValidPosition(row, col)) {
            board[row][col] = type;
            count--;
        }
    }
}

// Check if the special tiles position is valid
bool Board::isValidPosition(int row, int col) const {
    if (row == 0 || row == size - 1 || col == 0 || col == size - 1) {
        return false;
    }

    if (board[row][col] != 0) {
        return false;
    }

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (board[row + i][col + j] != 0) {
                return false;
            }
        }
    }
    return true;
}





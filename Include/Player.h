#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <queue>
#include "../include/Tiles.h"

class Player {
public:
    // Constructor to initialize the player with its id and name
    Player(int id, std::string  name);

    // display player info (number and name, color, turn number)
    void display() const;

    // Method for player's turn
    void takeTurn(std::queue<Tile>& tileQueue);

    // check if the player has remaining turns
    bool hasRemainingTurns() const;

    // Method to add an exchange tile
    void addExchangeTile();

    // Method to get the number of exchange tiles
    int getExchangeTiles() const;

    // Method to update the player's tiles
    void updateTiles(std::queue<Tile>& tileQueue);

    int getId() const;                  // return the player's id
    const std::string& getName() const; // return the player's name
    const std::string& getColor() const; // return the player's color


private:
    int id;                 // player id
    std::string name;       // name
    std::string color;      // color
    int currentTurn;        // Turn number
    int exchangeTiles;      // Number of exchange tiles
    std::vector<Tile> tiles; // Player's tiles
};



#endif //PLAYER_H

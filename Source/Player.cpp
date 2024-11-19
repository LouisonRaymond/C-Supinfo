//Library
#include "iostream"
#include <utility>

//Include
#include "Player.h"
#include "Menu.h"
#include "../include/Board.h"


std::vector<Player> players;

// Tableau des couleurs pour les 9 joueurs
const std::string colors[9] = {
    "\033[31m", // Rouge
    "\033[32m", // Vert
    "\033[34m", // Bleu
    "\033[33m", // Jaune
    "\033[35m", // Magenta
    "\033[36m", // Cyan
    "\033[37m", // Blanc
    "\033[90m", // Gris
    "\033[95m"  // Violet
};

// Constructeur pour initialiser le joueur avec son id et son nom
Player::Player(int id, std::string  name) : id(id), name(std::move(name)), currentTurn(0), exchangeTiles(0) {
    if (id >= 1 && id <= 9) {
        color = colors[id - 1]; // Assigner une couleur en fonction du numéro du joueur
    } else {
        color = "\033[37m"; // Couleur par défaut (blanc) si id > 9 (pour plus de sécurité)
    }
}

// Fonction pour afficher le joueur avec sa couleur
void Player::display() const {
    std::cout << color; // Appliquer la couleur
    std::cout << "Player " << id << " " << name << " - Turn : " << currentTurn + 1 << std::endl;
    std::cout << "\033[0m"; // Réinitialiser la couleur
}

// Méthode pour le tour du joueur
void Player::takeTurn(std::queue<Tile>& tileQueue) {
    if (currentTurn < 10) {
        currentTurn++;

        // Afficher la tuile actuelle
        if (!tiles.empty()) {
            std::cout << "Current Tile :\n";
            tiles[0].displayTile();

            // Afficher les 5 prochaines tuiles
            std::cout << "\nNext Tiles :\n";
            for (size_t i = 1; i < tiles.size(); ++i) {
                tiles[i].displayTile();
            }
        } else {
            std::cout << "No Tiles Left\n";
        }


        std::string action;

        std::cout << "Take tile(T)" << std::endl;
        std::cout << "Exchange tile - " << exchangeTiles << " available (E)" << std::endl;
        std::cout << "Display queue (D)" << std::endl;
        std::cout << "Skip Turn (P))" << std::endl;
        std::cout << "Exit (L)" << std::endl;

        std::cout << "Enter an action > : ";
        std::cin >> action;

        // Gérer l'action entrée
        if (action == "T" || action == "t") {
            if (!tileQueue.empty()) {

                std::cout << "Flip tile (F)" << std::endl;
                std::cout << "Rotate tile (R)" << std::endl;
                std::cout << "Place tile (P)" << std::endl;

                std::cout << "Enter an action > : ";
                std::cin >> action;

                if (action == "F" || action == "f") {
                    tiles[0].flip();
                    tiles[0].displayTile();
                } else if (action == "R" || action == "r") {
                    tiles[0].rotate();
                    tiles[0].displayTile();
                } else if (action == "P" || action == "p") {
                    // Placer la tuile sur le plateau
                    std::cout << "Enter the position (ex: AC ou CF) > : ";
                    std::string position;
                    std::cin >> position;

                }


            }
        } else if (action == "E" || action == "e" && exchangeTiles > 0) {
            if (!tileQueue.empty()) {
                std::cout << "Tuile échangée.\n";
                tiles.push_back(tileQueue.front());
                tileQueue.pop();

                exchangeTiles--;

            }
        } else if (action == "l" || action == "L") {
            exit(0);
        } else if (action == "D" || action == "d") {

            std::cout << "\nNext Tiles :\n";
            for (size_t i = 1; i < tiles.size(); ++i) {
                tiles[i].displayTile();
            }

            currentTurn--;
            takeTurn(tileQueue);
        } else if (action == "P" || action == "p") {
            std::cout << "Turn skipped" << std::endl;
        } else {
            std::cout << "Action invalide.\n";
            takeTurn(tileQueue);
            currentTurn--;
        }
        // Mettre à jour les tuiles du joueur après son action
        updateTiles(tileQueue);

    }
}

bool Player::hasRemainingTurns() const {
    return currentTurn < 10;
}

// Méthode pour ajouter une tuile d'échange
void Player::addExchangeTile() {
    exchangeTiles++;
}

// Méthode pour obtenir le nombre de tuiles d'échange
int Player::getExchangeTiles() const {
    return exchangeTiles;
}

// Mettre à jour les tuiles du joueur
void Player::updateTiles(std::queue<Tile>& tileQueue) {
    tiles.clear();

    // Ajouter la tuile actuelle + 5 suivantes à la liste du joueur
    for (int i = 0; i < 6 && !tileQueue.empty(); ++i) {
        tiles.push_back(tileQueue.front());
        tileQueue.pop();
    }
}

int Player::getId() const {
    return id;
}

const std::string& Player::getName() const {
    return name;
}

const std::string& Player::getColor() const {
    return color;
}







//Library
#include "iostream"
#include <utility>

//Include
#include "Player.h"
#include "Menu.h"


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
void Player::takeTurn() {
    if (currentTurn < 10) {
        currentTurn++;
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
            // if (!tileQueue.empty()) {
            //     std::cout << "Vous jouez la tuile suivante.\n";
            //     tileQueue.erase(tileQueue.begin());
            // }
        } else if (action == "E" || action == "e" && exchangeTiles > 0) {
            // if (!tileQueue.empty()) {
                // Tile exchangedTile = tileQueue.front();
                // tileQueue.erase(tileQueue.begin());
                // pushTileToEnd(exchangedTile);
                exchangeTiles--;
                std::cout << "Tuile échangée et remise à la fin de la file.\n";
            // }
        } else if (action == "l" || action == "L") {
            exit(0);
        } else if (action == "D" || action == "d") {
            // displayTileQueue();
            takeTurn();
        } else if (action == "P" || action == "p") {
            std::cout << "Turn skipped" << std::endl;
        } else {
            std::cout << "Action invalide.\n";
            takeTurn();
            currentTurn--;
        }
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




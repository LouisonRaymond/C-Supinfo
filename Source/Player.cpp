//Library
#include "iostream"
#include <utility>

//Include
#include "Player.h"


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
    std::cout << "Player " << id << " " << name << " -" << std::endl;
    std::cout << "\033[0m"; // Réinitialiser la couleur
}

// Méthode pour le tour du joueur
void Player::takeTurn() {
    if (currentTurn < 10) {
        currentTurn++;
        std::string action;

        std::cout << "Take tile(T)" << std::endl;
        std::cout << "Exchange tile - " << exchangeTiles << " available (E)" << std::endl;
        std :: cout << "Display queue (D)" << std::endl;

        std::cout << "Enter an action > : ";
        std::cin >> action;

        // Gérer l'action entrée
        if (action == "passer") {
            std::cout << "Le joueur " << name << " passe son tour.\n";
        } else {
            std::cout << "Action '" << action << "' réalisée par " << name << ".\n";
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




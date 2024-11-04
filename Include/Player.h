//
// Created by Anice on 04/11/2024.
//
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Tile.h"

class Player {
public:
    Player(const std::string &name, const std::string &color);

    void addTile(const Tile &tile); // Ajouter une tuile au territoire du joueur
    void useTileExchangeCoupon();   // Utilise un coupon d'échange de tuile
    bool hasExchangeCoupons() const; // Vérifie si le joueur a des coupons d'échange

    std::string getName() const;
    std::string getColor() const;

private:
    std::string name;
    std::string color;
    std::vector<Tile> territory; // Tuiles faisant partie du territoire du joueur
    int exchangeCoupons;         // Nombre de coupons d'échange de tuile
};

#endif // PLAYER_H
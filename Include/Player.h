<<<<<<< Updated upstream
//
// Created by Peon4 on 04/11/2024.
//

#ifndef C_SUPINFO_PLAYER_H
#define C_SUPINFO_PLAYER_H


class Player {
public :


private:


=======
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "../include/Tiles.h"

class Player {
public:



private:
    std::string name;
    std::string color;
    std::vector<Tiles> territory; // Tuiles faisant partie du territoire du joueur
    int exchangeCoupons;         // Nombre de coupons d'échange de tuile
>>>>>>> Stashed changes
};




#endif //C_SUPINFO_PLAYER_H

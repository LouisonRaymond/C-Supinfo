//
// Created by Anice on 04/11/2024.
//
#ifndef TILE_H
#define TILE_H

#include <vector>

class Tile {
public:
    Tile(int id, int width, int height); // Constructeur avec un identifiant et les dimensions de la tuile

    void rotate(); // Méthode pour tourner la tuile
    void flip();   // Méthode pour retourner la tuile

    std::vector<std::vector<bool>> getShape() const; // Renvoie la forme de la tuile
    int getId() const; // Renvoie l'ID de la tuile

private:
    int id;  // Identifiant unique de la tuile
    int width;
    int height;
    std::vector<std::vector<bool>> shape; // Représentation de la tuile en 2D (true pour les cases occupées)
};

#endif // TILE_H
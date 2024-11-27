#pragma once

#include <ctime>
#include <cmath>
#include <vector>
#include "global.hpp"

/// @brief Classe permettant de gérer la création d'une pomme
class Apple
{
    public:
        /// @brief Constructeur, détermine la position aléatoire de la pomme, la position la pomme ne doit pas sortir de la map
        /// @param largeur largeur de la map
        /// @param hauteur hauteur de la map
        /// @param snake_pos position du serpent pour éviter que la pomme n'aparaisse sur le serpent
        Apple(int largeur, int hauteur, std::vector<Position> snake_pos);

        Position get_pos();

    private:
        Position pos;
};

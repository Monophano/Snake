#pragma once

#include <ctime>
#include <cmath>
#include "global.hpp"

/// @brief Classe permettant de gérer la création d'une pomme
class Apple
{
    public:
        /// @brief Constructeur, détermine la position aléatoire de la pomme, la position la pomme ne doit pas sortir de la map
        /// @param largeur largeur de la map
        /// @param hauteur hauteur de la map
        Apple(int largeur, int hauteur);

        Position get_pos();

    private:
        Position pos;
};

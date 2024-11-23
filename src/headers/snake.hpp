#pragma once

#include "global.hpp"
#include <vector>

/// @brief Classe permettant de gérer le fonctionnement du serpent du jeu snake
class Snake
{
    public:
        /// @brief Constructeur, initialise les données
        Snake();

        /// @brief Accesseur de la position du serpent courant
        /// @return Position du serpent courant
        std::vector<Position> get_pos();

        /// @brief Méthode chargé de faire se déplacer le serpent
        /// @param direction direction du serpent
        void deplacer(Direction direction);

        /// @brief Ajoute une taille au serpent
        void add_size();

    private:
        std::vector<Position> pos;
        Direction last_direction;
};

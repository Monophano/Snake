#pragma once

#include "global.hpp"
#include <vector>
#include <cmath>
#include <stdio.h>

/// @brief Classe permettant de gérer le fonctionnement du serpent du jeu snake
class Snake
{
    public:
        /// @brief Constructeur, initialise les données et fait apparaitre le serpent à un endroit aléatoire dans la map
        /// @param largeur largeur de la carte
        /// @param hauteur hauteur de la carte
        Snake(int largeur, int hauteur);

        /// @brief Accesseur de la position du serpent courant
        /// @return Position du serpent courant
        std::vector<Position> get_pos();

        /// @brief Méthode chargé de faire se déplacer le serpent
        /// @param direction direction du serpent
        void deplacer(Direction direction);

        /// @brief Ajoute une taille au serpent
        void add_size();

        /// @brief Méthode chargé de déterminer si le serpent est entré en collision avec lui même ou s'il est sortie de la carte
        /// @return true -> il est en vie | false -> il est mort ;(
        bool is_alive();

    private:
        std::vector<Position> pos;
        Direction last_direction;

        int map_largeur;
        int map_hauteur;
};

#pragma once

#include "global.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

/// @brief Classe permettant de gérer la map du jeu, elle doit être utilisé avec un pointeur et être delete après utilisation
class Grid
{
    public:
        /// @brief Constructeur de la classe
        /// @param largeur largeur de la carte
        /// @param hauteur hauteur de la carte
        /// @param cell_size taille des cellules de la map
        Grid(int largeur, int hauteur, float cell_size);

        ~Grid();

        /// @brief Méthode permettant d'attribuer une valeur à la map
        /// @param pos position de la valeur à attribuer
        /// @param value
        void add_to_grid(Position pos, Tilemap value);

        /// @brief Accesseurs de la valeur de la case à la position en paramètre
        /// @param pos Position de la valeur
        /// @return valeur, -1 si index out of range
        Tilemap get_case_value(Position pos);

        /// @brief Méthode chargé de remplir la map de vide pour éviter que des infos restent trop longtemps
        void update();

        /// @brief Méthode d'affichage de la
        /// @param window fenêtre sfml sur laquelle afficher la grille
        void display(sf::RenderWindow &window);

    private:
        Tilemap **map;

        // variables ne devant être modifier qu'à l'attibution dans le constructeur
        int largeur;
        int hauteur;
        float cell_size;

        std::vector<sf::Color> color = {
            sf::Color(0,0,64), // vide
            sf::Color::Green, // serpent
            sf::Color::Red // pomme
        };
};

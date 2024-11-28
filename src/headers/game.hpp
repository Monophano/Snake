#pragma once

#include "grid.hpp"
#include "apple.hpp"
#include "snake.hpp"
#include "file.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>

/// @brief Classe permettant de gérer la logique du jeu snake, doit être utilisé avec un pointeur
class Game
{
    public:
        /// @brief Constucteur de la classe
        /// @param largeur largeur de la map, à passer au constructeur de grid
        /// @param hauteur hauteur de la map, à passer au constrcuteur de grid
        /// @param cell_size taille des cellules de la carte, à passer au constrcuteur de grid
        Game(int largeur, int hauteur, float cell_size);

        ~Game();

        /// @brief Met à jour la logique de jeu tout les ticks
        void update();

        /// @brief Méthode d'affichage du jeu via sfml
        /// @param window Fenêtre SFML sur laquelle dessiner le jeu
        void display(sf::RenderWindow &window);

        /// @brief Accesseur de l'instance courante du snake, réinstancie si non instancié
        /// @return Instance courante du snake
        Snake* get_instanced_snake();

        /// @brief Accesseur de la direction du snake
        /// @return Direction du snake
        Direction get_snake_direction();

        /// @brief Mutateur de la direction du snake
        /// @param dir nouvelle direction du snake
        void set_snake_direction(Direction dir);

    private:
        Grid *i_grid;
        Apple *i_apple;
        Snake *i_snake;
        File *i_file;

        int grid_hauteur;
        int grid_largeur;
        float grid_cell_size;

        int score;

        Direction direction;
};

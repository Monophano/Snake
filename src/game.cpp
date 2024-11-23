#include "headers/game.hpp"

Game::Game(int largeur, int hauteur, float cell_size)
{
    this->grid_largeur = largeur;
    this->grid_hauteur = hauteur;
    this->grid_cell_size = cell_size;
    this->i_grid = new Grid(largeur, hauteur, cell_size);
    this->i_apple = new Apple(largeur, hauteur);
}

Game::~Game()
{
    if (this->i_grid != nullptr)
        delete this->i_grid;

    if (this->i_apple != nullptr)
        delete this->i_apple;
}

void Game::update()
{
    this->i_grid->update();

    // Positionnement de la pomme sur la carte
    this->i_grid->add_to_grid(this->i_apple->get_pos(), apple);

    // Positionnnement du serpent sur la carte
    for (int i = 0; i < (int)(this->i_snake.get_pos().size()); i++)
        this->i_grid->add_to_grid(this->i_snake.get_pos()[i], snake);

    // on fait se déplacer le snake
    this->i_snake.deplacer(this->direction);

    // s'il mange une pomme, on la réinstancie ailleurs et on ajoute une taille au serpent plus un au score
    if (this->i_grid->get_case_value(this->i_snake.get_pos()[0]) == apple)
    {
        delete this->i_apple;
        this->i_apple = new Apple(this->grid_largeur, this->grid_hauteur);
        this->score++;
        this->i_snake.add_size();
    }
}

void Game::display(sf::RenderWindow &window)
{
    this->i_grid->display(window);
}

Snake Game::get_instanced_snake()
{
    return this->i_snake;
}

void Game::set_snake_direction(Direction dir)
{
    this->direction = dir;
}

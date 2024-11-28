#include "headers/game.hpp"

Game::Game(int largeur, int hauteur, float cell_size)
{
    this->grid_largeur = largeur;
    this->grid_hauteur = hauteur;
    this->grid_cell_size = cell_size;
    this->score = 0;
    this->i_grid = new Grid(largeur, hauteur, cell_size);
    this->i_snake = new Snake(largeur, hauteur);
    this->i_apple = new Apple(largeur, hauteur, this->i_snake->get_pos());
    this->i_file = new File("res/best_score.txt");
}

Game::~Game()
{
    if (this->i_grid != nullptr)
        delete this->i_grid;

    if (this->i_apple != nullptr)
        delete this->i_apple;

    if (this->i_snake != nullptr)
        delete this->i_snake;

    if (this->i_file != nullptr)
        delete this->i_file;
}

void Game::update()
{
    this->i_grid->update();

    // Positionnement de la pomme sur la carte
    this->i_grid->add_to_grid(this->i_apple->get_pos(), apple);

    // Positionnnement du serpent sur la carte
    for (int i = 0; i < (int)(this->i_snake->get_pos().size()); i++)
        this->i_grid->add_to_grid(this->i_snake->get_pos()[i], snake);

    // on fait se déplacer le snake
    this->i_snake->deplacer(this->direction);

    // s'il mange une pomme, on la réinstancie ailleurs et on ajoute une taille au serpent plus un au score
    if (this->i_grid->get_case_value(this->i_snake->get_pos()[0]) == apple)
    {
        delete this->i_apple;
        this->i_apple = new Apple(this->grid_largeur, this->grid_hauteur, this->i_snake->get_pos());
        this->score++;
        this->i_snake->add_size();
    }

    // si le serpent est mort, on vérifie si le score actuelle est le meilleur
    // si oui, on l'écrit dans le fichier, sinon on ne fait rien
    if (!this->i_snake->is_alive())
        if (this->score > (std::stoi)(this->i_file->get_data()))
            this->i_file->set_data(std::to_string(this->score));
}

void Game::display(sf::RenderWindow &window)
{
    // affichage de la map
    this->i_grid->display(window);

    // affichage des yeux du serpent
    sf::CircleShape oeuil(5);
    oeuil.setFillColor(sf::Color::Black);

    switch (this->direction)
    {
        case haut:
            oeuil.setPosition(sf::Vector2f(this->i_snake->get_pos()[0].x * this->grid_cell_size + 3, (this->i_snake->get_pos()[0].y * this->grid_cell_size) + 30));
            window.draw(oeuil);

            oeuil.setPosition(sf::Vector2f((this->i_snake->get_pos()[0].x * this->grid_cell_size) + this->grid_cell_size - 13, (this->i_snake->get_pos()[0].y * this->grid_cell_size) + 30));
            window.draw(oeuil);
            break;

        case bas:
            oeuil.setPosition(sf::Vector2f(this->i_snake->get_pos()[0].x * this->grid_cell_size + 3, (this->i_snake->get_pos()[0].y * this->grid_cell_size)-10));
            window.draw(oeuil);

            oeuil.setPosition(sf::Vector2f((this->i_snake->get_pos()[0].x * this->grid_cell_size) + this->grid_cell_size - 13, (this->i_snake->get_pos()[0].y * this->grid_cell_size)-10));
            window.draw(oeuil);
            break;

        case droite:
            oeuil.setPosition(sf::Vector2f((this->i_snake->get_pos()[0].x * this->grid_cell_size) - 10, (this->i_snake->get_pos()[0].y * this->grid_cell_size) + 3));
            window.draw(oeuil);

            oeuil.setPosition(sf::Vector2f((this->i_snake->get_pos()[0].x * this->grid_cell_size) - 10, (this->i_snake->get_pos()[0].y * this->grid_cell_size) + this->grid_cell_size - 13));
            window.draw(oeuil);
            break;

        case gauche:
            oeuil.setPosition(sf::Vector2f((this->i_snake->get_pos()[0].x * this->grid_cell_size) + this->grid_cell_size, (this->i_snake->get_pos()[0].y * this->grid_cell_size) + 3));
            window.draw(oeuil);

            oeuil.setPosition(sf::Vector2f((this->i_snake->get_pos()[0].x * this->grid_cell_size) + this->grid_cell_size, (this->i_snake->get_pos()[0].y * this->grid_cell_size) + this->grid_cell_size - 13));
            window.draw(oeuil);
            break;
    }

    // affichage du HUD
    sf::Font font;
    font.loadFromFile("./res/font/LiberationSans-Regular.ttf");

    sf::Text txt_score("Score : "+(std::to_string)(this->score), font, 30);
    txt_score.setPosition(sf::Vector2f(10, 0));

    window.draw(txt_score);

    sf::Text txt_best_core("Best score : " + this->i_file->get_data(), font, 30);
    txt_best_core.setPosition(sf::Vector2f(10, 40));

    window.draw(txt_best_core);
}

Snake* Game::get_instanced_snake()
{
    // si non instancié, on réinstancie
    if (this->i_snake == nullptr)
        this->i_snake = new Snake(this->grid_largeur, this->grid_hauteur);
    return this->i_snake; // on retourne l'instance
}

Direction Game::get_snake_direction()
{
    return this->direction;
}

void Game::set_snake_direction(Direction dir)
{
    this->direction = dir;
}

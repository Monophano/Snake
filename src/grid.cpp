#include "headers/grid.hpp"

Grid::Grid(int largeur, int hauteur, float cell_size)
{
    this->largeur = largeur;
    this->hauteur = hauteur;
    this->cell_size = cell_size;

    // allocation du tableau
    this->map = new Tilemap* [this->hauteur];
    for (int ligne = 0; ligne < this->hauteur; ligne++)
        this->map[ligne] = new Tilemap [this->largeur];

    // remplissage du tableau
    for (int ligne = 0; ligne < this->hauteur; ligne++)
    for (int colonne = 0; colonne < this->largeur; colonne++)
        this->map[ligne][colonne] = vide;
}

Grid::~Grid()
{
    for (int i = 0; i < this->hauteur; i++)
        delete[] this->map[i];
    delete[] this->map;
}

void Grid::add_to_grid(Position pos, Tilemap value)
{
    // on vérifie qu'on a pas un index out of range, si non, on attribue, si oui, on fait rien
    if ((pos.x >= 0 && pos.x < this->largeur) && (pos.y >= 0 && pos.y < this->hauteur))
        this->map[pos.y][pos.x] = value;
}

Tilemap Grid::get_case_value(Position pos)
{
    // on vérifie qu'on a pas un index out of range, si non, on renvoie la valeur à la position indiqué, si oui, on renvoie une erreur
    if ((pos.x >= 0 && pos.x < this->largeur) && (pos.y >= 0 && pos.y < this->hauteur))
        return this->map[pos.y][pos.x];
    return erreur;
}

void Grid::update()
{
    for (int ligne = 0; ligne < this->hauteur; ligne++)
    for (int colonne = 0; colonne < this->largeur; colonne++)
        this->map[ligne][colonne] = vide;
}

void Grid::display(sf::RenderWindow &window)
{
    // on affiche comme un tilemap
    sf::RectangleShape cell(sf::Vector2f(this->cell_size, this->cell_size));

    for (int ligne = 0; ligne < this->hauteur; ligne++)
    for (int colonne = 0; colonne < this->largeur; colonne++)
    {
        cell.setFillColor(this->color[this->map[ligne][colonne]]);
        cell.setPosition(sf::Vector2f(colonne * this->cell_size, ligne * this->cell_size));
        window.draw(cell);
    }
}

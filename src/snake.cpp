#include "headers/snake.hpp"

Snake::Snake(int largeur, int hauteur)
{
    // on génère la position aléatoire dans la map
    Position depart;
    depart.x = rand()%(largeur-1);
    depart.y = rand()%(hauteur-1);
    this->pos.push_back(depart);

    // on récupère les données
    this->map_largeur = largeur;
    this->map_hauteur = hauteur;
}

std::vector<Position> Snake::get_pos()
{
    return this->pos;
}

void Snake::deplacer(Direction direction)
{
    // on fait se déplacer le snake
    Position new_pos;
    new_pos.x = this->pos[0].x;
    new_pos.y = this->pos[0].y;

    switch (direction)
    {
        case haut:
            new_pos.y--;
            break;

        case bas:
            new_pos.y++;
            break;

        case droite:
            new_pos.x++;
            break;

        case gauche:
            new_pos.x--;
            break;
    }

    this->pos.insert(this->pos.begin(), new_pos);
    this->pos.pop_back();

    this->last_direction = direction;
}

void Snake::add_size()
{
    Position new_pos;
    new_pos.x = this->pos[0].x;
    new_pos.y = this->pos[0].y;

    switch (this->last_direction)
    {
        case haut:
            new_pos.y--;
            break;

        case bas:
            new_pos.y++;
            break;

        case gauche:
            new_pos.x--;
            break;

        case droite:
            new_pos.x++;
            break;
    }

    this->pos.insert(this->pos.begin(), new_pos);
}

bool Snake::is_alive()
{
    // on vérifie que la tête ne rentre pas en collision avec le corp
    for (int i = 1; i < (int)(this->pos.size()); i++)
        if (this->pos[0].x == this->pos[i].x && this->pos[0].y == this->pos[i].y)
            return false;

    // on vérifie s'il sort de la carte
    if (this->pos[0].x < 0 || this->pos[0].x >= this->map_largeur || this->pos[0].y < 0 || this->pos[0].y >= this->map_hauteur)
        return false;

    return true;
}

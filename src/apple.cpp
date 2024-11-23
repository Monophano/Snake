#include "headers/apple.hpp"

Apple::Apple(int largeur, int hauteur)
{
    srand(time(nullptr));

    this->pos.x = rand()%(largeur-1);
    this->pos.y = rand()%(hauteur-1);
}

Position Apple::get_pos()
{
    return this->pos;
}

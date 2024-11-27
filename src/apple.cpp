#include "headers/apple.hpp"

Apple::Apple(int largeur, int hauteur, std::vector<Position> snake_pos)
{
    srand(time(nullptr));

    bool run = true;

    while (run)
    {
        this->pos.x = rand()%(largeur-1);
        this->pos.y = rand()%(hauteur-1);

        for (int i = 0; i < (int)(snake_pos.size()); i++)
            if (snake_pos[i].x != this->pos.x && snake_pos[i].y != this->pos.y)
                run = false;
    }
}

Position Apple::get_pos()
{
    return this->pos;
}

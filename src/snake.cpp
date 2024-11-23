#include "headers/snake.hpp"

Snake::Snake()
{
    Position depart;
    depart.x = 0;
    depart.y = 0;
    this->pos.push_back(depart);
}

std::vector<Position> Snake::get_pos()
{
    return this->pos;
}

void Snake::deplacer(Direction direction)
{
    Position new_pos;
    new_pos.x = this->pos[0].x;
    new_pos.y = this->pos[0].y;

    if (direction == droite)
        new_pos.x++;

    if (direction == gauche)
        new_pos.x--;

    if (direction == haut)
        new_pos.y--;

    if (direction == bas)
        new_pos.y++;

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

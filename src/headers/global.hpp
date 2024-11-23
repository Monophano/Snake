#pragma once

enum Tilemap
{
    erreur = -1,
    vide = 0,
    snake = 1,
    apple = 2
};

enum Direction
{
    haut = 0,
    bas = 1,
    gauche = 2,
    droite = 3
};

struct Position
{
    int x;
    int y;
};

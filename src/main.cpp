#include "headers/game.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    int map_hauteur = 30;
    int map_largeur = 30;
    float map_cell_size = 10.0f;
    sf::RenderWindow window(sf::VideoMode(map_largeur * map_cell_size, map_hauteur * map_cell_size), "Snake");
    window.setFramerateLimit(5);
    sf::Event event;

    Game *game = new Game(map_largeur, map_hauteur, map_cell_size);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;

                        case sf::Keyboard::Up:
                            game->set_snake_direction(haut);
                            break;

                        case sf::Keyboard::Down:
                            game->set_snake_direction(bas);
                            break;

                        case sf::Keyboard::Left:
                            game->set_snake_direction(gauche);
                            break;

                        case sf::Keyboard::Right:
                            game->set_snake_direction(droite);
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

        game->update();

        window.clear();
        game->display(window);
        window.display();
    }

    delete game;

    return 0;
}

#include "headers/game.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    // paramètres de la fenetre
    int map_hauteur = 20;
    int map_largeur = 20;
    float map_cell_size = 30.0f;

    // instanciation de la fenetre
    sf::RenderWindow window(sf::VideoMode(map_largeur * map_cell_size, map_hauteur * map_cell_size), "Snake");
    sf::Event event;
    window.setFramerateLimit(7);

    Game *game = new Game(map_largeur, map_hauteur, map_cell_size);

    // game loop
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
                            if (game->get_snake_direction() != bas)
                                game->set_snake_direction(haut);
                            break;

                        case sf::Keyboard::Down:
                            if (game->get_snake_direction() != haut)
                                game->set_snake_direction(bas);
                            break;

                        case sf::Keyboard::Left:
                            if (game->get_snake_direction() != droite)
                                game->set_snake_direction(gauche);
                            break;

                        case sf::Keyboard::Right:
                            if (game->get_snake_direction() != gauche)
                                game->set_snake_direction(droite);
                            break;

                        case sf::Keyboard::Space:
                            // Si snake mort et touche espace pressé, on relance le jeu
                            if (!game->get_instanced_snake()->is_alive())
                            {
                                delete game;
                                game = new Game(map_largeur, map_hauteur, map_cell_size);
                            }
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }

        // si le serpent est en vie, on update la logique de jeu
        if (game->get_instanced_snake()->is_alive())
            game->update();

        window.clear();
        game->display(window);

        // si le serpent est mort, on dessine l'écran de fin
        if (!game->get_instanced_snake()->is_alive())
        {
            sf::Font font;
            font.loadFromFile("./res/font/LiberationSans-Regular.ttf");

            sf::Text game_over("Game over", font, 30);
            game_over.setPosition(sf::Vector2f(((map_largeur*map_cell_size)/2)-60,((map_hauteur*map_cell_size)/2)-40));

            sf::Text retry("Press `space` to retry.", font, 20);
            retry.setPosition(sf::Vector2f(((map_largeur*map_cell_size)/2)-85,((map_hauteur*map_cell_size)/2)));

            window.draw(game_over);
            window.draw(retry);
        }

        window.display();

    }

    delete game;

    return 0;
}

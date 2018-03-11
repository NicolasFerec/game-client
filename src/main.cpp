#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Game.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game client", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Clock clock;

    std::shared_ptr<Game> game(new Game());
    std::shared_ptr<Player> player(new Player(3, 6));
    game->players.push_back(player.get());

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    // If escape is pressed, close the application
                    case  sf::Keyboard::Escape :
                        window.close();
                        break;

                        // Process the up, down, left and right keys
                    case sf::Keyboard::Up :
                        player->setY(player->getY()-1);
                        break;
                    case sf::Keyboard::Down:
                        player->setY(player->getY()+1);
                        break;
                    case sf::Keyboard::Left:
                        player->setX(player->getX()-1);
                        break;
                    case sf::Keyboard::Right:
                        player->setX(player->getX()+1);
                        break;
                    default : break;
                }
            }

        }

        game->loop(window, clock);

    }

    return 0;
}
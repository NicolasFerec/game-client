#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Game.h"
#include "Player.h"

#define SFML_STATIC

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Game client", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    std::shared_ptr<Game> game(new Game());
    std::shared_ptr<Player> player(new Player(3, 6));
    game->players.push_back(*player);

    sf::Clock clock;

    while (window.isOpen())
    {
        /*sf::Time frameTime = clock.restart();
        double framerate = 1 / (frameTime.asMilliseconds() * 0.001);
        int roundedFramerate = (int)std::round(framerate);
        std::cout << roundedFramerate << std::endl;*/

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
                        break;
                    case sf::Keyboard::Down:
                        break;
                    case sf::Keyboard::Left:
                        player->setX(player->getX()-1);
                    std::cout << player->getX() << std::endl;
                        break;
                    case sf::Keyboard::Right:
                        player->setX(player->getX()+1);
                        break;
                    default : break;
                }
            }

        }

        game->loop(window);

    }

    return 0;
}
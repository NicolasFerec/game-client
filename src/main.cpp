#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Game.h"

#define SFML_STATIC

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Game client", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    std::shared_ptr<Game> game(new Game());
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time frameTime = clock.restart();
        double framerate = 1 / (frameTime.asMilliseconds() * 0.001);
        int roundedFramerate = (int)std::round(framerate);
        std::cout << roundedFramerate << std::endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game->loop(window);

    }

    return 0;
}
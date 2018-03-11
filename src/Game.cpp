//
// Created by Nicolas Ferec on 07/03/2018.
//

#include <iostream>
#include <cmath>
#include <sstream>
#include "Game.h"

Game::Game() : map{
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}
}{}

void Game::loop(sf::RenderWindow &window, sf::Clock &clock) {

    window.clear(sf::Color::Black);

    int i, j;

    for (i = 0; i < this->map.size(); i++) {
        for ( j = 0; j < this->map[i].size(); j++) {
            int tile = this->map[i][j];
            sf::RectangleShape shape(sf::Vector2f(this->tileWidth, this->tileHeight));
            shape.setOutlineThickness(1);
            shape.setOutlineColor(sf::Color(51, 51, 51));

            switch (tile){
                case 1:
                    shape.setFillColor(sf::Color(193, 144, 19));
                    break;
                case 0:
                default:
                    shape.setFillColor(sf::Color(77, 183, 34));
                    break;
            }

            shape.setPosition(this->tileWidth*j, this->tileHeight*i);
            window.draw(shape);
        }
    }

    int k;

    for(k = 0; k < this->players.size(); k++){
        sf::RectangleShape shape(sf::Vector2f(this->tileWidth / 2, this->tileHeight / 2));
        shape.setFillColor(sf::Color(51, 51, 51));
        shape.setPosition(this->players[k]->getX()*this->tileWidth+this->tileWidth/4, this->players[k]->getY()*this->tileHeight+this->tileHeight/4);
        window.draw(shape);
    }

    sf::Time frameTime = clock.restart();
    double framerate = 1 / (frameTime.asMilliseconds() * 0.001);
    int roundedFramerate = (int)std::round(framerate);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error when font loading" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    std::ostringstream strs;
    strs << roundedFramerate << " FPS";
    std::string str = strs.str();
    text.setString(str);
    text.setCharacterSize(24);
    text.setPosition(10, 5);
    window.draw(text);

    window.display();
}
//
// Created by Nicolas Ferec on 07/03/2018.
//

#include <iostream>
#include "Game.h"

Game::Game() : map{
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}{}

void Game::loop(sf::RenderWindow &window) {

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
        shape.setPosition(this->players[k].getX()*this->tileWidth+this->tileWidth/4, this->players[k].getY()*this->tileHeight+this->tileHeight/4);
        window.draw(shape);
    }

    window.display();
}
//
// Created by Nicolas Ferec on 07/03/2018.
//

#include <SFML/Graphics.hpp>
#include <array>
#include "Player.h"

#ifndef GAME_CLIENT_GAME_H
#define GAME_CLIENT_GAME_H


class Game {
private:
    //sf::Window *window;
    std::vector< std::vector< int > > map;
    const int tileHeight = 50;
    const int tileWidth = 50;


public:
    Game();

    void loop(sf::RenderWindow&, sf::Clock&);

    std::vector< Player* > players;
};


#endif //GAME_CLIENT_GAME_H

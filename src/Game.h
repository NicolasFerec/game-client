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
    int map[10][10];
    const int tileHeight = 50;
    const int tileWidth = 50;
    Player players[];

public:
    Game();

    void loop(sf::RenderWindow& window);
};


#endif //GAME_CLIENT_GAME_H

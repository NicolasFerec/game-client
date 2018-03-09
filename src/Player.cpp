//
// Created by Nicolas Ferec on 08/03/2018.
//

#include "Player.h"

Player::Player(int x, int y) : x(x), y(y){}

int Player::getX() {
    return this->x;
}

int Player::getY() {
    return this->y;
}

void Player::setX(int x) {
    this->x = x;
}

void Player::setY(int y) {
    this->y = y;
}
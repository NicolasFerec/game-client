//
// Created by Nicolas Ferec on 08/03/2018.
//

#ifndef GAME_CLIENT_PLAYER_H
#define GAME_CLIENT_PLAYER_H
#include <vector>

class Player {
private:
    int x = 0;
    int y = 0;

public:
    Player(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};


#endif //GAME_CLIENT_PLAYER_H

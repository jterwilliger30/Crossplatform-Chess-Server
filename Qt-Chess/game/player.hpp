#ifndef PLAYER_H
#define PLAYER_H

enum class Color : bool {
    black = 0, 
    white = 1
};

enum class player_type : bool {
    human = 0,
    computer = 1
};

class Player {
public:
    Color isWhite;
    player_type isHuman;
};
#endif
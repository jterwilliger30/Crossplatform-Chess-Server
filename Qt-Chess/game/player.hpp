#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <map>

class Piece;

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

    std::map<char, std::shared_ptr<Piece>> pieceboard_map;
};
#endif
#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <map>

class Piece;


enum class Color : bool {
    black = 0, 
    white = 1
};

enum class PlayerType : bool {
    human = 0,
    computer = 1
};

class Player {
public:
    Player(Color _isWhite, PlayerType _isHuman, std::shared_ptr<Player> _opposing_player) :
        isWhite(_isWhite),
        isHuman(_isHuman),
        opposing_player(_opposing_player)
    {

    }

    Color isWhite;
    PlayerType isHuman;

    std::shared_ptr<Player> opposing_player;

    std::map<char, std::shared_ptr<Piece>> pieceboard_map;
};
#endif
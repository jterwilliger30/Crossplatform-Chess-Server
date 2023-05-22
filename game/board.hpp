#include "player.hpp"
#include "bitboard.hpp"

#include <iostream>

class Board {
private:
    Player p1;
    Player p2;
public:
    Bitboard *gamestate;
    Board(Player, Player);

    void reset_board();
};


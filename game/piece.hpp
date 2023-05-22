#include "bitboard.hpp"
#include "player.hpp"

class Piece {
public:
    Bitboard bitboard;
    Bitboard* gamestate;

    Player side;

    // Computes the attack and movement bitboards. Varies depending on piece type.
    virtual Bitboard compute_attack() = 0;
    virtual Bitboard compute_movement() = 0;

    virtual void reset_board() = 0;
};
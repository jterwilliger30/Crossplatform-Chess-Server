#ifndef PIECE_H
#define PIECE_H

#include <memory>
#include <string>

#include "bitboard.hpp"
#include "player.hpp"
#include "bit_masks.hpp"

using PlayerSPtr = const std::shared_ptr<Player>;
using BitboardSPtr = const std::shared_ptr<Bitboard>;

class Piece {
public:
    Piece(PlayerSPtr side, BitboardSPtr gamestate, BitboardSPtr opposing_occupied);
    virtual ~Piece() {};

    Bitboard pieceboard;

    BitboardSPtr gamestate;
    BitboardSPtr opposing_occupied;
    PlayerSPtr side;

    std::string unicode_str;

    // Computes the attack and movement bitboards. Varies depending on piece type.
    virtual Bitboard compute_attack(Bitboard board);
    //virtual Bitboard compute_movement() = 0;

    virtual void reset_board();
};
#endif
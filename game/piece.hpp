#pragma once

#include "bitboard.hpp"
#include "player.hpp"
#include "bit_masks.hpp"

class Piece {
public:
    Piece(Player *const side, Bitboard *const gamestate, Bitboard *const opposing_occupied);
    virtual ~Piece() {};

    Bitboard pieceboard;
    Bitboard *const gamestate;
    Bitboard *const opposing_occupied;

    Player *const side;

    // Computes the attack and movement bitboards. Varies depending on piece type.
    virtual Bitboard compute_attack() = 0;
    //virtual Bitboard compute_movement() = 0;

    virtual void reset_board() = 0;
};
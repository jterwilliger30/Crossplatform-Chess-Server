#pragma once

#include "../piece.hpp"

class Rookboard : public Piece {
public:
    Rookboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied);

    Bitboard compute_attack() override;

    void reset_board() override;
};
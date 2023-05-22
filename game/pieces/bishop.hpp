#pragma once

#include "../piece.hpp"

class Bishopboard : public Piece {
public:
    Bishopboard(Player s, Bitboard *gamestate);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
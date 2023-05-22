#pragma once

#include "../piece.hpp"

class Kingboard : public Piece {
public:
    Kingboard(Player s, Bitboard *gamestate);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
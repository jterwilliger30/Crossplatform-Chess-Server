#pragma once

#include "../piece.hpp"

class Queenboard : public Piece {
public:
    Queenboard(Player s, Bitboard *gamestate);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
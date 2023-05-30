#pragma once

#include "../piece.hpp"

class Knightboard : public Piece {
public:
    Knightboard(Player *s, Bitboard *gamestate);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
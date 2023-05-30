#pragma once

#include "../piece.hpp"

class Rookboard : public Piece {
public:
    Rookboard(Player *s, Bitboard *gamestate);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
#pragma once

#include "../piece.hpp"

class Knightboard : public Piece {
public:
    Knightboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
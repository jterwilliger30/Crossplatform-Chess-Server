#pragma once

#include "../piece.hpp"

class Queenboard : public Piece {
public:
    Queenboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied);

    Bitboard compute_attack() override;

    void reset_board() override;
};
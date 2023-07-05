#pragma once

#include "../piece.hpp"

class Pawnboard : public Piece {
public:
    Pawnboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack() override;

    void reset_board() override;
};
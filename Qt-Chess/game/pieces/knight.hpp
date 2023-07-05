#pragma once

#include "../piece.hpp"

class Knightboard : public Piece {
public:
    Knightboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack() override;

    void reset_board() override;
};
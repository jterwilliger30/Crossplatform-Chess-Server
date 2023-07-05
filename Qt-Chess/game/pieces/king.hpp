#pragma once

#include "../piece.hpp"

class Kingboard : public Piece {
public:
    Kingboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack() override;

    void reset_board() override;
};
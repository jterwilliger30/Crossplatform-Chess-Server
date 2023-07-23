#ifndef PAWN_H
#define PAWN_H

#include "../piece.hpp"

class Pawnboard : public Piece {
public:
    Pawnboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack(Bitboard) override;

    void reset_board() override;
};
#endif
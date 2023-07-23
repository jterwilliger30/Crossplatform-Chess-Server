#ifndef ROOK_H
#define ROOK_H

#include "../piece.hpp"

class Rookboard : public Piece {
public:
    Rookboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack(Bitboard) override;

    void reset_board() override;
};
#endif
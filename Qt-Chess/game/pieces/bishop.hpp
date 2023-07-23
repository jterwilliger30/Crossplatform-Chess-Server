#ifndef BISHOP_H
#define BISHOP_H

#include "../piece.hpp"

class Bishopboard : public Piece {
public:
    Bishopboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack(Bitboard board) override;

    void reset_board() override;
};
#endif
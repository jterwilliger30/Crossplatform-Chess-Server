#ifndef QUEEN_H
#define QUEEN_H

#include "../piece.hpp"

class Queenboard : public Piece {
public:
    Queenboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied);

    Bitboard compute_attack(Bitboard) override;

    void reset_board() override;
};
#endif
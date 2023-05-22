#include "../piece.hpp"

class Pawnboard : public Piece {
public:
    Pawnboard(Player);

    Bitboard compute_attack() override;
    Bitboard compute_movement() override;

    void reset_board() override;
};
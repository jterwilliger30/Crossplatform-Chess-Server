#include "piece.hpp"

Piece::Piece(PlayerSPtr side, BitboardSPtr gamestate, BitboardSPtr opposing_occupied) :
    gamestate(gamestate),
    opposing_occupied(opposing_occupied),
    side(side)
{
    // Nuthin...
}

Bitboard Piece::compute_attack(Bitboard board)
{
    throw std::invalid_argument("Compute attack must be overridden...");
}
void Piece::reset_board()
{
    throw std::invalid_argument("Reset board must be overridden...");
}
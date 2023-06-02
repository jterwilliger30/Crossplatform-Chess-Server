#include "piece.hpp"

Piece::Piece(Player *const side, Bitboard *const gamestate, Bitboard *const opposing_occupied) :
    gamestate(gamestate),
    opposing_occupied(opposing_occupied),
    side(side)
{
    // Nuthin...
}
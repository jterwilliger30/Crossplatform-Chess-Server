#include "piece.hpp"

Piece::Piece(PlayerSPtr side, BitboardSPtr gamestate, BitboardSPtr opposing_occupied) :
    gamestate(gamestate),
    opposing_occupied(opposing_occupied),
    side(side)
{
    // Nuthin...
}
#include "./queen.hpp"


Queenboard::Queenboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied) :
    Piece(s, gamestate, opposing_occupied)
{
    // Nuthin...
}

Bitboard Queenboard::compute_attack()
{

}

Bitboard Queenboard::compute_movement()
{

}

void Queenboard::reset_board()
{
    // Set white queen
    if ((bool) this->side->isWhite)
    {
        pieceboard.set_bit(Spot::D1);
    }
    // Set black queen
    else
    {
        pieceboard.set_bit(Spot::D8);
    }

}
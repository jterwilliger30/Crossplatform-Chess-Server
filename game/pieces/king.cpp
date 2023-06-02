#include "./king.hpp"


Kingboard::Kingboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied) :
    Piece(s, gamestate, opposing_occupied)
{
    // Nuthin..
}

Bitboard Kingboard::compute_attack()
{

}

Bitboard Kingboard::compute_movement()
{

}

void Kingboard::reset_board()
{
    // Set white king
    if ((bool) this->side->isWhite)
    {
        pieceboard.set_bit(Spot::E1);
    }
    // Set black king
    else
    {
        pieceboard.set_bit(Spot::E8);
    }

}
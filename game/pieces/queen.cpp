#include "./queen.hpp"


Queenboard::Queenboard(Player s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
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
    if ((bool) this->side.isWhite)
    {
        bitboard.set_bit(Spot::D1);
    }
    // Set black queen
    else
    {
        bitboard.set_bit(Spot::D8);
    }

}
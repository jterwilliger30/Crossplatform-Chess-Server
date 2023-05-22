#include "./king.hpp"


Kingboard::Kingboard(Player s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
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
    if ((bool) this->side.isWhite)
    {
        bitboard.set_bit(Spot::E1);
    }
    // Set black king
    else
    {
        bitboard.set_bit(Spot::E8);
    }

}
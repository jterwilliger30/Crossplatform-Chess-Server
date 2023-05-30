#include "./knight.hpp"


Knightboard::Knightboard(Player *s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
}

Bitboard Knightboard::compute_attack()
{

}

Bitboard Knightboard::compute_movement()
{

}

void Knightboard::reset_board()
{
    // Set white knights
    if ((bool) this->side->isWhite)
    {
        pieceboard.set_bit(Spot::B1);
        pieceboard.set_bit(Spot::G1);
    }
    // Set black knights
    else
    {
        pieceboard.set_bit(Spot::B8);
        pieceboard.set_bit(Spot::G8);
    }

}
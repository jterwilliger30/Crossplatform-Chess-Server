#include "./bishop.hpp"

Bishopboard::Bishopboard(Player *s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
}

Bitboard Bishopboard::compute_attack()
{

}

Bitboard Bishopboard::compute_movement()
{

}

void Bishopboard::reset_board()
{
    // Set white bishops
    if ((bool) this->side->isWhite)
    {
        pieceboard.set_bit(Spot::C1);
        pieceboard.set_bit(Spot::F1);
    }
    // Set black bishops
    else
    {
        pieceboard.set_bit(Spot::C8);
        pieceboard.set_bit(Spot::F8);
    }

}
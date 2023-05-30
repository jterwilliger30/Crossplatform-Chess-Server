#include "./rook.hpp"


Rookboard::Rookboard(Player *s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
}

Bitboard Rookboard::compute_attack()
{
    uint64_t attacks = 0;
    for (int i = 0; i < 8; i++)
    {
        
    }
}

Bitboard Rookboard::compute_movement()
{

}

void Rookboard::reset_board()
{
    // Set white rooks
    if ((bool) this->side->isWhite)
    {
        pieceboard.set_bit(Spot::A1);
        pieceboard.set_bit(Spot::H1);
    }
    // Set black rooks
    else
    {
        pieceboard.set_bit(Spot::A8);
        pieceboard.set_bit(Spot::H8);
    }

}
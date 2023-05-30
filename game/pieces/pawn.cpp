#include "./pawn.hpp"

Pawnboard::Pawnboard(Player *s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
}

Bitboard Pawnboard::compute_attack()
{
    pieceboard 
}

Bitboard Pawnboard::compute_movement()
{
    // Pawns are the only piece where the computation differs depending on white/black
    if ((bool) side->isWhite)
    {

    }
    else
    {

    }


}

void Pawnboard::reset_board()
{
    // Set White Pawns
    if ((bool) side->isWhite)
    {
        pieceboard.set_bit(Spot::A2);
        pieceboard.set_bit(Spot::B2);
        pieceboard.set_bit(Spot::C2);
        pieceboard.set_bit(Spot::D2);
        pieceboard.set_bit(Spot::E2);
        pieceboard.set_bit(Spot::F2);
        pieceboard.set_bit(Spot::G2);
        pieceboard.set_bit(Spot::H2);
    }
    // Set Black Pawns
    else
    {
        pieceboard.set_bit(Spot::A7);
        pieceboard.set_bit(Spot::B7);
        pieceboard.set_bit(Spot::C7);
        pieceboard.set_bit(Spot::D7);
        pieceboard.set_bit(Spot::E7);
        pieceboard.set_bit(Spot::F7);
        pieceboard.set_bit(Spot::G7);
        pieceboard.set_bit(Spot::H7);
    }
}
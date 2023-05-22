#include "./pawn.hpp"

Pawnboard::Pawnboard(Player s, Bitboard* gamestate)
{
    this->side = s;
    this->gamestate = gamestate;
}

Bitboard Pawnboard::compute_attack()
{

}

Bitboard Pawnboard::compute_movement()
{

}

void Pawnboard::reset_board()
{
    // Set White Pawns
    if ((bool) this->side.isWhite)
    {
        bitboard.set_bit(Spot::A2);
        bitboard.set_bit(Spot::B2);
        bitboard.set_bit(Spot::C2);
        bitboard.set_bit(Spot::D2);
        bitboard.set_bit(Spot::E2);
        bitboard.set_bit(Spot::F2);
        bitboard.set_bit(Spot::G2);
        bitboard.set_bit(Spot::H2);
    }
    // Set Black Pawns
    else
    {
        bitboard.set_bit(Spot::A7);
        bitboard.set_bit(Spot::B7);
        bitboard.set_bit(Spot::C7);
        bitboard.set_bit(Spot::D7);
        bitboard.set_bit(Spot::E7);
        bitboard.set_bit(Spot::F7);
        bitboard.set_bit(Spot::G7);
        bitboard.set_bit(Spot::H7);
    }
}
#include "./pawn.hpp"

Pawnboard::Pawnboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied) :
    Piece(s, gamestate, opposing_occupied)
{
    // Nuthin...
}

Bitboard Pawnboard::compute_attack()
{
    // Pawns are the only piece where the computation differs depending on white/black
    uint64_t attack = 0, movement = 0;
    if ((bool) side->isWhite)
    {
        attack |= (~(uint64_t) File_Mask::File_A & pieceboard.bitboard) << 9;
        attack |= (~(uint64_t) File_Mask::File_H & pieceboard.bitboard) << 7;
        attack &= opposing_occupied->bitboard;

        movement |= (pieceboard.bitboard << 8) & ~gamestate->bitboard;
        movement |= (((uint64_t) Rank_Mask::Rank_2 & pieceboard.bitboard) << 16) & ~gamestate->bitboard;

        return Bitboard(attack | movement);
    }
    else
    {
        attack |= (~(uint64_t) File_Mask::File_A & pieceboard.bitboard) >> 7;
        attack |= (~(uint64_t) File_Mask::File_H & pieceboard.bitboard) >> 9;
        attack &= opposing_occupied->bitboard;

        movement = (pieceboard.bitboard >> 8) & ~gamestate->bitboard;
        movement |= (((uint64_t) Rank_Mask::Rank_7 & pieceboard.bitboard) >> 16) & ~gamestate->bitboard;

        return Bitboard(attack | movement);
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
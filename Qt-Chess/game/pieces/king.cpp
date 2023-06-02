#include "./king.hpp"


Kingboard::Kingboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied) :
    Piece(s, gamestate, opposing_occupied)
{
    // Nuthin..
}

Bitboard Kingboard::compute_attack()
{
    /* NOTE: To reduce complexity, the computation to detect whether an opposing piece is attacking
    a square the king could otherwise move into is not done here */
    uint64_t movement = 0;

    movement |= pieceboard.bitboard << 8;                                   // N
    movement |= (pieceboard.bitboard & ~(uint64_t) File_Mask::File_H) << 7; // NE
    movement |= (pieceboard.bitboard & ~(uint64_t) File_Mask::File_H) >> 1; // E
    movement |= (pieceboard.bitboard & ~(uint64_t) File_Mask::File_H) >> 9; // SE
    movement |= pieceboard.bitboard >> 8;                                   // S
    movement |= (pieceboard.bitboard & ~(uint64_t) File_Mask::File_A) >> 7; // SW
    movement |= (pieceboard.bitboard & ~(uint64_t) File_Mask::File_A) << 1; // W
    movement |= (pieceboard.bitboard & ~(uint64_t) File_Mask::File_A) << 9; // NW

    // King can move anywhere except into spots occupied by friendly pieces
    movement &= ~(gamestate->bitboard ^ opposing_occupied->bitboard);

    return Bitboard(movement);
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
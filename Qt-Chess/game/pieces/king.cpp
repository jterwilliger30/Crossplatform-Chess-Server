#include "./king.hpp"


Kingboard::Kingboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied) :
    Piece(player, gamestate, opposing_occupied)
{
    unicode_str = (static_cast<bool>(player->isWhite) ? "\u265A" : "\u2654");
}

Bitboard Kingboard::compute_attack(Bitboard board)
{
    /* NOTE: To reduce complexity, the computation to detect whether an opposing piece is attacking
    a square the king could otherwise move into is not done here */
    uint64_t movement = 0;

    movement |= board.bitboard << 8;                                   // N
    movement |= (board.bitboard & ~(uint64_t) File_Mask::File_H) << 7; // NE
    movement |= (board.bitboard & ~(uint64_t) File_Mask::File_H) >> 1; // E
    movement |= (board.bitboard & ~(uint64_t) File_Mask::File_H) >> 9; // SE
    movement |= board.bitboard >> 8;                                   // S
    movement |= (board.bitboard & ~(uint64_t) File_Mask::File_A) >> 7; // SW
    movement |= (board.bitboard & ~(uint64_t) File_Mask::File_A) << 1; // W
    movement |= (board.bitboard & ~(uint64_t) File_Mask::File_A) << 9; // NW

    // King can move anywhere except into spots occupied by friendly pieces
    movement &= ~(gamestate->bitboard ^ opposing_occupied->bitboard);

    return Bitboard(movement);
}


void Kingboard::reset_board()
{
    // Set white king
    if (static_cast<bool>(side->isWhite))
    {
        pieceboard.set_bit(Spot::E1);
    }
    // Set black king
    else
    {
        pieceboard.set_bit(Spot::E8);
    }

}
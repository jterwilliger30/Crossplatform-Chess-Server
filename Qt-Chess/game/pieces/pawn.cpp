#include "./pawn.hpp"

Pawnboard::Pawnboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied) :
    Piece(player, gamestate, opposing_occupied)
    {
        unicode_str = (static_cast<bool>(player->isWhite) ? "\u265F" : "\u2659");
    }

Bitboard Pawnboard::compute_attack()
{
    // Pawns are the only piece where the computation differs depending on white/black
    uint64_t attack = 0, movement = 0;
    if (static_cast<bool>(side->isWhite))
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
    if (static_cast<bool>(side->isWhite))
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
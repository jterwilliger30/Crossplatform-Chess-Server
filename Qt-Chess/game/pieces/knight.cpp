#include "./knight.hpp"


Knightboard::Knightboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied) :
    Piece(player, gamestate, opposing_occupied)
    { /* Nuthin... */ }

Bitboard Knightboard::compute_attack()
{
    uint64_t ls_attack = 0, rs_attack = 0;

    uint64_t AB_mask = (uint64_t) File_Mask::File_A | (uint64_t) File_Mask::File_B;
    uint64_t GH_mask = (uint64_t) File_Mask::File_G | (uint64_t) File_Mask::File_H;
    
    ls_attack |= (~AB_mask & pieceboard.bitboard) << 10;
    rs_attack |= (~AB_mask & pieceboard.bitboard) >> 6;

    ls_attack |= (~(uint64_t) File_Mask::File_A & pieceboard.bitboard) << 17;
    rs_attack |= (~(uint64_t) File_Mask::File_A & pieceboard.bitboard) >> 15;

    ls_attack |= (~(uint64_t) File_Mask::File_H & pieceboard.bitboard) << 15;
    rs_attack |= (~(uint64_t) File_Mask::File_H & pieceboard.bitboard) >> 17;

    ls_attack |= (~GH_mask & pieceboard.bitboard) << 6;
    rs_attack |= (~GH_mask & pieceboard.bitboard) >> 10;

    return Bitboard(ls_attack | rs_attack);

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
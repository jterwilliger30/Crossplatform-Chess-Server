#include "./rook.hpp"


Rookboard::Rookboard(Player *const s, Bitboard *const gamestate, Bitboard *const opposing_occupied) :
    Piece(s, gamestate, opposing_occupied)
{
    // Nuthin...
}

Bitboard Rookboard::compute_attack()
{
    uint64_t attacks = 0;
    for (int i = 0; i < 8; i++)
    {
        uint64_t attack = 0;
        

        uint64_t temp_north = 0, temp_east = 0, temp_south = 0, temp_west = 0;
        temp_north = temp_east = temp_south = temp_west = pieceboard.bitboard;

        for (int i=0; i < 8; i++)
        {
            temp_north <<= 8;
            if (bool flag = temp_north & gamestate->bitboard)
            {

            }
        }
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
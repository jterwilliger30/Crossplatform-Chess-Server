#include "./rook.hpp"


Rookboard::Rookboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied) :
    Piece(player, gamestate, opposing_occupied)
    {
        unicode_str = (static_cast<bool>(player->isWhite) ? "\u265C" : "\u2656");
    }

Bitboard Rookboard::compute_attack()
{
    uint64_t attack = 0;

    uint64_t temp_N, temp_E, temp_S, temp_W;
    temp_N = temp_E = temp_S = temp_W = pieceboard.bitboard;

    bool flag;

    for (int i=0; i < 7; i++)
    {

        /*
            NORTH ATTACKS
        */

        temp_N <<= 8;
        
        if ((flag = temp_N & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_N & opposing_occupied->bitboard)
            {
                attack |= (temp_N & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_N &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_N;

        /*
            EAST ATTACkS
        */

        // If rightmost file, can't move right anymore
        if (temp_E & (uint64_t) File_Mask::File_H)
        {
            temp_E &= ~(uint64_t) File_Mask::File_H;
        }

        temp_E >>= 1;

        if ((flag = temp_E & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_E & opposing_occupied->bitboard)
            {
                attack |= (temp_E & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_E &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_E;
        

        /*
            SOUTH ATTACkS
        */
        temp_S >>= 8;

        if ((flag = temp_S & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_S & opposing_occupied->bitboard)
            {
                attack |= (temp_S & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_S &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_S;


        /* 
            WEST ATTACkS
        */ 

        // If leftmost file, can't move left anymore
        if (temp_W & (uint64_t) File_Mask::File_A)
        {
            temp_W &= ~(uint64_t) File_Mask::File_A;
        }

        temp_W <<= 1;

        if ((flag = temp_W & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_W & opposing_occupied->bitboard)
            {
                attack |= (temp_W & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_W &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_W;
    }

    return attack;
}

void Rookboard::reset_board()
{
    // Set white rooks
    if (static_cast<bool>(side->isWhite))
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
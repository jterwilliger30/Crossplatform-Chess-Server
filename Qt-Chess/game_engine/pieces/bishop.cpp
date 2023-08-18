#include "./bishop.hpp"

Bishopboard::Bishopboard(const std::shared_ptr<Player> player, const std::shared_ptr<Bitboard> gamestate, const std::shared_ptr<Bitboard> opposing_occupied) :
    Piece(player, gamestate, opposing_occupied)
    {
        unicode_str = (static_cast<bool>(player->isWhite) ? "\u265D" : "\u2657");
    }

Bitboard Bishopboard::compute_attack(Bitboard board)
{
    uint64_t attack = 0;

    uint64_t temp_NE, temp_SE, temp_SW, temp_NW;
    temp_NE = temp_SE = temp_SW = temp_NW = board.bitboard;

    bool flag;

    for (int i=0; i < 7; i++)
    {
        /*
            NORTHEAST ATTACKS
        */

        // If rightmost file, can't move right anymore
        if (temp_NE & (uint64_t) File_Mask::File_H)
        {
            temp_NE &= ~(uint64_t) File_Mask::File_H;
        }
        
        temp_NE <<= 7;
        
        if ((flag = temp_NE & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_NE & opposing_occupied->bitboard)
            {
                attack |= (temp_NE & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_NE &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_NE;


        /*
            SOUTHEAST ATTACKS
        */

        // If rightmost file, can't move right anymore
        if (temp_SE & (uint64_t) File_Mask::File_H)
        {
            temp_SE &= ~(uint64_t) File_Mask::File_H;
        }
        
        temp_SE >>= 9;
        
        if ((flag = temp_SE & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_SE & opposing_occupied->bitboard)
            {
                attack |= (temp_SE & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_SE &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_SE;
        

        /*
            SOUTHWEST ATTACKS
        */

        // If leftmost file, can't move left anymore
        if (temp_SW & (uint64_t) File_Mask::File_A)
        {
            temp_SW &= ~(uint64_t) File_Mask::File_A;
        }
        
        temp_SW >>= 7;
        
        if ((flag = temp_SW & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_SW & opposing_occupied->bitboard)
            {
                attack |= (temp_SW & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_SW &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_SW;


        /*
            NORTHWEST ATTACKS
        */

        // If leftmost file, can't move left anymore
        if (temp_NW & (uint64_t) File_Mask::File_A)
        {
            temp_NW &= ~(uint64_t) File_Mask::File_A;
        }
        
        temp_NW <<= 9;
        
        if ((flag = temp_NW & gamestate->bitboard)) // Encountered Obstruction
        {
            // Obstruction is opposing player
            if (temp_NW & opposing_occupied->bitboard)
            {
                attack |= (temp_NW & opposing_occupied->bitboard);
            }

            // This piece can't move further
            temp_NW &= ~gamestate->bitboard;
        }
        // Add intermediate space to possible movement (i.e. no obstruction)
        attack |= temp_NW;
    }

    return attack;
}

void Bishopboard::reset_board()
{
    // Set white bishops
    if (static_cast<bool>(side->isWhite))
    {
        pieceboard.set_bit(Spot::C1);
        pieceboard.set_bit(Spot::F1);
    }
    // Set black bishops
    else
    {
        pieceboard.set_bit(Spot::C8);
        pieceboard.set_bit(Spot::F8);
    }

}
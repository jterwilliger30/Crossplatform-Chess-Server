#include "./board.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"

Board::Board(Player a, Player b)
{
    this->p1 = a;
    this->p2 = b;

    reset_board();
}

void Board::reset_board()
{
    Pawnboard p1_pawn(p1, gamestate);
    Pawnboard p2_pawn(p2, gamestate);
    p1_pawn.reset_board();
    p2_pawn.reset_board();

    Bishopboard p1_bishop(p1, gamestate);
    Bishopboard p2_bishop(p2, gamestate);
    p1_bishop.reset_board();
    p2_bishop.reset_board();

    Rookboard p1_rook(p1, gamestate);
    Rookboard p2_rook(p2, gamestate);
    p1_rook.reset_board();
    p2_rook.reset_board(); 

    Knightboard p1_knight(p1, gamestate);
    Knightboard p2_knight(p2, gamestate);
    p1_knight.reset_board();
    p2_knight.reset_board(); 

    Queenboard p1_queen(p1, gamestate);
    Queenboard p2_queen(p2, gamestate);
    p1_queen.reset_board();
    p2_queen.reset_board(); 

    Kingboard p1_king(p1, gamestate);
    Kingboard p2_king(p2, gamestate);
    p1_king.reset_board();
    p2_king.reset_board(); 


    gamestate->bitboard = 
        p2_pawn.bitboard.bitboard | p1_pawn.bitboard.bitboard | 
        p2_bishop.bitboard.bitboard | p1_bishop.bitboard.bitboard | 
        p2_rook.bitboard.bitboard | p1_rook.bitboard.bitboard |
        p2_knight.bitboard.bitboard | p1_knight.bitboard.bitboard |
        p2_queen.bitboard.bitboard | p1_queen.bitboard.bitboard |
        p2_king.bitboard.bitboard | p1_king.bitboard.bitboard;
}
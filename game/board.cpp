#include "./board.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"

Board::Board(Player *a, Player *b) :
p1_pawn(a, gamestate),
p2_pawn(b, gamestate),
p1_bishop(a, gamestate),
p2_bishop(b, gamestate),
p1_rook(a, gamestate),
p2_rook(b, gamestate),
p1_knight(a, gamestate),
p2_knight(b, gamestate),
p1_queen(a, gamestate),
p2_queen(b, gamestate),
p1_king(a, gamestate),
p2_king(b, gamestate)
{
    gamestate = new Bitboard();
    reset_board();
}

Board::~Board()
{

}

void Board::update_board_state()
{
    gamestate->bitboard = 
        p2_pawn.pieceboard.bitboard | p1_pawn.pieceboard.bitboard | 
        p2_bishop.pieceboard.bitboard | p1_bishop.pieceboard.bitboard | 
        p2_rook.pieceboard.bitboard | p1_rook.pieceboard.bitboard |
        p2_knight.pieceboard.bitboard | p1_knight.pieceboard.bitboard |
        p2_queen.pieceboard.bitboard | p1_queen.pieceboard.bitboard |
        p2_king.pieceboard.bitboard | p1_king.pieceboard.bitboard;
}

void Board::reset_board()
{
    p1_pawn.reset_board();
    p2_pawn.reset_board();

    p1_bishop.reset_board();
    p2_bishop.reset_board();

    p1_rook.reset_board();
    p2_rook.reset_board(); 

    p1_knight.reset_board();
    p2_knight.reset_board(); 

    p1_queen.reset_board();
    p2_queen.reset_board(); 

    p1_king.reset_board();
    p2_king.reset_board(); 

    update_board_state();
}
#include "./board.hpp"

#include <array>
#include <bitset>
#include <iostream>

#include "piece.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"

Board::Board(PlayerSPtr p1, PlayerSPtr p2, BitboardSPtr GAMESTATE, BitboardSPtr P1_OCCUPIED, BitboardSPtr P2_OCCUPIED) :
    gamestate(GAMESTATE),
    p1_occupied(P1_OCCUPIED),
    p2_occupied(P2_OCCUPIED),

    player1(p1),
    player2(p2),

    p1_pawn(std::make_shared<Pawnboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_bishop(std::make_shared<Bishopboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_rook(std::make_shared<Rookboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_knight(std::make_shared<Knightboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_queen(std::make_shared<Queenboard>(p1, GAMESTATE, P2_OCCUPIED)),
    p1_king(std::make_shared<Kingboard>(p1, GAMESTATE, P2_OCCUPIED)),

    p2_pawn(std::make_shared<Pawnboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_bishop(std::make_shared<Bishopboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_rook(std::make_shared<Rookboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_knight(std::make_shared<Knightboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_queen(std::make_shared<Queenboard>(p2, GAMESTATE, P1_OCCUPIED)),
    p2_king(std::make_shared<Kingboard>(p2, GAMESTATE, P1_OCCUPIED))
{
    reset_board();
}

void Board::update_board_state()
{
    p1_occupied->bitboard =
        p1_pawn->pieceboard.bitboard |
        p1_bishop->pieceboard.bitboard |
        p1_rook->pieceboard.bitboard |
        p1_knight->pieceboard.bitboard |
        p1_queen->pieceboard.bitboard |
        p1_king->pieceboard.bitboard;

    p2_occupied->bitboard =
        p2_pawn->pieceboard.bitboard |
        p2_bishop->pieceboard.bitboard |
        p2_rook->pieceboard.bitboard |
        p2_knight->pieceboard.bitboard |
        p2_queen->pieceboard.bitboard |
        p2_king->pieceboard.bitboard;

    gamestate->bitboard = p2_occupied->bitboard | p1_occupied->bitboard;
}

void Board::reset_board()
{
    p1_pawn->reset_board();
    p2_pawn->reset_board();

    p1_bishop->reset_board();
    p2_bishop->reset_board();

    p1_rook->reset_board();
    p2_rook->reset_board(); 

    p1_knight->reset_board();
    p2_knight->reset_board(); 

    p1_queen->reset_board();
    p2_queen->reset_board(); 

    p1_king->reset_board();
    p2_king->reset_board(); 

    update_board_state();
}

void Board::print_board()
{
    for (int i = 0; i < 64; i++)
    {
        //if (p1_pawn->pieceboard.bitboard)

    }
}

void Board::preview_turn(PlayerSPtr)
{

}

void Board::take_turn(PlayerSPtr, Spot start, Spot end)
{

}
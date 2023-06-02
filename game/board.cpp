#include "./board.hpp"

#include <array>
#include <bitset>
#include <utility>
#include <iostream>

#include "piece.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"



Board::Board(Player *const p1, Player *const p2, Bitboard *const GAMESTATE, Bitboard *const P1_OCCUPIED, Bitboard *const P2_OCCUPIED) :
    gamestate(GAMESTATE),
    p1_occupied(P1_OCCUPIED),
    p2_occupied(P2_OCCUPIED),

    player1(p1),
    player2(p2),

    p1_pawn(new Pawnboard(p1, GAMESTATE, P2_OCCUPIED)),
    p1_bishop(new Bishopboard(p1, GAMESTATE, P2_OCCUPIED)),
    p1_rook(new Rookboard(p1, GAMESTATE, P2_OCCUPIED)),
    p1_knight(new Knightboard(p1, GAMESTATE, P2_OCCUPIED)),
    p1_queen(new Queenboard(p1, GAMESTATE, P2_OCCUPIED)),
    p1_king(new Kingboard(p1, GAMESTATE, P2_OCCUPIED)),

    p2_pawn(new Pawnboard(p2, GAMESTATE, P1_OCCUPIED)),
    p2_bishop(new Bishopboard(p2, GAMESTATE, P1_OCCUPIED)),
    p2_rook(new Rookboard(p2, GAMESTATE, P1_OCCUPIED)),
    p2_knight(new Knightboard(p2, GAMESTATE, P1_OCCUPIED)),
    p2_queen(new Queenboard(p2, GAMESTATE, P1_OCCUPIED)),
    p2_king(new Kingboard(p2, GAMESTATE, P1_OCCUPIED))
{
    reset_board();
}

Board::~Board()
{
    delete p1_pawn;
    delete p1_bishop;
    delete p1_rook;
    delete p1_knight;
    delete p1_queen;
    delete p1_king;

    delete p2_pawn;
    delete p2_bishop;
    delete p2_rook;
    delete p2_knight;
    delete p2_queen;
    delete p2_king;
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

void Board::print_lettered_board()
{
    std::array<std::string, 64> lettered_board;
    for (int i=0; i < 64; i++)
    {
        lettered_board[i] = ". ";
    }

    std::bitset<64> bs;

    std::array<std::pair<Piece*, std::string>, 12> pieces =
    {
        std::make_pair(p1_pawn, "P "),
        std::make_pair(p1_rook, "R "),
        std::make_pair(p1_knight, "K "),
        std::make_pair(p1_bishop, "B "),
        std::make_pair(p1_queen, "Q "),
        std::make_pair(p1_king, "Kn"),

        std::make_pair(p2_pawn, "p "),
        std::make_pair(p2_rook, "r "),
        std::make_pair(p2_knight, "k "),
        std::make_pair(p2_bishop, "b "),
        std::make_pair(p2_queen, "q "),
        std::make_pair(p2_king, "kn")
    };

    for (int pc_idx=0; pc_idx < 12; pc_idx++)
    {
        bs = pieces[pc_idx].first->pieceboard.bitboard;
        for (int b_idx=0; b_idx < 64; b_idx++)
        {
            if (bs[63 - b_idx]) lettered_board[b_idx] = pieces[pc_idx].second;
        }
    }

    for (int i=0; i < 8; i++)
    {
        for (int j=0; j < 8; j++)
        {
            std::cout << lettered_board[(8 * i) + j] << ' ';
        }
        std::cout << "\n";
    } std::cout << std::endl;
    
}
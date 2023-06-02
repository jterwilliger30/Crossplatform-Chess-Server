#pragma once

#include "player.hpp"
#include "bitboard.hpp"

#include "./pieces/pawn.hpp"
#include "./pieces/bishop.hpp"
#include "./pieces/rook.hpp"
#include "./pieces/king.hpp"
#include "./pieces/queen.hpp"
#include "./pieces/knight.hpp"

class Board {
public:
    Board(Player *const, Player *const, Bitboard *const, Bitboard *const, Bitboard *const);
    ~Board();

    Bitboard *const gamestate;
    Bitboard *const p1_occupied;
    Bitboard *const p2_occupied;

    void update_board_state();
    void reset_board();
    void print_lettered_board();

    void preview_turn(Player *const);
    void take_turn(Player *const, Spot start, Spot end);

//private:
    Player *const player1;
    Player *const player2;

    Pawnboard *const p1_pawn;
    Bishopboard *const p1_bishop;
    Rookboard *const p1_rook;
    Knightboard *const p1_knight;
    Queenboard *const p1_queen;
    Kingboard *const p1_king;

    Pawnboard *const p2_pawn;
    Bishopboard *const p2_bishop;
    Rookboard *const p2_rook;
    Knightboard *const p2_knight;
    Queenboard *const p2_queen;
    Kingboard *const p2_king;
};


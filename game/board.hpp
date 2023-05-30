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
private:
public:
    Player *p1;
    Player *p2;

    Pawnboard p1_pawn;
    Bishopboard p1_bishop;
    Rookboard p1_rook;
    Knightboard p1_knight;
    Queenboard p1_queen;
    Kingboard p1_king;

    Pawnboard p2_pawn;
    Bishopboard p2_bishop;
    Rookboard p2_rook;
    Knightboard p2_knight;
    Queenboard p2_queen;
    Kingboard p2_king;

public:
    Bitboard *gamestate;
    Board(Player*, Player*);
    ~Board();

    void update_board_state();
    void reset_board();
    void print_lettered_board();
};


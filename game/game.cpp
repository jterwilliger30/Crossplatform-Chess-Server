#include "bitboard.hpp"
#include "player.hpp"
#include "spots_enum.hpp"

#include "board.hpp"

#include <iostream>

int main()
{
    Player white_player;
    Player black_player;

    white_player.isWhite = Color::white;
    black_player.isWhite = Color::black;

    white_player.isHuman = player_type::human;
    black_player.isHuman = player_type::human;

    std::cout << sizeof(Bitboard);
    Bitboard GAME_STATE;
    Bitboard P1_OCCUPIED;
    Bitboard P2_OCCUPIED;

    Board *GAMEBOARD = new Board(&white_player, &black_player, &GAME_STATE, &P1_OCCUPIED, &P2_OCCUPIED);

    /*
    GAMEBOARD->p1_pawn->pieceboard.pop_bit(Spot::A2);
    GAMEBOARD->p1_pawn->pieceboard.pop_bit(Spot::C2);
    GAMEBOARD->p1_pawn->pieceboard.set_bit(Spot::C4);
    GAMEBOARD->p1_rook->pieceboard.pop_bit(Spot::A1);
    GAMEBOARD->p1_rook->pieceboard.set_bit(Spot::A4);
    GAMEBOARD->update_board_state();
    
    GAMEBOARD->gamestate->print_board();
    GAMEBOARD->print_lettered_board();
    */

    // White Turn

    // Victory, Stalemate, Check??

    // Black Turn

    // Victory, Stalemate, Check??


    delete GAMEBOARD;
    
}
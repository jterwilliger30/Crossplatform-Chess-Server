#include "bitboard.hpp"
#include "player.hpp"
#include "spots_enum.hpp"

#include "board.hpp"

int main()
{
    Player white_player;
    Player black_player;

    white_player.isWhite = Color::white;
    black_player.isWhite = Color::black;

    white_player.isHuman = player_type::human;
    black_player.isHuman = player_type::human;

    Board GAMEBOARD(&white_player, &black_player);

    // White Turn

    // Victory, Stalemate, Check??

    // Black Turn

    // Victory, Stalemate, Check??


    GAMEBOARD.gamestate->print_board();
}
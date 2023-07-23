#include "bitboard.hpp"
#include "player.hpp"
#include "spots_enum.hpp"

#include "board.hpp"

#include <iostream>

int main()
{
    PlayerSPtr white_player = std::make_shared<Player>();
    PlayerSPtr black_player = std::make_shared<Player>();

    white_player->isWhite = Color::white;
    black_player->isWhite = Color::black;

    white_player->isHuman = player_type::human;
    black_player->isHuman = player_type::human;

    BitboardSPtr GAME_STATE = std::make_shared<Bitboard>();
    BitboardSPtr P1_OCCUPIED = std::make_shared<Bitboard>();
    BitboardSPtr P2_OCCUPIED = std::make_shared<Bitboard>();

    const std::shared_ptr<Board> GAMEBOARD = std::make_shared<Board>(white_player, black_player, GAME_STATE, P1_OCCUPIED, P2_OCCUPIED);

    while (true)
    {
        GAMEBOARD->print_board();
        GAMEBOARD->take_turn(white_player);
        // Handle WIN/STALEMATE/CHECK condition
        GAMEBOARD->print_board();
        GAMEBOARD->take_turn(black_player);
        // Handle WIN/STALEMATE/CHECK condition
    }
}
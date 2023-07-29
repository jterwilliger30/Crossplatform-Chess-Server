#include "game.hpp"

GameEngine::GameEngine(PlayerType p1, PlayerType p2) : 
    white_player(std::make_shared<Player>(Color::white, p1)),
    black_player(std::make_shared<Player>(Color::black, p2)),
    GAME_STATE(std::make_shared<Bitboard>()),
    P1_OCCUPIED(std::make_shared<Bitboard>()),
    P2_OCCUPIED(std::make_shared<Bitboard>())
{
    white_player->opposing_player = black_player;
    black_player->opposing_player = white_player;

    const std::shared_ptr<Board> GAMEBOARD = std::make_shared<Board>(white_player, black_player, GAME_STATE, P1_OCCUPIED, P2_OCCUPIED);
    GAMEBOARD->reset_board();
}

void GameEngine::beginGameLoop()
{
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







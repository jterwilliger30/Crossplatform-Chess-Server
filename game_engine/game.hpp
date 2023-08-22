#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "bitboard.hpp"
#include "player.hpp"
#include "spots_enum.hpp"
#include "piece.hpp"

#include "board.hpp"

#include <iostream>

using PlayerSPtr = const std::shared_ptr<Player>;

class GameEngine
{
public:
    GameEngine(PlayerSPtr p1, PlayerSPtr p2);

    PlayerSPtr white_player;
    PlayerSPtr black_player;
    BitboardSPtr GAME_STATE;
    BitboardSPtr P1_OCCUPIED;
    BitboardSPtr P2_OCCUPIED;
    const std::shared_ptr<Board> GAMEBOARD;

};
#endif

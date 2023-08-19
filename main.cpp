#include "game_engine/game.hpp"
#include "networkinterface.h"

int main(int argc, char *argv[])
{
    // Server begins listing on XYZ port waiting for player
        // When player connects, server asks if want to wait for 2nd player or play AI

        // If AI, server inits stockfish and plugs that into player2
            // Game begins
        // Else if 2nd player, wait for second player
            // 2nd player connects, and game begins
    
    GameEngine engine(PlayerType::human, PlayerType::human);

    NetworkInterface a(true);

    while (true)
    {
        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.white_player);
        // Synchronize game state with clients
        // (BOTH) Handle WIN/STALEMATE/CHECK condition

        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.black_player);
        // Synchronize game state with clients
        // (BOTH) Handle WIN/STALEMATE/CHECK condition
    }
}



    
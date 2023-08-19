#include "game_engine/game.hpp"
#include "networkinterface.h"

int main(int argc, char *argv[])
{
    GameEngine engine(PlayerType::human, PlayerType::human);
    
    NetworkInterface a(true);
    a.load_protobuffer(engine.white_player, engine.black_player);

    while (true)
    {
        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.white_player);
        // Synchronize game state with peer
        // (BOTH) Handle WIN/STALEMATE/CHECK condition

        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.black_player);
        // Synchronize game state with peer
        // (BOTH) Handle WIN/STALEMATE/CHECK condition
    }
}



    
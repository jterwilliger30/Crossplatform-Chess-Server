#include "game_engine/game.hpp"

#include "game_engine/piece.hpp"

#include "networkinterface.h"
#include "PlayerInterface.hpp"

#include <cstdlib>

std::vector<std::string> parseRequest(std::string request)
{
    std::vector<std::string> str_list;

    std::string tmp = "";
    for (char c : request)
    {
        if (c == ',')
        {
            str_list.push_back(tmp);
            tmp = "";
            continue;
        } else if (c == '\n')
        {
            continue;
        }
        else
        {
            tmp += c;
        }
    }
    str_list.push_back(tmp);

    return str_list;
}

void assignColors(PlayerSPtr p1, PlayerSPtr p2)
{
    srand(time(NULL));

    int rand_num = rand() % 2;

    if (rand_num)
    {
        p1->isWhite = Color::white;
        p2->isWhite = Color::black;
    }
    else
    {
        p1->isWhite = Color::black;
        p2->isWhite = Color::white;
    }
}

int main(int argc, char *argv[])
{
    /*  #############  SETUP  #############

        Setup necessary irrespective of player type (human or computer) or client type (GUI, terminal, browser)
    */

    PlayerInterface p1(std::make_shared<Player>());
    PlayerInterface p2(std::make_shared<Player>());

    assignColors(p1.player, p2.player);
    
    // Player 1 is always human
    p1.player->isHuman = PlayerType::human;
    p1.interface = std::make_shared<NetworkInterface>();


    /*  #############  CLIENT HANDSHAKE  #############

        Waits for connection from first player (always human). Upon connection, client will tell
        the server it wants to play and its client type (GUI, terminal, browser). If the player is 
        the first to connect, the server will ask if the client wants to player single or multiplayer.
        Otherwise, server will respond with 'occupied'.
    */

    p1.interface->initSocket(12819);
    p1.interface->waitForResponse();

    std::vector<std::string> p1_msg = parseRequest(p1.interface->readRequest());
    if (p1_msg[0] == "I want to play")
    {
        p1.interface->setMode(std::stoi(p1_msg[1]));  // CHANGE TO SHORT
        // Send message where client will choose b/w playing AI or PvP
        p1.interface->sendResponse("p1 choice");

        p1.interface->waitForResponse();

        std::string request = p1.interface->readRequest();
        if (request[0] == '0')
        {
            // Singleplayer
            std::cout << "[Server] starting game!\n";
            //throw std::exception(); // (Stockfish integration not yet supported)
        }
        else if (request[0] == '1')
        {
            // Wait for second player
            std::cout << "[Server] waiting for second player...\n";
        }
        else
        {
            throw std::exception();
        }
    }

    /*  #############  GAME BEGINS  #############

        The game logic from this point forward should be identical for all gamemodes and client types,
        regardless whether Player vs AI or Player vs Player, or GUI vs terminal, GUI vs browser, etc...
    */

    GameEngine engine(p1.player, p2.player);

    
    while (true)
    {
        p1.interface->sendResponse(engine.GAMEBOARD->print_board());
        auto move = p1.interface->getUserMove(static_cast<bool>(p1.player->isWhite));
        engine.GAMEBOARD->take_turn(p1.player, move);

        // PLEASE NOTE THAT ONLY 1 CLIENT IS POLLED FOR DEBUGGING
        p1.interface->sendResponse(engine.GAMEBOARD->print_board());
        move = p1.interface->getUserMove(static_cast<bool>(p2.player->isWhite));
        engine.GAMEBOARD->take_turn(p2.player, move);




        // Synchronize game state with client(s)
        // (BOTH) Handle WIN/STALEMATE/CHECK condition

        //engine.GAMEBOARD->print_board();
        //engine.GAMEBOARD->take_turn(engine.black_player);
        // Synchronize game state with client(s)
        // (BOTH) Handle WIN/STALEMATE/CHECK condition
    }


}



    
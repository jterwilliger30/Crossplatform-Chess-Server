#include "game_engine/game.hpp"

#include "game_engine/piece.hpp"

#include "networkinterface.h"

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

        tmp += c;
    }
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

class PlayerInterface
{
public:
    PlayerInterface(PlayerSPtr player_) :
        player(player_) 
    {
        interface = nullptr;
    }

    void setInterface(std::shared_ptr<NetworkInterface> ptr_) 
    {
        interface = ptr_;
    }

    PlayerSPtr player;
    std::shared_ptr<NetworkInterface> interface;
};

int main(int argc, char *argv[])
{

    PlayerInterface p1(std::make_shared<Player>());
    PlayerInterface p2(std::make_shared<Player>());

    assignColors(p1.player, p2.player);
    
    

    // Server begins listing on XYZ port waiting for player
        // When player connects, server asks if want to wait for 2nd player or play AI

        // If AI, server inits stockfish and plugs that into player2
            // Game begins
        // Else if 2nd player, wait for second player
            // 2nd player connects, and game begins
    
    p1.player->isHuman = PlayerType::human;
    p1.interface = std::make_shared<NetworkInterface>();

    p1.interface->initSocket(12819);
    p1.interface->waitForResponse();

    std::vector<std::string> p1_msg = parseRequest(p1.interface->readRequest());
    if (p1_msg[0] == "I want to play")
    {
        p1.interface->setMode(std::stoi(p1_msg[1]));  // CHANGE TO SHORT
        // Send message where client will choose b/w playing AI or PvP
        p1.interface->sendResponse("p1 choice");
    }


    //GameEngine engine(, );  // Player 1 and Player 2...
    


    /*
    while (true)
    {
        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.white_player);
        // Synchronize game state with client(s)
        // (BOTH) Handle WIN/STALEMATE/CHECK condition

        engine.GAMEBOARD->print_board();
        engine.GAMEBOARD->take_turn(engine.black_player);
        // Synchronize game state with client(s)
        // (BOTH) Handle WIN/STALEMATE/CHECK condition
    }
    */


}



    
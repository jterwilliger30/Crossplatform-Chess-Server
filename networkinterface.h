#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>

#include "game_engine/piece.hpp"

class NetworkInterface
{
public:
    enum class GameMode : bool {
        Player_vs_Player,
        Single_Player
    };

    NetworkInterface();

private:
    asio::ip::tcp::socket initSocket(unsigned short);

    std::vector<std::unique_ptr<asio::ip::tcp::socket>> m_player_socket_map;
    
};

#endif // NETWORKINTERFACE_H

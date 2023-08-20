#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>
#include <iostream>

#include "game_engine/piece.hpp"

class NetworkInterface
{
public:
    enum class GameMode : bool {
        Player_vs_Player,
        Single_Player
    };

    NetworkInterface();

    void initSocket(unsigned short);
    void waitForResponse();
    std::string readRequest();
    void sendResponse(std::string msg);
private:
   //std::vector<std::unique_ptr<asio::ip::tcp::socket>> m_player_socket_map;

    asio::error_code ec;
    asio::io_context context;
    std::unique_ptr<asio::ip::tcp::endpoint> ep;
    std::unique_ptr<asio::ip::tcp::acceptor> acceptor;
    std::unique_ptr<asio::ip::tcp::socket> sock;
};

#endif // NETWORKINTERFACE_H

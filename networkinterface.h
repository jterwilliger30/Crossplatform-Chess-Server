#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>
#include <iostream>

#include "game_engine/piece.hpp"

class NetworkInterface
{
public:
    enum class ClientMode {
        Terminal,
        Browser,
        QtGUI
    };

    NetworkInterface();
    bool setMode(short);

    void initSocket(unsigned short);
    void waitForResponse();
    std::string readRequest();
    void sendResponse(std::string msg);

    int connected_players; 
private:
   //std::vector<std::unique_ptr<asio::ip::tcp::socket>> m_player_socket_map;

    ClientMode m_playerMode;

    asio::error_code ec;
    asio::io_context context;
    std::unique_ptr<asio::ip::tcp::endpoint> ep;
    std::unique_ptr<asio::ip::tcp::acceptor> acceptor;
    std::unique_ptr<asio::ip::tcp::socket> sock;
};

#endif // NETWORKINTERFACE_H

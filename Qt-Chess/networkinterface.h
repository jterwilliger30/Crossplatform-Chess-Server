#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>

#include "game_engine/player.hpp"

class NetworkInterface
{
public:
    NetworkInterface();

    void sendGameState(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);

private:
    void ClientConnect();
    void ServerListen();

    bool m_isServer; // True if server, false if client
};

#endif // NETWORKINTERFACE_H

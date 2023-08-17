#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>

class NetworkInterface
{
public:
    NetworkInterface();

    void sendGameState();

private:
    void ClientConnect();
    void ServerListen();

    bool m_isServer; // True if server, false if client
};

#endif // NETWORKINTERFACE_H

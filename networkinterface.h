#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>

#include "game_engine/piece.hpp"

class NetworkInterface
{
public:
    NetworkInterface(bool isServer_);

private:
    bool m_isServer; // True if server, false if client
};

#endif // NETWORKINTERFACE_H

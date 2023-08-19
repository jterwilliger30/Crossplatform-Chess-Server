#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>

#include "game_engine/player.hpp"

class NetworkInterface
{
public:
    NetworkInterface(bool isServer_);

    std::unique_ptr<char[]> load_protobuffer(PlayerSPtr p1, PlayerSPtr p2);
    void unload_protobuffer(std::unique_ptr<char[]> data, size_t size, PlayerSPtr p1, PlayerSPtr);

private:
    void ClientConnect();
    void ServerListen();

    std::map<char, uint64_t> extractBitboards(PlayerSPtr);

    bool m_isServer; // True if server, false if client
};

#endif // NETWORKINTERFACE_H

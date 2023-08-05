#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

class NetworkInterface
{
public:
    NetworkInterface();

private:
    void ClientConnect();

};

#endif // NETWORKINTERFACE_H

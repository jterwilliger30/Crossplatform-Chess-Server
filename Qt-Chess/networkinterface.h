#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

class NetworkInterface
{
public:
    NetworkInterface(std::string ip_address, int port);
    void initConnection();
    void sendRequest();

protected:
    void registerEndpoint(std::string& ip_address, int& port);

    asio::io_context context;
    asio::error_code ec;
    asio::ip::tcp::endpoint endpoint;
    asio::ip::tcp::socket socket;

};

class ServerInterface : public NetworkInterface
{
public:
    void beginListening();
    void readConnection();

};

class ClientInterface : public NetworkInterface
{
public:

};

#endif // NETWORKINTERFACE_H

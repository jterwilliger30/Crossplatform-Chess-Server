#include "networkinterface.h"

#include <chrono>

NetworkInterface::NetworkInterface() :
    connected_players(0)
{
    // Begin listening
}

bool NetworkInterface::setMode(short mode)
{
    switch (mode)
    {
        case 0:
            m_playerMode = ClientMode::Terminal;
            break;
        case 1:
            m_playerMode = ClientMode::Browser;
            break;
        case 2:
            m_playerMode = ClientMode::QtGUI;
            break;
        default:
            return false;
    }

    return true;
}

void NetworkInterface::initSocket(unsigned short port_num)
{
    ep = std::make_unique<asio::ip::tcp::endpoint>(asio::ip::tcp::v4(), port_num);
    acceptor = std::make_unique<asio::ip::tcp::acceptor>(context, *ep); 
    sock = std::make_unique<asio::ip::tcp::socket>(context);

    std::cout << "[Server] Waiting for connection" << std::endl;
    acceptor->accept(*sock);
    std::cout << "[Server] Accepted a connection from client" << std::endl;
}

void NetworkInterface::waitForResponse()
{
    if (sock->is_open())
    {
        size_t bytes = 0;
        while (bytes == 0)
        {
            bytes = sock->available();
        }
    }
}

std::string NetworkInterface::readRequest()
{
    std::vector<char> m_buffer(1024);

    if (sock->is_open())
    {
        sock->read_some(asio::buffer(m_buffer.data(), m_buffer.size()));
    }

    std::string request(m_buffer.begin(), m_buffer.end());

    return request;
}

void NetworkInterface::sendResponse(std::string msg)
{
    if (sock->is_open())
    {
        sock->write_some(asio::buffer(msg), ec);
        context.run();
    }
}
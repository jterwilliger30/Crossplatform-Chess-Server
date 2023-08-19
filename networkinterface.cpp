#include "networkinterface.h"

NetworkInterface::NetworkInterface()
{
    // Begin listening
}

bool NetworkInterface::initSocket(unsigned short port_num)
{
    asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);
    asio::io_context context;
    try
    {
        asio::ip::tcp::acceptor acceptor(context, ep.protocol());
        acceptor.bind(ep);
        acceptor.listen();
        asio::ip::tcp::socket sock(context);
        acceptor.accept(sock);
        //thread t(hearbeatSender,sock); 
        //process(sock);
        //t.join();

        //m_player_socket_map.push_back()

        return true;

    } catch (...)
    {
        return false;
    }
}
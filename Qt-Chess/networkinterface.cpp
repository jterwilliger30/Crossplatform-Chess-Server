#include "networkinterface.h"
#include <iostream>

NetworkInterface::NetworkInterface(std::string ip_address, int port) :
        socket(context)
{
    registerEndpoint(ip_address, port);

}

void NetworkInterface::registerEndpoint(std::string& ip_address, int& port)
{
    endpoint = asio::ip::tcp::endpoint(asio::ip::make_address(ip_address, ec), port);
}

void NetworkInterface::initConnection()
{
    socket.connect(endpoint, ec);

    if (!ec)
    {
        std::cout << "Connected" << std::endl;
        // Log successful connection
    }
    else
    {
        std::cout << "Connection failed" << ec.message() << std::endl;
        // Log unsuccessful connection << ec.message()
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

        std::string sRequest =
        "GET /index.html HTTP1.1\r\nHost: pointcutoff.com\r\nConnection: close\r\n\r\n";

        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        socket.wait(socket.wait_read);

        size_t bytes = socket.available();

        std::cout << bytes;
        if (bytes > 0)
        {
            std::vector<char> vBuffer(bytes);
            socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

            for (char c : vBuffer)
                std::cout << c;
        }

}

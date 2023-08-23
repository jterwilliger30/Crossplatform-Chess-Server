#include "networkinterface.h"
#include "spots_enum.hpp"

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

std::pair<char, std::pair<Spot, Spot>> NetworkInterface::getUserMove(bool isWhite)
{
    sendResponse((isWhite ? "White player's turn.\n" : "Black player's turn.\n"));
    std::cout << "Please enter your move in long algebraic notation:\t";
    std::string user_input, str_start, str_end;


    char piece_type;
    std::pair<Spot, Spot> start_end;

    while (true)
    {
        waitForResponse();
        user_input = readRequest();

        static int bc = 0;
        std::cout << user_input << " " << bc << std::endl;

        std::string temp;
        for (char c : user_input)
        {
            if (c == ' ')
                continue;
            temp += c;
        }


        for (char& c : user_input)
        {
            if (isalpha(static_cast<unsigned char>(c)))
                c = toupper(c);
        }
        piece_type = user_input[0];  // Value to be returned!

        str_start = user_input.substr(1, 2);
        str_end = user_input.substr(3, 2);

        try
        {
            if (!(piece_type == 'P' || piece_type == 'B' || piece_type == 'R' || piece_type == 'N' || piece_type == 'Q' || piece_type == 'K'))
            {
                std::cout << "throw";
                throw std::out_of_range("Invalid piece type");
            }
            start_end = {::str_to_spot.at(str_start), ::str_to_spot.at(str_end)}; // Value to be returned!

            std::cout << "True";
            return {piece_type, start_end};
        }
        catch (std::out_of_range)
        {
            std::cout << "\nInvalid... Please re-enter your choice:\t";
            continue;
        }
    }
}
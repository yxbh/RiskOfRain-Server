#include "gui/ServerGuiMainWindow.hpp"

#include <QApplication>

#include <SFML/Network.hpp>

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    ServerGuiMainWindow w;
//    w.show();

    bool waiting_for_connection = true;
    bool running = true;
    bool error = false;
    using SocketUptr = std::unique_ptr<sf::TcpSocket>;
    std::vector<SocketUptr>     sockets;
    sf::SocketSelector          socket_selector;
    sf::TcpListener             listener;
    using SocketStatus = sf::TcpListener::Status;
    listener.setBlocking(false);
    if (listener.listen(11100) != SocketStatus::Done)
    {
        std::cerr << "listener socket failure listening to port." << std::endl;
        error = true;
    }

    while (waiting_for_connection && !error)
    {
        SocketUptr new_socket(new sf::TcpSocket);
        new_socket->setBlocking(false);
        switch (listener.accept(*new_socket))
        {
        case SocketStatus::Done:
        {
            sockets.push_back(std::move(new_socket));
            std::clog << "new connection successful." << std::endl;
            waiting_for_connection = false;

            char hello[] = "GM:Studio-Connect\0";
            if (sockets[sockets.size()-1]->send(hello, strlen(hello+1)*sizeof(char)) != SocketStatus::Done)
            {
                error = false;
                std::cerr << "error saying hello." << std::endl;
            }
        }
            break;

        case SocketStatus::NotReady:
            std::clog << "no new connection." << std::endl;
            break;

        case SocketStatus::Error:
            std::cerr << "connection error." << std::endl;
            error = true;
            break;

        case SocketStatus::Disconnected:
            std::clog << "socket disconnection." << std::endl;
            break;

        default: /* ignore */ break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    std::vector<char> data_buf(100);
    std::size_t data_len;
    while (running && !error)
    {
        switch (sockets[0]->receive(data_buf.data(), data_buf.size(), data_len))
        {
        case SocketStatus::Done:
        {
            std::cout << "Packet data:";
            for (int i = 0; i < data_len; ++i)
            {
                std::cout << data_buf[i];
            }
            std::cout << std::endl;
        }
            break;

        case SocketStatus::Error:
        {
            std::cerr << "error receiving data." << std::endl;
            error = true;
        }
            break;

        default:
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    std::clog << "Exiting..." << std::endl;

//    return a.exec();
    return 0;
}

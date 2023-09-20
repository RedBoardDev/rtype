#pragma once


#include <iostream>
#include "Room.hpp"
#include <vector>
#include "../Reader/Reader.hpp"
#include <mutex>

class Game
{
    private:
        std::vector<Room> _rooms;
        unsigned int _roomIds;
        std::mutex _roomsMutex;

    public:
        Game();
        ~Game();
        void createRoom(Reader::Packet &packet, asio::ip::udp::socket &socket, bool privateRoom = false);
        void searchRoom(Reader::Packet &packet, asio::ip::udp::socket &socket);
};
#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include "Player.hpp"
#include "../Client.hpp"
#include "Monsters/Monster.hpp"

class Room
{
    private:
        bool _started;
        std::thread _thread;
        std::mutex _playersMutex;
        std::vector<std::unique_ptr<Player>> _players;
        std::vector<std::unique_ptr<IMonster>> _monsters;
        unsigned short _id;
        unsigned int _maxPlayer;
        unsigned int _progress;
        u_char _playersIds;
        bool _private;
        void refresh();
        void update();

        size_t _missilesIds;
        u_char _monstersIds;

        Stream _broadcastStream;
        unsigned char _broadcastInst;

        size_t _lastMapRefresh;
        size_t _lastWaitMessage;
        size_t _lastJoin;
        size_t _lastMissileUpdate;
        size_t _lastPlayerUpdate;
        size_t _lastMonsterSpawn;

    public:
        Room(unsigned int id, std::shared_ptr<Client> client, bool privateRoom = false);
        ~Room();
        Room(const Room &room) = delete;
        Room(Room &&room) = delete;
        Room &operator=(const Room &room) = delete;
        Room &operator=(Room &&room) = delete;
        unsigned short getId() const;
        unsigned int getNbPlayer() const;
        unsigned int getProgress() const;
        unsigned int getMaxPlayer() const;
        void addPlayer(std::shared_ptr<Client> client);
        void movePlayer(std::shared_ptr<Client> client, char move, char nbr);
        void removePlayer(std::shared_ptr<Client> client);
        bool isClientInRoom(std::shared_ptr<Client> client);
        Player &getPlayer(std::shared_ptr<Client> client);
        void sendToAll(const Stream &stream);
        void sendBroadcast();
        void startGame();
        Stream &getBroadcastStream();
        void setInstBroadcast(unsigned char inst);
        size_t &getMissilesIds();
        void addMonster(IMonster::Type type, int x, int y);
};
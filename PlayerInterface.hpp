#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include "game_engine/player.hpp"
#include "networkinterface.h"

class PlayerInterface
{
public:
    PlayerInterface(PlayerSPtr player_);

    void setInterface(std::shared_ptr<NetworkInterface> ptr_);

    PlayerSPtr player;
    std::shared_ptr<NetworkInterface> interface;
};
#endif
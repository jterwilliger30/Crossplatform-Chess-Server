#include "PlayerInterface.hpp"

PlayerInterface::PlayerInterface(PlayerSPtr player_) :
    player(player_) 
{
    interface = nullptr;
}

void PlayerInterface::setInterface(std::shared_ptr<NetworkInterface> ptr_) 
{
    interface = ptr_;
}
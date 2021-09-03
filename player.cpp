#include "player.h"

Player::Player(std::string&& name) :
   Person{std::move(name)}
{

}

bool Player::isHitting() const
{
   return false;
}

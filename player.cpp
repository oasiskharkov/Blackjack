#include "player.h"

Player::Player(std::string&& name) :
   Person{std::move(name)}
{

}

bool Player::isHitting() const
{
   std::cout << name() << ", do you want a hit? (Y/N): ";
   char response;
   std::cin >> response;
   return (response == 'y' || response == 'Y');
}

void Player::showPush() const
{
   std::cout << name() << ' ' << " push!" << std::endl;
}

void Player::showBust() const
{
   std::cout << name() << ' ' << " bust!" << std::endl;
}

#include "player.h"
#include <conio.h>

Player::Player(std::string&& name) :
   Person{std::move(name)}
{

}

bool Player::isHitting() const
{
   std::cout << name() << ", if you want to hit press 'y' button or other key to stand: ";
   char response;
   response = _getch();
   return (response == 'y' || response == 'Y');
}

bool Player::exit() const
{
   std::cout << name() << ", if you want to exit, press 'y' button or other key to continue: ";
   char response;
   response = _getch();
   return !(response == 'y' || response == 'Y');
}

void Player::showPush() const
{
   std::cout << name() << ' ' << "push!" << std::endl;
}

void Player::showBust() const
{
   std::cout << name() << ' ' << "bust!" << std::endl;
}

void Player::showBlackjack() const
{
   std::cout << name() << " has Blackjack!" << std::endl;
}
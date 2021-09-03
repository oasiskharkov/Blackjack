#include "person.h"

Person::Person(std::string&& name) :
   m_name{std::move(name)}
{

}

bool Person::isBusted() const
{
   return m_hand.total() > GameParams::blackjack;
}

void Person::showBust() const
{
   std::cout << m_name << ' ' << " bust!" << std::endl;
}

void Person::showWin() const
{
   std::cout << m_name << ' ' << " win!" << std::endl;
}

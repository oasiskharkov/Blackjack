#include "dealer.h"

Dealer::Dealer(std::string&& name) :
   Person{std::move(name)}
{

}

bool Dealer::isHitting() const
{
   return hand().total() < GameParams::dealerLimit;
}

void Dealer::flipFirstCard()
{
   hand().flipCard(0);
}

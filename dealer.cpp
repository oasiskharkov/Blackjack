#include "dealer.h"

Dealer::Dealer(std::string&& name) :
   Person{std::move(name)}
{

}

bool Dealer::isHitting() const
{
   return false;
}

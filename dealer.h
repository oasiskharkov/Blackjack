#pragma once

#include "person.h"

class Dealer final : public Person
{
public:
   explicit Dealer(std::string&& name = "Dealer");
   bool isHitting() const override;
   void flipFirstCard();
};

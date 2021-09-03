#pragma once

#include "person.h"

class Dealer final : public Person
{
public:
   explicit Dealer(std::string&& name = "Dealer");
public:
   bool isHitting() const override;
private:
};

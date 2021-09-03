#pragma once

#include "person.h"

class Player final : public Person
{
public:
   Player(std::string&& name);
public:
   bool isHitting() const override;
private:
};


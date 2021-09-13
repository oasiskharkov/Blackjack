#pragma once

#include "person.h"

class Player final : public Person
{
public:
   Player(std::string&& name);
   bool isHitting() const override;
   void showPush() const;
   void showBust() const;
   void showBlackjack() const;
   bool exit() const;
};
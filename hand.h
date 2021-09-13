#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

#include "card.h"

class Hand
{
public:
   Hand() = default;
   Hand(const Hand&) = delete;
   Hand& operator = (const Hand&) = delete;
public:
   void clear();
   void add(std::unique_ptr<Card> card);
   int total() const;
   bool isBlackjack() const;
   bool empty() const;
   void flipCard(const int index);
   void printCards(std::ostream& out) const;
private:
   Cards m_cards;
};
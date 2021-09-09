#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <unordered_map>

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
   void printAllCards(std::ostream& out) const;
private:
   std::vector<std::unique_ptr<Card>> m_cards;
};
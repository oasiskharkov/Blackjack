#pragma once

#include <vector>
#include <memory>
#include <algorithm>

class Card;

namespace
{
   constexpr int blackjack = 21;
}

class Hand
{
public:
   Hand() = default;
   Hand(const Hand&) = delete;
   Hand& operator = (const Hand&) = delete;

   void clear();
   void add(std::unique_ptr<Card> card);
   int total() const;
   bool isBlackjack() const;
private:
   std::vector<std::unique_ptr<Card>> m_cards;
};
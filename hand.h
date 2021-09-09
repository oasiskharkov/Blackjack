#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "card.h"

namespace GameParams
{
   constexpr int blackjack = 21;
}

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
private:
   std::vector<std::unique_ptr<Card>> m_cards;
};
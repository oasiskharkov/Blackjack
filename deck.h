#pragma once

#include <memory>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#include "card.h"

class Deck
{
public:
   Deck();
   Deck(const Deck&) = delete;
   Deck& operator = (const Deck&) = delete;
public:
   void fill();
   void clear();
   void shuffle();
   bool needToUpdate() const;
   std::unique_ptr<Card> deal();
private:
   Cards m_deck;
   unsigned m_seed;
};


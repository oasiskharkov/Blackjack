#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "game_params.h"

class Card
{
public:
   enum class Suit { SPADES, CLUBS, DIAMONDS, HEARTS };
   enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
public:
   Card(Suit suit, Rank rank, bool isShirtUp = true);
   Card(const Card&) = delete;
   Card& operator = (const Card&) = delete;
public:
   Suit suit() const;
   Rank rank() const;
   bool isShirtUp() const;
   int value() const;
   void flip();
private:
   Suit m_suit;
   Rank m_rank;
   bool m_isShirtUp;
};

std::ostream& operator << (std::ostream& out, const Card& card);
using Cards = std::vector<std::unique_ptr<Card>>;

#pragma once

#include <iostream>

#include "game_params.h"

class Card
{
public:
   enum class Suit { SPADES, CLUBS, DIAMONDS, HEARTS };
   enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
public:
   Card(Suit suit, Rank rank, bool isShirtUp = true);
public:
   Suit suit() const;
   Rank rank() const;
   bool isShirtUp() const;
   int value() const;
   void flip();
   std::string rankSuitToString() const;
private:
   Suit m_suit;
   Rank m_rank;
   bool m_isShirtUp;
};

std::ostream& operator << (std::ostream& out, const Card& card);
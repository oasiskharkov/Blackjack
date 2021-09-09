#pragma once

class Card
{
public:
   enum class Suit { SPADES, CLUBS, DIAMONDS, HEARTS };
   enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
public:
   Card(Suit suit, Rank rank, bool isShirtUp);
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
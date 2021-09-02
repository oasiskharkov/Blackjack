#pragma once

class Card
{
public:
   enum class Suit { SPADES, CLUBS, DIAMONDS, HEARTS };
   enum class Seniority { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
public:
   Card(Suit suit, Seniority seniority, bool isShirtUp);
   Suit suit() const;
   Seniority seniority() const;
   bool isShirtUp() const;
   int value() const;
   void flip();
private:
   Suit m_suit;
   Seniority m_seniority;
   bool m_isShirtUp;
};
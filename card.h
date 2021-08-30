#pragma once

class Card
{
public:
   enum Suit { SPADES, CLUBS, DIAMONDS, HEARTS };
   enum Seniority { ACE = 1, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10 };
public:
   Card(Suit suit, Seniority seniority, bool isShirtUp) :
      m_suit{suit},
      m_seniority{seniority},
      m_isShirtUp{isShirtUp}
   {}
   Suit suit() const;
   Seniority seniority() const;
   bool isShirtUp() const;
   int getValue() const;
   void flip();
private:
   Suit m_suit;
   Seniority m_seniority;
   bool m_isShirtUp;
};

inline Card::Suit Card::suit() const
{
   return m_suit;
}

inline Card::Seniority Card::seniority() const
{
   return m_seniority;
}

inline bool Card::isShirtUp() const
{
   return m_isShirtUp;
}

int Card::getValue() const
{
   return static_cast<int>(m_seniority);
}

inline void Card::flip()
{
   m_isShirtUp = !m_isShirtUp;
}
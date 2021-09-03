#include "card.h"

Card::Card(Suit suit, Rank rank, bool isShirtUp) :
   m_suit{ suit },
   m_rank{ rank },
   m_isShirtUp{ isShirtUp }
{}

Card::Suit Card::suit() const
{
   return m_suit;
}

Card::Rank Card::rank() const
{
   return m_rank;
}

bool Card::isShirtUp() const
{
   return m_isShirtUp;
}

int Card::value() const
{
   return static_cast<int>(m_rank);
}

void Card::flip()
{
   m_isShirtUp = !m_isShirtUp;
}
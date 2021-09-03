#include "card.h"

Card::Card(Suit suit, Seniority seniority, bool isShirtUp) :
   m_suit{ suit },
   m_seniority{ seniority },
   m_isShirtUp{ isShirtUp }
{}

Card::Suit Card::suit() const
{
   return m_suit;
}

Card::Seniority Card::seniority() const
{
   return m_seniority;
}

bool Card::isShirtUp() const
{
   return m_isShirtUp;
}

int Card::value() const
{
   return static_cast<int>(m_seniority);
}

void Card::flip()
{
   m_isShirtUp = !m_isShirtUp;
}
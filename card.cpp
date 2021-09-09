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

std::string Card::rankSuitToString() const
{
   std::string suits[] = { "S", "C", "D", "H" };
   std::string result;
   if (m_rank == Rank::JACK)
   {
      result = "J";
   }
   else if (m_rank == Rank::QUEEN)
   {
      result = "Q";
   }
   else if (m_rank == Rank::KING)
   {
      result = "K";
   }
   else
   {
      const std::string ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
      result = ranks[static_cast<int>(m_rank) - 1];
   }
   result += suits[static_cast<int>(m_suit)];
   return result;
}

std::ostream& operator << (std::ostream& out, const Card& card)
{
   if (card.isShirtUp())
   {
      out << "XX";
   }
   else
   {
      out << card.rankSuitToString();
   }
   return out;
}

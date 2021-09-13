#include "card.h"

Card::Card(Suit suit, Rank rank, bool isShirtUp) :
   m_suit{suit},
   m_rank{rank},
   m_isShirtUp{isShirtUp}
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
   int value = static_cast<int>(m_rank);
   if (m_rank == Rank::JACK)
   {
      value -= 1;
   }
   else if (m_rank == Rank::QUEEN)
   {
      value -= 2;
   }
   else if (m_rank == Rank::KING)
   {
      value -= 3;
   }
   return value;
}

void Card::flip()
{
   m_isShirtUp = !m_isShirtUp;
}

std::ostream& operator << (std::ostream& out, const Card& card)
{
   if (card.isShirtUp())
   {
      out << "XX";
   }
   else
   {
      const std::string suits[] = { "S", "C", "D", "H" };
      const std::string ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
      out << ranks[static_cast<int>(card.rank()) - 1] << suits[static_cast<int>(card.suit())];
   }
   return out;
}

#include "deck.h"

Deck::Deck()
{
   fill();
}

void Deck::fill()
{
   for (int s = static_cast<int>(Card::Suit::SPADES); s <= static_cast<int>(Card::Suit::HEARTS); ++s)
   {
      for (int r = static_cast<int>(Card::Rank::ACE); r <= static_cast<int>(Card::Rank::KING); ++r)
      {
         m_deck.emplace_back(std::make_unique<Card>(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
      }
   }
}

void Deck::clear()
{
   m_deck.clear();
}

void Deck::shuffle()
{
   unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
   std::shuffle(m_deck.begin(), m_deck.end(), std::default_random_engine(seed));
}

bool Deck::needToUpdate() const
{
   return m_deck.size() < GameParams::minCardsCount;
}

std::unique_ptr<Card> Deck::deal()
{
   if (m_deck.empty())
   {
      throw std::logic_error("Deck is empty. Can't deal a card!");
   }
   std::unique_ptr<Card> last = std::move(m_deck.back());
   m_deck.pop_back();
   return last;
}

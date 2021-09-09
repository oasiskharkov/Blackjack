#include "hand.h"
#include "card.h"

void Hand::clear()
{
   m_cards.clear();
}

void Hand::add(std::unique_ptr<Card> card)
{
   m_cards.emplace_back(std::move(card));
}

bool Hand::isBlackjack() const
{
   int sum = total();
   int cardsCount = m_cards.size();
   if (cardsCount == 2 and sum == GameParams::blackjack)
   {     
      Card* first = m_cards[0].get();
      Card* second = m_cards[1].get();
      if ((first->value() == 10 and second->rank() == Card::Rank::ACE) or
         (second->value() == 10 and first->rank() == Card::Rank::ACE))
      {
         return true;
      }
   }
   return false;
}

int Hand::total() const
{
   int sum = 0;
   int aceCount = std::count_if(m_cards.begin(), m_cards.end(), 
      [](const std::unique_ptr<Card>& card) { return card->rank() == Card::Rank::ACE; });
   for (const auto& card : m_cards)
   {
      sum += card->value();
   }

   for (int i = 0; i < aceCount; ++i)
   {
      if (sum <= GameParams::blackjack - 10)
      {
         sum += 10;
      }
   }
   return sum;
}
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
   int cardsCount = m_cards.size();
   if (cardsCount == GameParams::dealCardsCount)
   {     
      Card* first = m_cards[0].get();
      Card* second = m_cards[1].get();
      if ((first->value() == GameParams::pictureCost and second->rank() == Card::Rank::ACE) or
         (second->value() == GameParams::pictureCost and first->rank() == Card::Rank::ACE))
      {
         return true;
      }
   }
   return false;
}

bool Hand::empty() const
{
   return m_cards.empty();
}

void Hand::flipCard(const int index)
{
   if (empty())
   {
      throw std::logic_error("Deck is empty. Can't flip a card!");
   }
   if (index < 0 or (size_t)index >= m_cards.size())
   {
      throw std::logic_error("Incorrect index. Can't flip a card!");
   }
   m_cards.at(index)->flip();
}

void Hand::printCards(std::ostream& out) const
{
   for (const auto& card : m_cards)
   {
      out << *card << ' ';
   }
}

int Hand::total() const
{
   int sum = 0;
   int aceCount = std::count_if(m_cards.begin(), m_cards.end(), 
      [](const std::unique_ptr<Card>& card) { return card->rank() == Card::Rank::ACE && !card->isShirtUp(); });
   for (const auto& card : m_cards)
   {
      sum += (!card->isShirtUp() ? card->value() : 0);
   }

   for (int i = 0; i < aceCount; ++i)
   {
      if (sum <= GameParams::blackjack - GameParams::aceAdd)
      {
         sum += GameParams::aceAdd;
      }
   }
   return sum;
}

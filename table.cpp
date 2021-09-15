#include "table.h"

Table* Table::instance = nullptr;

Table* Table::getInstance(std::string&& name)
{
   if (!instance)
   {
      instance = new Table(std::move(name));
   }
   return instance;
}

Table::Table(std::string&& name) :
   m_player{std::move(name)}
{
   m_deck.shuffle();
}

void Table::update() const
{
   std::system("cls");
   std::cout << m_dealer << std::endl;
   std::cout << m_player << std::endl;
}

void Table::reset()
{
   m_dealer.hand().clear();
   m_player.hand().clear();
   
   if (m_deck.needToUpdate())
   {
      m_deck.clear();
      m_deck.fill();
      m_deck.shuffle();
   }
}

void Table::play()
{
   bool state = true;
   while (state)
   {
      for (int i = 0; i < GameParams::dealCardsCount; ++i)
      {
         auto card1 = m_deck.deal();
         card1->flip(); 
         m_player.hand().add(std::move(card1));
         auto card2 = m_deck.deal();
         card2->flip();
         m_dealer.hand().add(std::move(card2));
      }

      m_dealer.flipFirstCard();
      update();

      if (m_player.hand().isBlackjack())
      {
         m_player.showBlackjack();
         state = m_player.exit();
         reset();
         continue;
      }
      else if (m_dealer.hand().isBlackjack())
      {
         m_dealer.flipFirstCard();
         update();
         m_dealer.showWin();
         state = m_player.exit();
         reset();
         continue;
      }
 
      while(m_player.isHitting())
      {
         auto card = m_deck.deal();
         card->flip();
         m_player.hand().add(std::move(card));
         update();
         if (m_player.isBusted() or m_player.hand().total() == GameParams::blackjack)
         {
            break;
         }
      }

      if (m_player.isBusted())
      {
         m_dealer.flipFirstCard();
         update();
         m_player.showBust();
         state = m_player.exit();
         reset();
         continue;
      }

      m_dealer.flipFirstCard();
      while (m_dealer.isHitting())
      {
         auto card = m_deck.deal();
         card->flip();
         m_dealer.hand().add(std::move(card));
         update();
      }

      if (m_dealer.isBusted())
      {
         m_player.showWin();
         state = m_player.exit();
         reset();
         continue;
      }

      update();
      if (m_dealer.hand().total() > m_player.hand().total())
      {
         m_dealer.showWin();
      }
      else if (m_dealer.hand().total() == m_player.hand().total())
      {
         m_player.showPush();
      }
      else
      {
         m_player.showWin();
      }

      reset();
      state = m_player.exit();
   }
}
#pragma once

#include "dealer.h"
#include "player.h"
#include "deck.h"

class Table
{
public:
   Table(const Table&) = delete;
   Table& operator = (const Table&) = delete;
   static Table* getInstance(std::string&& name);
   void play();
private:
   Table(std::string&& name);
   static Table* instance;
private:
   Dealer m_dealer;
   Player m_player;
   Deck m_deck;
};


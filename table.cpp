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

void Table::play()
{

}

